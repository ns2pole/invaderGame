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
#include "component/DrawComponent.hpp"

#endif /* Ship_hpp */

class Ship : public Object {
public:
    Ship();
    float speed;
    void UpdateToRight(float deltaTime);
    void UpdateToLeft(float deltaTime);
    DrawComponent* dc;
};
