#include <iostream>
#include "raylib.h"
#include "Headers/ship.h"


struct screenParam{
    int screenWidth = 1080;
    int screenHeight = 720;
};


int main(){
    screenParam screen;
    InitWindow(screen.screenWidth,screen.screenHeight,"Asteroids");
    SetTargetFPS(60);

    ship myShip(screen.screenWidth/2,screen.screenHeight/2,30,WHITE);

while(!WindowShouldClose()){
    DrawFPS(20,20);


    if(IsKeyDown(KEY_LEFT)){
        myShip.updateShipAngle((-180)* GetFrameTime());
    }
    else if(IsKeyDown(KEY_RIGHT)){
        myShip.updateShipAngle((180)* GetFrameTime());
    }
    
    if(IsKeyDown(KEY_UP)){
        myShip.applyThrust(100.0f * GetFrameTime());
    }
    
    


    BeginDrawing();
    ClearBackground(BLACK);

    screen.screenWidth = GetScreenWidth();
    screen.screenHeight = GetScreenHeight();

    myShip.drawShip();

    EndDrawing();
}



    CloseWindow();
    return 0;
}
