#pragma once

#include "raylib.h"
#include "screen.h"

class Ship{

private:

float speedX,speedY;
float shipAngle;
float shipSize;
Vector2 center, topV, rightV, leftV;
Color shipColor;


void calculateVectors();
void calculateSpeed();


public:

Ship(float x, float y, float size, Color color);


void drawShip();
void updateShipAngle(float newAngle);
void applyThrust(float thrustPower);

float getSpeedX() const;
float getSpeedY() const;
float getCenterX() const;
float getCenterY() const;
float getShipAngle() const;
Vector2 getVector() const;


};
