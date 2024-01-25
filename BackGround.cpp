//
//  BackGround.cpp
//  invader
//
//  Created by nakamura on 2024/01/21.
//

#include "BackGround.hpp"
SDL_Texture* BackGround::generateTexture(SDL_Renderer* mRenderer) {
    return SDL_CreateTextureFromSurface(mRenderer, image);
}
