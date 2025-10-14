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
ship myShip(screen.screenWidth/2,screen.screenHeight/2,20,WHITE);
while(!WindowShouldClose()){




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
