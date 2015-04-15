#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include "TcpNetworking/simpletcpstartpoint.hpp"
#include <vector>

class SNZ_Server {

public:
    SNZ_Server();

    SNZ_Server(const SNZ_Server&) {
      std::cout << "kikoo \n";
    };

    ~SNZ_Server();

    void start();

    bool isRunning() const ;

    void stopServer();

private :

    bool running;

    SimpleTcpStartPoint *socketServer;

    void acceptClient(QUuid client);

    friend void serveur_listening_routine(SNZ_Server *server);

};

void serveur_listening_routine(SNZ_Server *server);


#endif // SERVER_HPP
