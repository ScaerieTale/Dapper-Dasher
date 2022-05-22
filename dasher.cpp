#include "raylib.h"

int main()
{
    // Initial window setup
    const int window_width{512};
    const int window_height{380};
    InitWindow(window_width, window_height, "Dapper Dasher");
    SetTargetFPS(60);

    // Acceleration (pixels/sec)/sec
    const int gravity{1000};

    // jump velocity in pixles/second
    const int jumpVel{575};
    bool isInAir{false};    
    // Velocity is 0 when not jumping
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
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        // Physics
        // Delta Time
        const float dT{GetFrameTime()};

        // Check for ground
        if (scarfyPos.y >= window_height - scarfy.height)
        {
            // On the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // In mid-air, apply gravity
            velocity -= gravity * dT;
        }
        // Spacebar to jump!
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
            isInAir = true;
        }

        // Update position
        scarfyPos.y -= velocity * dT;



        // Game logic end
        EndDrawing();
    };
    UnloadTexture(scarfy);
    CloseWindow();

}
