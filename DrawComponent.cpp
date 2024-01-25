//
//  DrawComponent.cpp
//  invader
//
//  Created by nakamura on 2024/01/25.
//

#include "DrawComponent.hpp"
#include "SDL2/SDL_image.h"
#include "Object.hpp"


DrawComponent::DrawComponent(Object* o):owner(o){};

void DrawComponent::Draw(SDL_Renderer* renderer) {
    SDL_QueryTexture(owner->texture, nullptr, nullptr, &owner->width, &owner->height);
    SDL_Rect rect = { static_cast<int>(owner->x), static_cast<int>(owner->y)
    , static_cast<int>(owner->width * owner->scale), static_cast<int>(owner->height * owner->scale)};
    SDL_RenderCopy(renderer, owner->texture, NULL, &rect);
};
