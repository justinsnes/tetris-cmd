// Tetris-Cmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

// grids, rows, columns
int tetrominoLibrary[7][ROWS][COLS];
int fieldWidth = 10;
int fieldHeight = 20;

vector<vector<int>> createPiece(int arr[ROWS][COLS])
{
    vector<vector<int>> createdPiece(ROWS, vector<int>(COLS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            createdPiece[i][j] = arr[i][j];
        }
    }

    return createdPiece;
}

vector<vector<int>> rotatePiece(vector<vector<int>> piece)
{
    // for a 90 degree rotation, transpose the 4x4 grid then reverse each row
    vector<vector<int>> rotatedPiece(ROWS, vector<int>(COLS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            rotatedPiece[i][j] = piece[j][i];
        }
        reverse(rotatedPiece[i].begin(), rotatedPiece[i].end());
    }

    // the below ends up reversing columns rather than rows for our 2d vector setup
    //reverse(begin(rotatedPiece), end(rotatedPiece));

    return rotatedPiece;
}

string generateAsciiBlock(vector<vector<int>> vec) {
    string asciiBlock = "";

    int rowCounter = 0;
    vector<vector<int>>::const_iterator row;
    vector<int>::const_iterator col;
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

    vector<vector<int>> activePiece = createPiece(tetrominoLibrary[1]);
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