#include "bullet.h"
#include <cmath>




Bullet::Bullet(const Ship& ship){
    radius = 6;
    color = WHITE;

    position = ship.getVector();

    float angle = DEG2RAD * ship.getShipAngle();

    float speed = 400.0f;

    velocity.x = cos(angle) * speed + ship.getSpeedX();
    velocity.y = sin(angle) * speed + ship.getSpeedY(); 

    lifetime = 5.0f;
    age = 0.0f;

}

void Bullet::update(float dt){
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    wrapPosition(position);

    age += dt;
}

void Bullet::draw() const {
    DrawCircle(position.x,position.y,radius,color);
}

bool Bullet::isDead() const {
    return age >= lifetime;
}