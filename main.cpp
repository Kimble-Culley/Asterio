#include <iostream>
#include <vector>
#include <algorithm>
#include "raylib.h"
#include "ship.h"
#include "bullet.h"

std::vector<Bullet> bullets;

struct screenParam{
    int screenWidth = 1920;
    int screenHeight = 1080;
};


int main(){
    screenParam screen;
    InitWindow(screen.screenWidth,screen.screenHeight,"Asteroids");
    SetTargetFPS(60);

    Ship myShip(screen.screenWidth/2,screen.screenHeight/2,30,WHITE);

    float shootDelay = 0.25f;
    float coolDown = 0.0f;

while(!WindowShouldClose()){
    DrawFPS(20,20);
    float dt = GetFrameTime();

    if(IsKeyDown(KEY_LEFT)){
        myShip.updateShipAngle((-180)* GetFrameTime());
    }
    if(IsKeyDown(KEY_RIGHT)){
        myShip.updateShipAngle((180)* GetFrameTime());
    }
    if(IsKeyDown(KEY_UP)){
        myShip.applyThrust(100.0f * GetFrameTime());
    }


    coolDown -= dt;

    if(IsKeyDown(KEY_SPACE) && coolDown <= 0.0f){
        bullets.push_back(Bullet(myShip));
        coolDown = shootDelay;
    }
    
    for(auto& bullet : bullets){
        bullet.update(dt);
    }

    for(auto it = bullets.begin(); it != bullets.end();){
        if(it -> isDead()){
            it = bullets.erase(it);
        }
        else{
            it++;
        }
    }


    BeginDrawing();
    ClearBackground(BLACK);

    screen.screenWidth = GetScreenWidth();
    screen.screenHeight = GetScreenHeight();

    myShip.drawShip();

    for(const auto& bullet : bullets){
        bullet.draw();
    }

    EndDrawing();
}



    CloseWindow();
    return 0;
}
