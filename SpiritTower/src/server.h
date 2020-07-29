#ifndef SPIRITTOWER_SERVER_H
#define SPIRITTOWER_SERVER_H

#include <WS2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "Game.h"
#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"

/**
 * Corresponde a la clase del servidor
 */
class Server{

public:
    Game *G=new Game();
    static Server* getInstance();
    int init();
    int run();
    void readMessage(std::string message);
    void sendMessage(std::string message);
    void readBuffer(std::string buffer);
    void sendStats(int piso);

private:
    static Server* instance;
    SOCKET ListenSocket = INVALID_SOCKET, ClientSocket = INVALID_SOCKET;
    char recvbuf[1024];
    int iResult, iRecvResult, iSendResult;
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    Server();
    ~Server();

};


#endif //SPIRITTOWER_SERVER_H
