#include <raylib.h>
#include "ball.h"
#include <iostream>

using namespace std;

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    int grid[50][50];
    for (int x = 0; x<=50; x++){
    for (int y = 0; y<=50; y++){
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
        ClearBackground(darkGreen);
        ball.Update();
        ball.Draw();
        //for (int i = 0; i <= GetScreenWidth(); i = i+GetScreenWidth()/50){
        
        //};
        EndDrawing();
    }

    CloseWindow();
    return 0;
}