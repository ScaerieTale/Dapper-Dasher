#include "raylib.h"

int main()
{
    // Initial window setup
    const int window_width{512};
    const int window_height{380};
    InitWindow(window_width, window_height, "Dapper Dasher");
    SetTargetFPS(60);
    
    // Rectangle Dimensions - FOR SCIENCE!!
    const int rect_width{50};
    const int rect_height{80};
    int rect_x{window_width / 2};
    int rect_y{window_height - rect_height};
    int rect_velocity{-10};

    // Initiate game loop
    while(!WindowShouldClose())
    {
        // In-game window setup
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begin
        DrawRectangle(rect_x, rect_y, rect_height, rect_width, BLUE);
        rect_y += rect_velocity;




        // Game logic end
        EndDrawing();
    };
}