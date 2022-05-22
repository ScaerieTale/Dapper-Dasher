#include "raylib.h"

int main()
{
    // Initial window setup
    int width{800};
    int height{450};
    InitWindow(width, height, "Dapper Dasher");
    SetTargetFPS(60);

    // Initiate game loop
    while(WindowShouldClose() != true)
    {
        // In-game window setup
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begin




        // Game logic end
        EndDrawing();
    };
};
