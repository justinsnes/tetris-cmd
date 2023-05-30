#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <array>
#include <windows.h>

class Tetromino
{
public:
    Tetromino();
    COORD position;
    std::vector<std::vector<char>> shape;

    std::vector<COORD> lastDrawnPoints;

    static std::vector<std::vector<char>> ShapeLibrary[7];

    void rotate();
    void draw();
};

#endif