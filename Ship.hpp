//
//  Ship.hpp
//  invader
//
//  Created by nakamura on 2024/01/17.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include "SDL2/SDL_image.h"
#include "Object.hpp"
#include "DrawComponent.hpp"

#endif /* Ship_hpp */

class Ship : public Object {
public:
    Ship();
    float speed;
    void UpdateToRight(float deltaTime);
    void UpdateToLeft(float deltaTime);
    SDL_Texture* generateTexture(SDL_Renderer* mRenderer);
    DrawComponent* dc;
//    SDL_Surface* image;
};
