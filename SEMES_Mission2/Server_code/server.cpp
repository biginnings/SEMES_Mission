#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using std::cout;
using std::endl;

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    sockaddr_in serverAddr, clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    char buffer[10];

    // WSAStartup 초기화
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed!" << endl;
        return 1;
    }

    // 서버 소켓 생성
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed!" << endl;
        return 1;
    }

    // 서버 주소 설정
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(54000);

    // 바인딩
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Bind failed!" << endl;
        return 1;
    }

    // 클라이언트 연결 대기
    listen(serverSocket, SOMAXCONN);
    cout << "Waiting for a connection..." << endl;

    // 클라이언트 연결 수락
    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Client connection failed!" << endl;
        return 1;
    }

    cout << "Client connected!" << endl;

    // 메시지 수신 및 응답
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';  // Null-terminate the received data
            cout << "Received: " << buffer << endl;

            char* strcpy = buffer;
            char* idx = strtok_s(strcpy, ":", &strcpy);
            while (idx != nullptr) {
                cout << idx << " ";
                idx = strtok_s(nullptr, ":", &strcpy);
            }

            ////exception check
            //const char* response = "//";
            //send(clientSocket, response, strlen(response), 0);

            if (strcmp(buffer, "-1") == 0) {
                //exit
                cout << "client terminated" << endl;
            }
        }
    }

    // 소켓 닫기
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
