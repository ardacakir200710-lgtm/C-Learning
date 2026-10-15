#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 700

#define GRAVITY 1200.0f

// if you want to walk or jump faster you can edit those 2 macros bellow.
#define DEFAULT_SPEED 300.0f
#define JUMP_FORCE -800.0f 

#include "raylib.h"


int main(void) {
    float scale = 0.25f; // 1/4 smaller texture

    float verticalVelocity = 0.0f;

    // start position is hard coded as x=100 y=100
    Vector2 position = { 100, 100 };

    bool onTheGround = false;  
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PaTrick");

    Texture2D texture = LoadTexture("patrick.png");

    const float ground = (SCREEN_HEIGHT - (texture.height * scale));
    
    // set fps value
    SetTargetFPS(60);

    // mainloop
    while(!WindowShouldClose())
    {
        // for more smooth animations
        // for adaptibility on various computers
        float deltaTime = GetFrameTime();

        // jump trigger
        if( IsKeyPressed(KEY_UP) && onTheGround){
            /* initial velocity is negative because going UP in the window means going to 0 
            (thats how screen coordinates work.)*/
            verticalVelocity = JUMP_FORCE; 
            onTheGround = false;      // we are no longer in ground
        }

        // jump action continue
        if(!onTheGround)
        {
            /*
            since initial vertical velocity was negative, if we add a positive value to it,
            speed will decrease (going up in the screen means (-), going down means (+),
            therefore if we want to make a smooth jump we have to do increase the velocity
            untill velocity becomes 0 and then we go down to the ground(because velocity will
            become positive and positive coordinate means going down)...
            */

            verticalVelocity += GRAVITY * deltaTime; 
            position.y += verticalVelocity * deltaTime; 
        }

        // ground collision check
        if (position.y >= ground) {
            position.y = ground;
            verticalVelocity = 0.0f;
            onTheGround = true; // if we are in the ground again
        }

        // moving on x axis 

        // going right
        if(IsKeyDown(KEY_RIGHT) ){
            position.x += DEFAULT_SPEED * deltaTime;
        }
        // going left
        else if(IsKeyDown(KEY_LEFT)){
            position.x -= DEFAULT_SPEED * deltaTime;
        }


        // right-left wall collision check

        if (position.x >= SCREEN_WIDTH - (texture.width * scale))
            position.x -= (texture.width / (texture.width / 10));
        else if (position.x <= 0)
            position.x += (texture.width / (texture.width / 10));

        BeginDrawing();

        ClearBackground(BLACK);
        DrawTextureEx(texture, position, 0.0f, scale, RAYWHITE);
        
        EndDrawing();

    }

    UnloadTexture(texture);
    CloseWindow();

    
    return 0;
}
