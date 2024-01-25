//
//  BackGround.hpp
//  invader
//
//  Created by nakamura on 2024/01/21.
//

#ifndef BackGround_hpp
#define BackGround_hpp

#include <stdio.h>
#include "SDL2/SDL_image.h"
#include "DrawComponent.hpp"
#include "Object.hpp"
class BackGround : public Object {
public:
    BackGround();
    DrawComponent* dc;
};
#endif /* BackGround_hpp */
