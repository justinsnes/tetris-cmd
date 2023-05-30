#include <iostream>
#include <algorithm> // for reversing arrays
#include <chrono>
#include "Tetromino.h"

const COORD spawnPoint{4, 0};
const int pieceRows = 4;
const int pieceCols = 4;

std::vector<std::vector<char>> Tetromino::ShapeLibrary[7] = {
    {
        {' ', 'I', ' ', ' '}, 
        {' ', 'I', ' ', ' '}, 
        {' ', 'I', ' ', ' '}, 
        {' ', 'I', ' ', ' '}
    },
    {
        {' ', ' ', ' ', ' '},
        {' ', 'O', 'O', ' '},
        {' ', 'O', 'O', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {' ', ' ', ' ', ' '},
        {'T', 'T', 'T', ' '},
        {' ', 'T', ' ', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {' ', ' ', 'J', ' '},
        {' ', ' ', 'J', ' '},
        {' ', 'J', 'J', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {' ', 'L', ' ', ' '},
        {' ', 'L', ' ', ' '},
        {' ', 'L', 'L', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {' ', ' ', ' ', ' '},
        {' ', 'S', 'S', ' '},
        {'S', 'S', ' ', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {' ', ' ', ' ', ' '},
        {'Z', 'Z', ' ', ' '},
        {' ', 'Z', 'Z', ' '},
        {' ', ' ', ' ', ' '}
    }
};

Tetromino::Tetromino()
{
    srand(time(NULL));

    this->shape = Tetromino::ShapeLibrary[rand() % 4];
    this->position = spawnPoint;
}

void Tetromino::rotate()
{
    // for a 90 degree clockwise rotation, transpose the 4x4 grid then reverse each row
    std::vector<std::vector<char>> rotatedPiece(pieceRows, std::vector<char>(pieceCols));

    for (int i = 0; i < pieceRows; ++i) {
        for (int j = 0; j < pieceCols; ++j) {
            rotatedPiece[i][j] = this->shape[j][i];
        }
        std::reverse(rotatedPiece[i].begin(), rotatedPiece[i].end());
    }

    // the below ends up reversing columns rather than rows for our 2d vector setup
    //reverse(begin(rotatedPiece), end(rotatedPiece));

    this->shape = rotatedPiece;
}

void Tetromino::draw()
{
    if (this->lastDrawnPoints.size() > 0)
    {
        for (COORD x : lastDrawnPoints)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), x);
            std::cout << ' ';
        }
    }

    short xPos = this->position.X;
    short yPos = this->position.Y;
    
    std::vector<std::vector<char>>::const_iterator row;
    std::vector<char>::const_iterator col;
    for (row = this->shape.begin(); row != this->shape.end(); ++row) {
        for (col = row->begin(); col != row->end(); ++col) {
            if (*col != ' ')
            {
                COORD piecePixel{ xPos, yPos };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), piecePixel);
                std::cout << *col;
                this->lastDrawnPoints.push_back(piecePixel);
            }
            xPos++;
        }
        yPos++;
        xPos = this->position.X;
    }

}