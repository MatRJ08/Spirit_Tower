#include "server.h"
#include <sstream>
#include "Game.h"
float Datos[3];
bool b=false;
bool p =true;
int PISO;
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
    if(b){
        for (int j = 0; j <3 ; ++j) {
            switch (PISO) {
                case 0:
                    Datos[0] = G->generar_gen()[j].get_vel_ruta();
                    sendMessage("DAT|V_RUTA|"+ std::to_string(j) + "|" + std::to_string(Datos[0]));

                    Datos[1] = G->generar_gen()[j].get_vel_persecucion();
                    sendMessage("DAT|V_PER|"+ std::to_string(j) + "|" + std::to_string(Datos[1]));

                    Datos[2] = G->generar_gen()[j].get_vision();
                    sendMessage("DAT|RADIO|"+ std::to_string(j) + "|" + std::to_string(Datos[2]));

                    break;
                case 1:
                    Datos[0] = G->generar_gen2()[j].get_vel_ruta();
                    sendMessage("DAT|V_RUTA|"+ std::to_string(j) + "|" + std::to_string(Datos[0]));

                    Datos[1] = G->generar_gen2()[j].get_vel_persecucion();
                    sendMessage("DAT|V_PER|"+ std::to_string(j) + "|" + std::to_string(Datos[1]));

                    Datos[2] = G->generar_gen2()[j].get_vision();
                    sendMessage("DAT|RADIO|"+ std::to_string(j) + "|" + std::to_string(Datos[2]));

                    break;
                case 2:
                    Datos[0] = G->generar_gen3()[j].get_vel_ruta();
                    sendMessage("DAT|V_RUTA|"+ std::to_string(j) + "|" + std::to_string(Datos[0]));

                    Datos[1] = G->generar_gen3()[j].get_vel_persecucion();
                    sendMessage("DAT|V_PER|"+ std::to_string(j) + "|" + std::to_string(Datos[1]));

                    Datos[2] = G->generar_gen3()[j].get_vision();
                    sendMessage("DAT|RADIO|"+ std::to_string(j) + "|" + std::to_string(Datos[2]));

                    break;
                case 3:
                    Datos[0] = G->generar_gen3()->get_vel_ruta();
                    sendMessage("DAT|V_RUTA|"+ std::to_string(j) + "|" + std::to_string(Datos[0]));

                    Datos[1] = G->generar_gen3()->get_vel_persecucion();
                    sendMessage("DAT|V_PER|"+ std::to_string(j) + "|" + std::to_string(Datos[1]));

                    Datos[2] = G->generar_gen3()->get_vision();
                    sendMessage("DAT|RADIO|"+ std::to_string(j) + "|" + std::to_string(Datos[2]));

                    break;
            }
        }
        b=false;
    }
    std::string delimiter = "|";
    // UPDATE|PLAYER|X:00,Y:00;HP:00
    if(p) {
        if (message.substr(0, message.find(delimiter)) == "PISO") {
            message = message.substr(message.find(delimiter) + 1, message.size() - 1);
            PISO = std::stoi(message);
            p=false;
            b=true;
        }

    }
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

            std::cout << "Player = " << "X: " << X << " - Y: " << Y << " - HP: " << HP << std::endl;
            // TO-DO
            // Almacenar datos


        } else  if (message.substr(0,message.find(delimiter)) == "ENEMY" ){
            message = message.substr(message.find(delimiter)+1,message.length()-1);

                std::string NAME = message.substr(0, message.find(delimiter));

                message = message.substr(message.find(delimiter) + 1, message.size() - 1);

                // X:00
                std::string x = message.substr(0, message.find(","));

                message = message.substr(message.find(",") + 1, message.size() - 1);

                // Y:00
                std::string y = message;


                int X = std::stoi(x.substr(x.find(":") + 1, x.length() - 1));
                int Y = std::stoi(y.substr(y.find(":") + 1, y.length() - 1));



                std::cout << "Enemy name: " << NAME << " - X:" << X << " - Y:" << Y << std::endl;


                // TO-DO
                // Almacenar datos


        }
    } else if (message.substr(0,message.find(delimiter)) == "REQUEST"){
        message = message.substr(message.find(delimiter)+1,message.size()-1);

        if (message.substr(0,message.find(delimiter)) == "PLAYER"){
            message = message.substr(message.find(delimiter)+1,message.size()-1);

            int damageReceived = std::stoi(message.substr(message.find(":")+1));

            std::cout << "Player should take " << damageReceived << " damage. BANZAI" << std::endl;
            // TO-DO
            // * Realizar accion sobre jugador

            // * Enviar resultado
            std::string dR = std::to_string(damageReceived);
            std::string newMessage = "PLAYER|rHEALTH|"+dR;

            sendMessage(newMessage);

        } else if (message.substr(0,message.find(delimiter)) == "ENEMY"){
            message = message.substr(message.find(delimiter)+1,message.size()-1);

            // TO-DO
            // * Verificar tipo de peticion (Jugador ubicado, vida, etc...)
            // * Realizar accion sobre enemigo
            // * Enviar resultado
        }

    }
}

/**
 * Esta funcion *deberia enviar respuestas al cliente despues de procesar alguna peticion
 * recibida
 * @param message - mensaje a enviar por sockets
 */
void Server::sendMessage(std::string message) {

    iSendResult = send(ClientSocket, message.c_str(), message.length(), 0);
    if (iSendResult == SOCKET_ERROR) {
        closesocket(ClientSocket);
        WSACleanup();
    }
}

/**
 * Esta funcion lee los datos recibidos del cliente y separa los mensajes en el caso
 * de que estos lleguen varios a la vez
 * @param buffer
 */
void Server::readBuffer(std::string buffer) {
    std::string delimiter = "~";
    if (buffer.find(delimiter) == buffer.size()-1){
        readMessage(buffer.substr(0, buffer.find(delimiter)));
    } else {
        readMessage(buffer.substr(0, buffer.find(delimiter)));
        buffer = buffer.substr(buffer.find(delimiter)+1);
        readBuffer(buffer);
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


            readBuffer(recvbuf);
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