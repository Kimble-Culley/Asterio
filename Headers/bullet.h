#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class bullet{

private:

float speedX,speedY;
float bulletSize;
Vector2 center;
Color bulletColor;


public:


void drawBullet();


};



#endif //BULLET_H