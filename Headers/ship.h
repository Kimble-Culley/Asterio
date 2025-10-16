#ifndef SHIP_H
#define SHIP_H

#include "raylib.h"


class ship{

private:

float speedX,speedY;
float shipAngle;
float shipSize;
Vector2 center, topV, rightV, leftV;
Color shipColor;


void calculateVectors();
void calculateSpeed();
void wrapShipScreen();

public:

ship(float x, float y, float size, Color color);


void drawShip();
void updateShipAngle(float newAngle);
void applyThrust(float thrustPower);


float getSpeedX();
float getSpeedY();
float getCenterX();
float getCenterY();
float getShipAngle();


};

#endif //SHIP_H