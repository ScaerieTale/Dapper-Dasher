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
    bool isInAir{false};    

    // Rectangle dimensions
    const int width{50};
    const int height{80};
    
    // Rectangle location in space
    int pos_x{window_width / 2};
    int pos_y{window_height - height};
    int velocity{0};
    
    // Character
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.height = scarfy.height;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = window_width/2 - scarfyRec.width/2;
    scarfyPos.y = window_height - scarfyRec.height;

    

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
            isInAir = false;
        }
        else
        {
            // In mid-air, apply gravity
            velocity -= gravity;
        }
        // Spacebar to jump!
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
            isInAir = true;
        }

        // Update position
        pos_y -= velocity;



        // Game logic end
        EndDrawing();
    };
}
