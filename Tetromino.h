#include <vector>
#include <array>
#include <windows.h>

class Tetromino
{
public:
    Tetromino();
    COORD position;
    std::vector<std::vector<char>> shape;

    COORD lastDrawnPosition;
    std::vector<std::vector<char>> lastDrawnShape;

    static std::vector<std::vector<char>> ShapeLibrary[7];

    void rotate();
};