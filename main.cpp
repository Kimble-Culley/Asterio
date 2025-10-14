#include <iostream>
#include "raylib.h"
#include "Headers/ship.h"

const int screenWidth = 1080;
const int screenHeight = 720;



int main(){
InitWindow(screenWidth,screenHeight,"Asteroids");
SetTargetFPS(60);

ship myShip(screenWidth/2,screenHeight/2,100,WHITE);
while(!WindowShouldClose()){




    BeginDrawing();
    ClearBackground(BLACK);

    myShip.drawShip();
    
    EndDrawing();
}



    CloseWindow();
    return 0;
}
