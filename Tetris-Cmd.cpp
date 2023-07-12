// Tetris-Cmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
// developed after installing the MSYS2 collection
// if using OneLoneCoder's example with wchar_t, UNICODE is needed at compile:  g++ -DUNICODE Tetris-Cmd.cpp
#include <iostream>
#include <vector>
#include <Windows.h> // COORD and direct console screen writes
#include <chrono>
#include <thread>

#include "Tetromino.h"

//#define DUNICODE
//unsigned char *pField = nullptr;

// screen and playing field
const int screenWidth = 60;
const int screenHeight = 60;
const int fieldBorderWidth = 12;
const int fieldBorderHeight = 19;


void writeToConsolePosition(short x, short y, char c)
{
    COORD coord{x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << c;
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

    // testing pieces
    Tetromino newPiece;

    // game loop logic
    bool endGame = false;
    short framesBeforeAutoDrop = 20; //20 frames equates to a block drop every second. (20 * 50 = 1000 ms)
    short countedFrames = 0;
    while (!endGame)
    {
        if (countedFrames > framesBeforeAutoDrop)
        {
            newPiece.position.Y++;
            countedFrames = 0;
        }

        newPiece.draw();
        //newPiece.rotate();

        countedFrames++;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // the end
    COORD endCoord{0, 21};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), endCoord);
    std::cout << "\n12345 World!\n";
}