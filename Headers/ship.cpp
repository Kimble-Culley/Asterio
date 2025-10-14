#include <cmath>
#include "raylib.h"
#include "ship.h"




ship::ship(float x, float y, float size, Color color){
    posX = x;
    posY = y;
    shipSize = size;
    shipColor = color;

    speedX = 0.0f;
    speedY = 0.0f;
    shipAngle = 0.0f;

    center = {posX,posY};

    calculateVectors();
}


void ship::calculateVectors(){
    topV = {center.x + sinf(DEG2RAD * (shipAngle+180)) * shipSize, 
            center.y + cosf(DEG2RAD * (shipAngle+180)) * shipSize};

    rightV = {center.x + sinf(DEG2RAD * (shipAngle-45)) * shipSize, 
            center.y + cosf(DEG2RAD * (shipAngle-45)) * shipSize};

    leftV = {center.x + sinf(DEG2RAD * (shipAngle+45)) * shipSize, 
            center.y + cosf(DEG2RAD * (shipAngle+45)) * shipSize};

}


void ship::drawShip(){
    DrawTriangleLines(topV,rightV,leftV,shipColor);

    DrawPixelV(topV,RED);
    DrawPixelV(rightV,BLUE);
    DrawPixelV(leftV,GREEN);
}

float ship::getSpeedX(){
    return speedX;
}

float ship::getSpeedY(){
    return speedY;
}

float ship::getPosX(){
    return posX;
}

float ship::getPosY(){
    return posY;
}

float ship::getShipAngle(){
    return shipAngle;
}


