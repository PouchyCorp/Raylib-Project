#include <raylib.h>
#include "ball.h"
#include <iostream>

using namespace std;

int main()
{
    Color black = Color{0, 0, 0, 255};
    //Color white = Color{255,255,255,255};
    Color gray = Color{10,10,10,255};

    const int screenWidth = 800;
    const int screenHeight = 800;

    const int gridSizeX = 50;
    const int gridSizeY = 50;
    const int gridCellSizeX = screenWidth/gridSizeX;
    const int gridCellSizeY = screenHeight/gridSizeY;

    int grid[50][50];
    for (int x = 0; x<=gridSizeX; x++){
    for (int y = 0; y<=gridSizeY; y++){
        grid[y][x] = 0;
    };
    };

    Ball ball = Ball();

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    for (int i = 0; i<=50; i++){
        cout << endl;
    }
    
    cout << grid << endl;


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(black);
        ball.Update();
        ball.Draw();

        //grid ui
        for (int x = 0; x <= screenWidth; x = x+gridCellSizeX){
            DrawLine(x,0,x,screenHeight, gray);
        };
        for (int y = 0; y <= screenHeight; y = y+gridCellSizeY){
            DrawLine(0,y,screenWidth,y, gray);
        };

        EndDrawing();
    }

    CloseWindow();
    return 0;
}