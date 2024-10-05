#include "grid.h"
#include <raylib.h>
#include <vector>

Grid::Grid(int sizeX, int sizeY, std::vector<int> filling) : sizeX(sizeX), sizeY(sizeY), filling(filling)
{
    grid.resize(sizeY, std::vector<std::vector<std::vector<int>>>(sizeX, filling));
}

void Grid::getPos(int x, int y)
{
    return;
}

void Grid::setPos(int x, int y)
{
    return;
}