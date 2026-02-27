#pragma once

#include "raylib.h"
#include <vector>

class Asteroid{

    private:

    int size;
    int min, max;
    Vector2 center;
    std::vector<Vector2> points;
    


    public:
    Asteroid();

    void genAsteroid();
    void update();
    void draw() const;

};