#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"
#include "Server/server.hpp"
#include <chrono>
#include <thread>

int main ( int argc, char** argv ) {
    SNZ_Server s;
    s.start();
    while(s.isRunning()) {
    }
    return 0;
}
