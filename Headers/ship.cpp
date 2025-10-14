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
    topV = {center.x + cosf(DEG2RAD * shipAngle) * shipSize, 
            center.y + sinf(DEG2RAD * shipAngle) * shipSize};

    rightV = {center.x + cosf(DEG2RAD * (shipAngle + 120)) * shipSize, 
            center.y + sinf(DEG2RAD * (shipAngle + 120)) * shipSize};

    leftV = {center.x + cosf(DEG2RAD * (shipAngle + 240)) * shipSize, 
            center.y + sinf(DEG2RAD * (shipAngle + 240)) * shipSize};

}


void ship::drawShip(){
    DrawTriangleLines(topV,rightV,leftV,shipColor);
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


