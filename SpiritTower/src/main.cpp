#include "server.h"


int main(){
    Server* s = Server::getInstance();

    s->init();
    s->run();

    return 0;
}