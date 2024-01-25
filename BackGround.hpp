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

class BackGround {
public:
    SDL_Surface* image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/backGround.png");
    SDL_Texture* texture;
    SDL_Texture* generateTexture(SDL_Renderer* mRenderer);
};
#endif /* BackGround_hpp */
