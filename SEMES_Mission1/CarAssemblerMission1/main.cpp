#include <iostream>
#include "include.h"
#include "CarAssembler/CarAssembler.h"
#include <thread>

void GUI() {
    TCPServer server;
    while (1) {
        try {
            server.start();
        }
        catch (std::runtime_error e) {
            server.~TCPServer();
            cout << e.what();
        }
    }
}

int main() {

    std::thread t(GUI);
    CarAssembler::getInstance()->start();

    t.join();

	return 0;
}