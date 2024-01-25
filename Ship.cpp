//
//  Ship.cpp
//  invader
//
//  Created by nakamura on 2024/01/17.
//

#include "Ship.hpp"
#include "SDL2/SDL_image.h"
#include "DrawComponent.hpp"


Ship::Ship()
{
    x = 400;
    y = 600;
    speed = 400;
    width = 30;
    height = 30;
    image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/ship.png");
    dc = new DrawComponent(this);
}


void Ship::UpdateToRight(float deltaTime) {
    x += speed * deltaTime;
}

void Ship::UpdateToLeft(float deltaTime) {
    x -= speed * deltaTime;
}

SDL_Texture* Ship::generateTexture(SDL_Renderer* mRenderer) {
    return SDL_CreateTextureFromSurface(mRenderer, image);
}
