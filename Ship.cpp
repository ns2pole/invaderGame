//
//  Ship.cpp
//  invader
//
//  Created by nakamura on 2024/01/17.
//

#include "Ship.hpp"
#include "SDL2/SDL_image.h"


Ship::Ship()
{
    x = 400;
    y = 600;
    size = 30;
    image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/ship.png");
}
