#ifndef SHIP_H
#define SHIP_H

#include "raylib.h"


class ship{

private:

float speedX,speedY;
float posX,posY;
float shipAngle;
float shipSize;
Vector2 center, topV, rightV, leftV;
Color shipColor;


void calculateVectors();

public:

ship(float x, float y, float size, Color color);


void drawShip();



float getSpeedX();
float getSpeedY();
float getPosX();
float getPosY();
float getShipAngle();


};

#endif //SHIP_H