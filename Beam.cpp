//
//  Beam.cpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#include "Beam.hpp"
#include "Ship.hpp"

Beam::Beam(int xx, int yy) {
    x = xx;
    y = yy;
    width = 10;
    height = 35;
    velocity = 300;
    image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/beam.png");
    dc = new DrawComponent(this);
}

void Beam::Update(float deltaTime){
    y -= velocity * deltaTime;
}


SDL_Texture* Beam::generateTexture(SDL_Renderer* mRenderer) {
    return SDL_CreateTextureFromSurface(mRenderer, image);
}
