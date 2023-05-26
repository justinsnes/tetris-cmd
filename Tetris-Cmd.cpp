// Tetris-Cmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
// if using OneLoneCoder's example with wchar_t, UNICODE is needed at compile:  g++ -DUNICODE Tetris-Cmd.cpp
#include <iostream>
#include <vector>
#include <algorithm> // for reversing arrays
#include <Windows.h> // COORD and direct console screen writes

//#define DUNICODE
//unsigned char *pField = nullptr;

const int pieceRows = 4;
const int pieceCols = 4;
int tetrominoLibrary[7][pieceRows][pieceCols];

// screen and playing field
const int screenWidth = 60;
const int screenHeight = 60;
const int fieldBorderWidth = 12;
const int fieldBorderHeight = 19;
const COORD spawnPoint{4, 0};

void writeToConsolePosition(short x, short y, char c)
{
    COORD coord{x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << c;
}

std::vector<std::vector<int>> createPiece(int arr[pieceRows][pieceCols])
{
    std::vector<std::vector<int>> createdPiece(pieceRows, std::vector<int>(pieceCols));

    for (int i = 0; i < pieceRows; ++i) {
        for (int j = 0; j < pieceCols; ++j) {
            createdPiece[i][j] = arr[i][j];
        }
    }

    return createdPiece;
}

std::vector<std::vector<int>> rotatePiece(std::vector<std::vector<int>> piece)
{
    // for a 90 degree clockwise rotation, transpose the 4x4 grid then reverse each row
    std::vector<std::vector<int>> rotatedPiece(pieceRows, std::vector<int>(pieceCols));

    for (int i = 0; i < pieceRows; ++i) {
        for (int j = 0; j < pieceCols; ++j) {
            rotatedPiece[i][j] = piece[j][i];
        }
        std::reverse(rotatedPiece[i].begin(), rotatedPiece[i].end());
    }

    // the below ends up reversing columns rather than rows for our 2d vector setup
    //reverse(begin(rotatedPiece), end(rotatedPiece));

    return rotatedPiece;
}

void drawPiece(std::vector<std::vector<int>> vec) {
    short xPos = spawnPoint.X;
    short yPos = spawnPoint.Y;

    int rowCounter = 0;
    std::vector<std::vector<int>>::const_iterator row;
    std::vector<int>::const_iterator col;
    for (row = vec.begin(); row != vec.end(); ++row) {
        for (col = row->begin(); col != row->end(); ++col) {
            if (*col == 1)
            {
                writeToConsolePosition(xPos, yPos, 'X');
            }
            xPos++;
        }
        yPos++;
        xPos = spawnPoint.X;
    }
}

int main()
{
    // draw playing field
    std::system("cls");
    for (short y = 0; y < fieldBorderHeight; y++)
    {
        for (short x = 0; x < fieldBorderWidth; x++)
        {
            if (x == 0 || x == fieldBorderWidth - 1 || y == fieldBorderHeight - 1)
            {
                writeToConsolePosition(x, y, 'W');
            }
        }
    }

#pragma region OneLoneCoder screen buffer code
    // wchar_t *screen = new wchar_t[screenWidth*screenHeight];
    // for (int i = 0; i < screenWidth*screenHeight; i++) screen[i] = L' ';
    // HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    // SetConsoleActiveScreenBuffer(hConsole);
    // DWORD dwBytesWritten = 0;

    // pField = new unsigned char[fieldWidth*fieldHeight]; // Create play field buffer
	// for (int x = 0; x < fieldWidth; x++) // Board Boundary
	// 	for (int y = 0; y < fieldHeight; y++)
	// 		pField[y*fieldWidth + x] = (x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;

    //     // Draw Field
    // for (int x = 0; x < fieldWidth; x++)
    //     for (int y = 0; y < fieldHeight; y++)
    //         screen[(y + 2)*screenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y*fieldWidth + x]];

    // WriteConsoleOutputCharacter(hConsole, screen, screenWidth*screenHeight, {0,0}, &dwBytesWritten);
#pragma endregion OneLoneCoder End

#pragma region The seven shapes of Tetris
    tetrominoLibrary[0][0][2] = 1; // --X-
    tetrominoLibrary[0][1][2] = 1; // --X-
    tetrominoLibrary[0][2][2] = 1; // --X-
    tetrominoLibrary[0][3][2] = 1; // --X-

    tetrominoLibrary[1][0][2] = 1; // --X-
    tetrominoLibrary[1][1][2] = 1; // --X-
    tetrominoLibrary[1][2][2] = 1; // -XX-
    tetrominoLibrary[1][2][1] = 1; // ----
#pragma endregion The seven shapes of Tetris

    // testing pieces
    srand(time(NULL));
    std::vector<std::vector<int>> activePiece = createPiece(tetrominoLibrary[rand() % 2]);
    drawPiece(activePiece);

    // activePiece = rotatePiece(activePiece);
    // std::cout << generateAsciiBlock(activePiece) << " End\n";

    // activePiece = rotatePiece(activePiece);
    // std::cout << generateAsciiBlock(activePiece) << " End\n";

    // the end
    COORD endCoord{0, 21};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), endCoord);
    std::cout << "\n12345 World!\n";
}