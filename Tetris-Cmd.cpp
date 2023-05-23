// Tetris-Cmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <algorithm>
//#include <curses.h>

const int ROWS = 4;
const int COLUMNS = 4;

// grids, rows, columns
int tetrominoLibrary[7][ROWS][COLUMNS];
int fieldWidth = 10;
int fieldHeight = 20;

std::vector<std::vector<int>> createPiece(int arr[ROWS][COLUMNS])
{
    std::vector<std::vector<int>> createdPiece(ROWS, std::vector<int>(COLUMNS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            createdPiece[i][j] = arr[i][j];
        }
    }

    return createdPiece;
}

std::vector<std::vector<int>> rotatePiece(std::vector<std::vector<int>> piece)
{
    // for a 90 degree clockwise rotation, transpose the 4x4 grid then reverse each row
    std::vector<std::vector<int>> rotatedPiece(ROWS, std::vector<int>(COLUMNS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            rotatedPiece[i][j] = piece[j][i];
        }
        std::reverse(rotatedPiece[i].begin(), rotatedPiece[i].end());
    }

    // the below ends up reversing columns rather than rows for our 2d vector setup
    //reverse(begin(rotatedPiece), end(rotatedPiece));

    return rotatedPiece;
}

std::string generateAsciiBlock(std::vector<std::vector<int>> vec) {
    std::string asciiBlock = "";

    int rowCounter = 0;
    std::vector<std::vector<int>>::const_iterator row;
    std::vector<int>::const_iterator col;
    for (row = vec.begin(); row != vec.end(); ++row) {
        for (col = row->begin(); col != row->end(); ++col) {
            if (*col == 1)
                asciiBlock += "X";
            else
                asciiBlock += " ";
        }
        if (rowCounter < ROWS - 1)
            asciiBlock += "\n";
        rowCounter += 1;
    }

    return asciiBlock;
}

int main()
{
    std::cout << "12345 World!\n";

    //initscr();

#pragma region
    tetrominoLibrary[0][0][2] = 1; // --X-
    tetrominoLibrary[0][1][2] = 1; // --X-
    tetrominoLibrary[0][2][2] = 1; // --X-
    tetrominoLibrary[0][3][2] = 1; // --X-

    tetrominoLibrary[1][0][2] = 1; // --X-
    tetrominoLibrary[1][1][2] = 1; // --X-
    tetrominoLibrary[1][2][2] = 1; // -XX-
    tetrominoLibrary[1][2][1] = 1; // ----
#pragma endregion The seven shapes of Tetris

    std::vector<std::vector<int>> activePiece = createPiece(tetrominoLibrary[1]);
    std::cout << generateAsciiBlock(activePiece) << " End\n";

    activePiece = rotatePiece(activePiece);
    std::cout << generateAsciiBlock(activePiece) << " End\n";

    activePiece = rotatePiece(activePiece);
    std::cout << generateAsciiBlock(activePiece) << " End\n";

    activePiece = createPiece(tetrominoLibrary[0]);
    std::cout << generateAsciiBlock(activePiece) << " End\n";

    activePiece = rotatePiece(activePiece);
    std::cout << generateAsciiBlock(activePiece) << " End\n";

    activePiece = rotatePiece(activePiece);
    std::cout << generateAsciiBlock(activePiece) << " End\n";
}