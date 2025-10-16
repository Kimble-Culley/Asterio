#include <cmath>
#include "raylib.h"
#include "ship.h"




ship::ship(float x, float y, float size, Color color){
    shipSize = size;
    shipColor = color;

    speedX = 0.0f;
    speedY = 0.0f;
    shipAngle = -90.0f;
    center = {x,y};

    calculateVectors();
}


//Calculate vertex positions

void ship::calculateVectors(){
    if(shipAngle >= 360 || shipAngle <= -360){
        shipAngle = 0;
    }

    topV = {center.x + cosf(DEG2RAD * shipAngle) * shipSize,
        center.y + sinf(DEG2RAD * shipAngle) * shipSize};

    rightV = {center.x + cosf(DEG2RAD * (shipAngle + 135)) * shipSize,
          center.y + sinf(DEG2RAD * (shipAngle + 135)) * shipSize};

    leftV = {center.x + cosf(DEG2RAD * (shipAngle - 135)) * shipSize,
         center.y + sinf(DEG2RAD * (shipAngle - 135)) * shipSize};

}


//Movement and thrust


void ship::calculateSpeed() {

    center.x += speedX * GetFrameTime();
    center.y += speedY * GetFrameTime();


    speedX *= 0.998f;
    speedY *= 0.998f;
}

void ship::applyThrust(float thrustPower) {

    float rad = DEG2RAD * shipAngle;


    speedX += thrustPower * cosf(rad);
    speedY += thrustPower * sinf(rad);
}


//Rotation and Drawing

void ship::updateShipAngle(float newAngle){
    shipAngle += newAngle;
}

void ship::drawShip(){
    calculateVectors();
    calculateSpeed();
    wrapShipScreen();

    DrawTriangleLines(topV,rightV,leftV,shipColor);

    //DEBUG
    DrawPixelV(topV,RED);
    DrawPixelV(rightV,BLUE);
    DrawPixelV(leftV,GREEN);
}

void ship::wrapShipScreen(){
    if(center.x > GetScreenWidth()){
        center.x = 0;
    }
    else if (center.x < 0){
        center.x = GetScreenWidth();
    }

    if(center.y > GetScreenHeight()){
        center.y = 0;
    }
    else if (center.y < 0){
        center.y = GetScreenHeight();
    }

}




//*****************//
//                 //
//     Getters     //
//                 //
//*****************//

float ship::getSpeedX(){ return speedX; }

float ship::getSpeedY(){ return speedY; }

float ship::getCenterX(){ return center.x; }

float ship::getCenterY(){ return center.y; }

float ship::getShipAngle(){ return shipAngle; }
