#include <raylib.h>
#include <iostream>
#include <array>
#include <grid.h>
#include <algorithm> // For std::copy

using namespace std;

void copyArray(int *source, int *destination, int totalSize)
{
    std::copy(source, source + totalSize, destination);
}

array<int, 2> coordToGrid(int coordX, int coordY, int sizeX, int sizeY)
{
    array<int, 2> gridCoord;
    gridCoord[1] = coordX / (GetScreenWidth() / sizeX);
    gridCoord[0] = coordY / (GetScreenHeight() / sizeY);
    return gridCoord;
}

int main()
{
    Color black = Color{0, 0, 0, 255};
    Color white = Color{255, 255, 255, 255};
    //Color gray = Color{10, 10, 10, 255};

    const int screenWidth = 900;
    const int screenHeight = 900;

    Grid myGrid(3,3,0);
    

    srand(time(NULL));

    const int gridSizeX = 300;
    const int gridSizeY = 300;
    const int gridCellSizeX = screenWidth / gridSizeX;
    const int gridCellSizeY = screenHeight / gridSizeY;

    int *grid = new int[gridSizeX * gridSizeY]();
    int *fgrid = new int[gridSizeX * gridSizeY]();

    grid[20 * gridSizeX + 20] = 1;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(500);
    bool clicking = false;

    for (int i = 0; i <= 50; i++)
    {
        cout << endl;
    }

    while (!WindowShouldClose())
    {
        copyArray(grid, fgrid, gridSizeY * gridSizeX);

        Vector2 mousePos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            clicking = true;
        }
        else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            clicking = false;
        }

        if (0 < mousePos.x && mousePos.x < screenWidth && 0 < mousePos.y && mousePos.y < screenHeight && clicking)
        {
            array<int, 2> gridPos = coordToGrid(mousePos.x, mousePos.y, gridSizeX, gridSizeY);
            if (gridPos[0] < gridSizeY && gridPos[1] < gridSizeX)
            {
                fgrid[gridPos[0] * gridSizeX + gridPos[1]] = 1;
            }
        }

        // gravity
        for (int x = 0; x < gridSizeX; x++)
        {
            for (int y = gridSizeY - 1; y >= 0; y--)
            {
                if (grid[y * gridSizeX + x] == 1 && y + 1 < gridSizeY)
                {
                    if (grid[(y + 1) * gridSizeX + x] == 0)
                    {
                        fgrid[y * gridSizeX + x] = 0;
                        fgrid[(y + 1) * gridSizeX + x] = 1;
                    }
                    else if ((x + 1 < gridSizeX && grid[(y + 1) * gridSizeX + x + 1] == 0) ||
                             (x - 1 >= 0 && grid[(y + 1) * gridSizeX + x - 1] == 0))
                    {
                        fgrid[y * gridSizeX + x] = 0;

                        if (x + 1 < gridSizeX && grid[(y + 1) * gridSizeX + x + 1] == 0 &&
                            (x - 1 < 0 || grid[(y + 1) * gridSizeX + x - 1] != 0))
                        {
                            fgrid[(y + 1) * gridSizeX + x + 1] = 1;
                        }
                        else if (x - 1 >= 0 && grid[(y + 1) * gridSizeX + x - 1] == 0)
                        {
                            fgrid[(y + 1) * gridSizeX + x - 1] = 1;
                        }
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(black);
        /*
        // grid ui
        for (int x = 0; x <= screenWidth; x += gridCellSizeX)
        {
            DrawLine(x, 0, x, screenHeight, gray);
        }
        for (int y = 0; y <= screenHeight; y += gridCellSizeY)
        {
            DrawLine(0, y, screenWidth, y, gray);
        }
        */
        copyArray(fgrid, grid, gridSizeX * gridSizeY);

        // draw cells
        for (int y = 0; y < gridSizeY; y++)
        {
            for (int x = 0; x < gridSizeX; x++)
            {
                if (grid[y * gridSizeX + x] == 1)
                {
                    DrawRectangle(x * gridCellSizeX, y * gridCellSizeY, gridCellSizeX, gridCellSizeY, white);
                }
            }
        }

        EndDrawing();
    }

    delete[] grid;
    delete[] fgrid;
    CloseWindow();
    return 0;
}
