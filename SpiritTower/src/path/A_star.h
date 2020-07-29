//
// Created by ashley on 24/10/19.
//

#ifndef SPIRIT_TOWER_A_STAR_H
#define SPIRIT_TOWER_A_STAR_H

// Bibliotecas
#include <iostream>
#include <vector>
#include <string>
#include "lista.h"
#define ROW 10
#define COL 10

using namespace std;

struct cell
{
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};


class A_star{

public:

    Lista *strpath = new Lista;
    typedef pair<int, int> Pair;
    typedef pair<double, pair<int, int>> pPair;

    //! @brief Constructor
    A_star();
    //! @brief getter del path
    //! \return
    Lista * get_path();
    //! @brief Valida si la celda es valida
    //! \param row numero de fila
    //! \param col numero de columna
    //! \return
    bool isValid(int row, int col);
    //! @brief Valida si la celda está ocupada
    //! \param grid la matriz
    //! \param row numero de fila
    //! \param col numero de columna
    //! \return
    bool isUnBlocked(int grid[][COL], int row, int col);
    //! @brief Valida si es la celda de destino
    //! \param row numero de fila
    //! \param col numero de columna
    //! \param dest celda de destino
    //! \return
    bool isDestination(int row, int col, Pair dest);
    //! @brief Calcula el valor del H
    //! \param row numero de fila
    //! \param col numero de columna
    //! \param dest celda de destino
    //! \return
    double calculateHValue(int row, int col, Pair dest);
    //! @brief Traza la ruta
    //! \param cellDetails
    //! \param dest celda de destino
    void tracePath(cell cellDetails[][COL], Pair dest);
    //! @brief Realiza todo el proceso de búsqueda de la ruta
    //! \param grid matriz
    //! \param src celda de inicio
    //! \param dest celda de destino
    void aStarSearch(int grid[][COL], Pair src, Pair dest);

};

#endif //SPIRIT_TOWER_A_STAR_H