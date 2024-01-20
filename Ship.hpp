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

#endif /* Ship_hpp */

class Ship : public Object {
public:
    Ship();
    float speed;
    void Update(float deltaTime);
//    SDL_Surface* image;
};
