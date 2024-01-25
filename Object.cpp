//
//  Object.cpp
//  invader
//
//  Created by nakamura on 2024/01/18.
//

#include "Object.hpp"
#include "DrawComponent.hpp"

Object::Object(){
}
SDL_Texture* Object::generateTexture(SDL_Renderer* mRenderer) {
    return SDL_CreateTextureFromSurface(mRenderer, image);
}
