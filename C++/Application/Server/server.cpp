#include "server.hpp"

    SNZ_Server::SNZ_Server() : running(false) {
      SimpleTcpStartPoint::Options options;
      options.connectionPort = 3000;
      options.maximumConnectedClients = 1;
      socketServer = new SimpleTcpStartPoint( options );
    }

    SNZ_Server::~SNZ_Server() {
      if(this->isRunning()) {
        this->stopServer();
      }
      delete(socketServer);
    }

    void SNZ_Server::start() {
      if(this->isRunning()) {
        std::cerr << "serveur is already running , abort \n";
        return;
      }
      if(!this->socketServer->start()) {
        std::cerr << "impossible to start socketserver \n";
        return;
      }

      this->running = true;
      std::thread main_thread(serveur_listening_routine, this);
      main_thread.detach();
    }

    bool SNZ_Server::isRunning() const {
      return this->running;
    }

    void SNZ_Server::stopServer() {
      if(this->isRunning()) {
        this->socketServer->stop();
      }
      this->running = false;
    }

    void SNZ_Server::acceptClient(QUuid client) {
      unsigned char test[17] = "tuveuxvoirmabite";
      ByteBuffer Btest(test, 17);
      this->socketServer->send(client,Btest); std::cout << "Sent : " << "Hello" << " bytes" << std::endl;
    }


void serveur_listening_routine(SNZ_Server *server) {
  QUuid fake, client;
  while(server->isRunning()) {
    client = server->socketServer->listen();
    if(client != fake) {
      server->acceptClient(client);
    }
  }
}
