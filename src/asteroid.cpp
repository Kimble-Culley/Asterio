#include "asteroid.h"
#include <iostream>
#include <random>


Asteroid::Asteroid(){
    srand(time(0));
    int check = rand() % 100;

    //gen small
    if(check < 33){
        size = 8;
    }
    //gen medium
    else if (check < 66){
        size = 16;
    }
    //gen large
    else{
        size = 32;
    }

    genAsteroid();
}


void Asteroid::genAsteroid(){
    srand(time(0));
    
    if(size == 8){
        min = 15;
        max = 50;
    }
    else if (size == 16){
        min = 30;
        max = 80;

    }
    else{
        min = 50;
        max = 100;
    }

    for(int i = 0; i < size; i++){
        float angle = (2 * PI / size)*i;
        float radialpoint = ((rand() % max) + min);

        points[i] = {
            cosf(angle) * radialpoint,
            sinf(angle) * radialpoint
        };
        
    }
}


void Asteroid::draw() const {
    
}