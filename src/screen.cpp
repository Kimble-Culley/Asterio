#include "screen.h"


void wrapPosition(Vector2& position){

    int width = GetScreenWidth();
    int height = GetScreenHeight();

    if(position.x > width){
        position.x = 0;
    }
    else if( position.x < 0){
        position.x = width;
    }

    if(position.y > height){
        position.y = 0;
    }
    else if( position.y < 0){
        position.y = height;
    }


}