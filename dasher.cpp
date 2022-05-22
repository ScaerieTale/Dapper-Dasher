#include "raylib.h"

int main()
{
    // Initial window setup
    const int width{512};
    const int height{380};
    InitWindow(width, height, "Dapper Dasher");
    SetTargetFPS(60);
    
    // Rectangle Dimensions - FOR SCIENCE!!
    const int rect_width{40};
    const int rect_height{40};
    int rect_x{200};
    int rect_y{0};

    // Initiate game loop
    while(!WindowShouldClose())
    {
        // In-game window setup
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begin
        DrawRectangle(rect_x, rect_y, rect_height, rect_width, BLUE);




        // Game logic end
        EndDrawing();
    };
}