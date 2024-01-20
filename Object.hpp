////
////  Object.hpp
////  invader
////
////  Created by nakamura on 2024/01/18.
////
//
#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "SDL2/SDL_image.h"
#include "Object.hpp"

class Object {
public:
    Object();
    int x;
    int y;
    int size;
    SDL_Surface* image;
};

#endif /* Object_hpp */