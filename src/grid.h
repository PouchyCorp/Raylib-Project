#pragma once
#include <vector>

class Grid
{
public:
    Grid(int sizeX, int sizeY, std::vector<int> filling);
    void getPos(int x, int y);
    void setPos(int x, int y);

private:
    std::vector<std::vector<int>> grid; 
    int sizeX;
    int sizeY;
};