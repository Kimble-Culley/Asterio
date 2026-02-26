#pragma once

#include "raylib.h"
#include "ship.h"
#include "screen.h"

class Bullet{

private:

Vector2 position;
Vector2 velocity;
float radius;
Color color;

float lifetime;
float age;


public:


Bullet(const Ship& ship);
void update(float dt);
void draw() const;

bool isDead() const;
};
