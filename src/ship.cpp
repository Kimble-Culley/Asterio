#include <cmath>
#include "raylib.h"
#include "ship.h"




Ship::Ship(float x, float y, float size, Color color){
    shipSize = size;
    shipColor = color;

    speedX = 0.0f;
    speedY = 0.0f;
    shipAngle = -90.0f;
    center = {x,y};

    calculateVectors();
}



void Ship::calculateVectors(){
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


void Ship::calculateSpeed() {

    center.x += speedX * GetFrameTime();
    center.y += speedY * GetFrameTime();


    speedX *= 0.998f;
    speedY *= 0.998f;
}

void Ship::applyThrust(float thrustPower) {

    float rad = DEG2RAD * shipAngle;

    speedX += thrustPower * cosf(rad);
    speedY += thrustPower * sinf(rad);
}


//Rotation and Drawing

void Ship::updateShipAngle(float newAngle){
    shipAngle += newAngle;
}

void Ship::drawShip(){
    calculateVectors();
    calculateSpeed();
    wrapPosition(center);

    DrawTriangleLines(topV,rightV,leftV,shipColor);

    //DEBUG
    DrawPixelV(topV,RED);
    DrawPixelV(rightV,BLUE);
    DrawPixelV(leftV,GREEN);
}





//*****************//
//                 //
//     Getters     //
//                 //
//*****************//

float Ship::getSpeedX() const{ return speedX; }

float Ship::getSpeedY() const{ return speedY; }

float Ship::getCenterX() const{ return center.x; }

float Ship::getCenterY() const{ return center.y; }

float Ship::getShipAngle() const{ return shipAngle; }

Vector2 Ship::getVector() const{ return topV; }