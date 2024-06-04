#include <raylib.h>
#include <iostream>
#include<array>

using namespace std;

void copyArray(int* source, int* destination, int totalSize) {
    for (int i = 0; i < totalSize; ++i) {
            *(destination + i) = *(source + i);
    }
}

array<int,2> coordToGrid(int coordX, int coordY, int sizeX, int sizeY){
    array<int,2> gridCoord;
    gridCoord[1] = (coordX - (coordX % sizeY))/sizeY;
    gridCoord[0] = (coordY - (coordY % sizeX))/sizeX;
    return gridCoord;
}

int main()
{
    Color black = Color{0, 0, 0, 255};
    Color white = Color{255,255,255,255};
    Color gray = Color{10,10,10,255};

    const int screenWidth = 800;
    const int screenHeight = 800;

    const int gridSizeX = 100;
    const int gridSizeY = 100;
    const int gridCellSizeX = screenWidth/gridSizeX;
    const int gridCellSizeY = screenHeight/gridSizeY;

    int grid[gridSizeY][gridSizeY];
    for (int x = 0; x<gridSizeX; x++){
    for (int y = 0; y<gridSizeY; y++){
        grid[y][x] = 0;
    };
    };

    grid[20][20] = 1;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(20000);

    for (int i = 0; i<=50; i++){
        cout << endl;
    }


    while (!WindowShouldClose())
    {
        int fgrid[gridSizeY][gridSizeY];
        copyArray(*grid,*fgrid, gridSizeY*gridSizeX);

        Vector2 mousePos = GetMousePosition();

        if (0 < mousePos.x and mousePos.x < screenWidth and 0 < mousePos.y and mousePos.y < screenHeight and IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            array<int,2> gridPos = coordToGrid(mousePos.x,mousePos.y,gridSizeX,gridSizeY);
            fgrid[gridPos[0]][gridPos[1]] = 1;
        }

        //gravity
        for (int x = 0; x<gridSizeX; x++){
            for (int y = 0; y<gridSizeY; y++){
                if (grid[y][x] == 1 and y+1 < gridSizeY and grid[y+1][x] == 0){
                    fgrid[y][x] = 0;
                    fgrid[y+1][x] = 1;
                }
            }
        }

        BeginDrawing();
        ClearBackground(black);

        //grid ui
        for (int x = 0; x <= screenWidth; x = x+gridCellSizeX){
            DrawLine(x,0,x,screenHeight, gray);
        }
        for (int y = 0; y <= screenHeight; y = y+gridCellSizeY){
            DrawLine(0,y,screenWidth,y, gray);
        }


        copyArray(*fgrid,*grid,gridSizeX*gridSizeY);

        //draw cells
        for (int x = 0; x<gridSizeX; x++){
            for (int y = 0; y<gridSizeY; y++){
                if (grid[y][x] == 1){
                    DrawRectangle(x*gridCellSizeX, y*gridCellSizeY, gridCellSizeX, gridCellSizeY, white);
                    
                }
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}