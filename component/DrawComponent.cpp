//
//  DrawComponent.cpp
//  invader
//
//  Created by nakamura on 2024/01/25.
//

#include "DrawComponent.hpp"
#include "SDL2/SDL_image.h"
#include "Object.hpp"


DrawComponent::DrawComponent(Object* owner):owner(owner){
    image = IMG_Load(owner->imageURL);
};

void DrawComponent::Draw(SDL_Renderer* renderer) {
    SDL_Texture* texture = generateTexture(renderer);
    SDL_QueryTexture(texture, nullptr, nullptr, &owner->width, &owner->height);
    SDL_Rect rect = { static_cast<int>(owner->x), static_cast<int>(owner->y)
    , static_cast<int>(owner->width * owner->scale), static_cast<int>(owner->height * owner->scale)};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
};

SDL_Texture* DrawComponent::generateTexture(SDL_Renderer* mRenderer) {
    return SDL_CreateTextureFromSurface(mRenderer, image);
}
