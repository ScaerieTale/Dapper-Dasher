#include "raylib.h"

int main()
{
    // Initial window setup
    const int window_width{512};
    const int window_height{380};
    InitWindow(window_width, window_height, "Dapper Dasher");
    SetTargetFPS(60);

    // Acceleration (pixels/frame)/frame
    const int gravity{1};

    // jump velocity
    const int jumpVel{20};
    
    // Rectangle Dimensions - FOR SCIENCE!!
    const int width{80};
    const int height{50};
    
    // Rectangle location in space
    int pos_x{window_width / 2};
    int pos_y{window_height - height};
    int velocity{0};

    // Initiate game loop
    while(!WindowShouldClose())
    {
        // In-game window setup
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begin
        DrawRectangle(pos_x, pos_y, width, height, BLUE);

        // Physics
        // Check for ground
        if (pos_y >= window_height - height)
        {
            // On the ground
            velocity = 0;
        }
        else
        {
            // In mid-air, apply gravity
            velocity -= gravity;
        }
        // Spacebar to jump!
        if (IsKeyPressed(KEY_SPACE))
        {
            velocity += jumpVel;
        }

        // Update position
        pos_y -= velocity;



        // Game logic end
        EndDrawing();
    };
}
