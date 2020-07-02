#include "server.h"


Server::Server(){
}

Server::~Server() {
    WSACleanup();
}


Server* Server::instance = 0;

/**
 * Retorna la unica instancia del servidor
 * @return Server* - Instancia del servidor
 */
Server* Server::getInstance() {
    if (instance == 0){
        instance = new Server();
    }
    return instance;
}

/**
 * Esta funcion analiza los mensajes recibidos mediante sockets, y los "traduce" para ser utilizados por
 * el servidor.
 * @param message - Mensaje recibido por sockets
 */
void Server::readMessage(std::string message){
    std::string delimiter = "|";
    // UPDATE|PLAYER|X:00,Y:00;HP:00
    if (message.substr(0,message.find(delimiter)) == "UPDATE"){

        message = message.substr(message.find(delimiter)+1,message.size()-1);

        // PLAYER|X:00,Y:00;HP:00
        if (message.substr(0,message.find(delimiter)) == "PLAYER"){

            message = message.substr(message.find(delimiter)+1,message.size()-1);

            // X:00
            std::string x = message.substr(0,message.find(","));

            message = message.substr(message.find(",")+1, message.size()-1);

            // Y:00
            std::string y = message.substr(0,message.find(";"));

            message = message.substr(message.find(";")+1, message.size()-1);

            // HP:00
            std::string hp = message;

            int X = std::stoi(x.substr(x.find(":")+1,x.length()-1));
            int Y = std::stoi(y.substr(y.find(":")+1,y.length()-1));
            int HP = std::stoi(hp.substr(hp.find(":")+1,hp.length()-1));

            // TO-DO
            // Almacenar datos


        } else {
            // TO-DO
            // ENEMY update

        }
    } else if (message.substr(0,message.find(delimiter)) == "REQUEST"){
        std::cout << message << std::endl;
        // TO-DO
        // Manejar peticiones
    }
}

/**
 * Esta funcion *deberia enviar respuestas al cliente despues de procesar alguna peticion
 * recibida
 * @param message - mensaje a enviar por sockets
 */
void Server::sendMessage(char message[]){
    iSendResult = send(ClientSocket, message, iRecvResult, 0);
    if (iSendResult == SOCKET_ERROR){
        closesocket(ClientSocket);
        WSACleanup();
    }
}

/**
 * Inicializa variables utilizadas por el socket
 * @return 0 si todo sale bien, 1 en caso de error
 */
int Server::init(){
    WSADATA wsaData;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0){
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0){
        WSACleanup();
        return 1;
    }

    return 0;

}

/**
 * Inicializa el servidor
 * @return 0 si todo sale bien, 1 en caso de error
 */
int Server::run(){

    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET){
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR){
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR){
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }


    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET){
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }


    do{
        iRecvResult = recv(ClientSocket, recvbuf, 1024, 0);
        if (iRecvResult > 0){


            recvbuf[iRecvResult] = '\0';
            readMessage(recvbuf);
            //printf("%s \n",recvbuf);

            //SendMessage("Message received");
        } else if (iRecvResult == 0){
            printf("Connection closing...\n");
        } else {
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }
    } while (iRecvResult > 0);


    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR){
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    closesocket(ClientSocket);
    WSACleanup();

    return 0;

}