#include <iostream>
#include "raylib.h"

const int screenWidth = 1080;
const int screenHeight = 720;


struct Ship{
    float speedY, speedX = 0;
    float x = screenWidth/2;
    float y = screenHeight/2;

    float changeSpeed(float speed);
};

void shipDirection(Ship& ship);


int main(){

InitWindow(screenWidth,screenHeight,"Asteroids");

SetTargetFPS(60);

Ship ship;

while(!WindowShouldClose()){
    float DeltaTime = GetFrameTime();




    BeginDrawing();
    ClearBackground(BLACK);

    shipDirection(ship);


    DrawTriangleLines((Vector2){ship.x,ship.y}, (Vector2){ship.x+10,ship.y+30}, (Vector2){ship.x-10,ship.y+30},WHITE);

    
    EndDrawing();
}



    CloseWindow();
    return 0;
}

void shipDirection(Ship& ship){
    if(IsKeyDown(KEY_UP)){
        ship.y -= ship.changeSpeed(ship.speedY);
    }
}

float Ship::changeSpeed(float speed){
    speed -= 0.15;
    return speed;
}