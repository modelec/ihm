#include <atomic>
#include <csignal>

#include "TCPServer.hpp"

std::atomic<bool> keepRunning(true);

void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    keepRunning = false;
}

int main() {
    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    TCPServer server(8080);

    try {
        server.start();

        while (keepRunning) {
            sleep(1);

            server.broadcastMessage("request aruco");

            std::cout << "Main thread communicating with server..." << std::endl;
        }

        server.stop();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}