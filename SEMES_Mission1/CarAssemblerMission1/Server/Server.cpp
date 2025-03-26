#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include <exception>

#pragma comment(lib, "ws2_32.lib")

using std::cout;
using std::endl;

class TCPServer {
public:
    TCPServer(const std::string& ipAddress = "0.0.0.0", int port = 54000)
        : serverSocket(INVALID_SOCKET), clientSocket(INVALID_SOCKET), ipAddress(ipAddress), port(port) {
    }

    ~TCPServer() {
        cleanup();
    }

    void start() {
        initialize();
        createServerSocket();
        bindServerSocket();
        waitForConnection();
        handleClientCommunication();
    }

    int* get_cmd() {
        return cmd;
    }

private:
    SOCKET serverSocket;
    SOCKET clientSocket;
    std::string ipAddress;
    int port;
    char buffer[10];
    int cmd[5];

    void initialize() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("socket : initialize error - WSAStartup failed!\n");
        }
    }

    void createServerSocket() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == INVALID_SOCKET) {
            throw std::runtime_error("socket : create socket error - Socket creation failed!\n");
        }
    }

    void bindServerSocket() {
        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(54000);

        if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            throw std::runtime_error("socket : binding error - Bind failed!\n");
        }
    }

    void waitForConnection() {
        listen(serverSocket, SOMAXCONN);
        cout << "Waiting for a connection..." << endl;

        sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);

        clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrSize);
        if (clientSocket == INVALID_SOCKET) {
            throw std::runtime_error("socket : connection error - Client connection failed!\n");
        }

        //cout << "Client connected!" << endl;
    }

    void handleReceivedData(const char* data) {
        std::istringstream stream(data);
        std::string token;

        int idx = 0;
        while (std::getline(stream, token, ':')) {
            cmd[idx++] = stoi(token);
        }

        if (cmd[0] == 1) {
            //test
        }
        else if (cmd[0] == 2) {
            if (cmd[2] == 4) {
                char result[] = "Engine is not working.\nThe car doesn't move.\n";
                send(clientSocket, result, sizeof(result), 0);
            }
            else {
                char result[] = "The car is moving.\n";
                send(clientSocket, result, sizeof(result), 0);
            }
        }
    }

    void handleClientCommunication() {
        while (true) {
            int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesReceived > 0) {
                buffer[bytesReceived] = '\0';
                cout << "Received: " << buffer << endl;

                handleReceivedData(buffer);

                if (strcmp(buffer, "-1") == 0) {
                    throw std::runtime_error("Client terminated\n");
                }
            }
            else if (bytesReceived == 0) {
                throw std::runtime_error("Client disconnected\n");
            }
            else {
                throw std::runtime_error("Error receiving data!\n");
            }
        }
    }
    void cleanup() {
        if (clientSocket != INVALID_SOCKET) {
            closesocket(clientSocket);
        }
        if (serverSocket != INVALID_SOCKET) {
            closesocket(serverSocket);
        }
        WSACleanup();
    }
};
