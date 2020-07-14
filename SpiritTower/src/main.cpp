#include "server.h"
//#include "LinkedList.cpp"

int main(){
    //listTest();
    Server* s = Server::getInstance();

    s->init();
    s->run();


    return 0;
}