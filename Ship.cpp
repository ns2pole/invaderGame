//
//  Ship.cpp
//  invader
//
//  Created by nakamura on 2024/01/17.
//

#include "Ship.hpp"
#include "SDL2/SDL_image.h"
#include "component/DrawComponent.hpp"


Ship::Ship()
{
    x = 400;
    y = 670;
    speed = 400;
    scale = 0.1;
    dc = new DrawComponent(this, "/Users/nakamura/Program/C++/invader/invader/image/ship.png");
}


void Ship::UpdateToRight(float deltaTime) {
    x += speed * deltaTime;
}

void Ship::UpdateToLeft(float deltaTime) {
    x -= speed * deltaTime;
}

