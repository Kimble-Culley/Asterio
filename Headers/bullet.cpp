#include "raylib.h"
#include "bullet.h"


void bullet::drawBullet(){
    DrawCircle(center.x,center.y,10,bulletColor);
}