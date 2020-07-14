#include <iostream>
#include "Backtracking.h"
#include "A_star.h"


using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;


int backtracking_test(){
    int (*maze)[10] = (int(*)[10]) calloc(10,sizeof(*maze));
    maze[2][4]=1;
    maze[2][5]=1;
    auto solver = new Backtracking();
    solver->Backtracking_Search(maze,0,4);
    solver->print_maze(maze);

}


int A_star_test(){

    // Declarar un laberinto
    int (*maze)[10] = (int(*)[10]) calloc(10,sizeof(*maze));
    maze[2][4]=1;
    maze[2][5]=1;

    // Ejecutar el algoritmo A*
    A_star* solver = new A_star();
    Pair src = make_pair(0, 3);
    Pair dest = make_pair(9, 4);
    solver->aStarSearch(maze, src, dest);
    return 0;
}


int main(int argc, char *argv[]){

    backtracking_test();
    A_star_test();

    return 0;
}
