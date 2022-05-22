#include "raylib.h"

int main()
{
    // Initial window setup
    const int width{512};
    const int height{380};
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
