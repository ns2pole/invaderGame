//
//  DrawComponent.hpp
//  invader
//
//  Created by nakamura on 2024/01/25.
//

#ifndef DrawComponent_hpp
#define DrawComponent_hpp

#include <stdio.h>
#include "SDL2/SDL_image.h"
#include "Object.hpp"
class DrawComponent {
    public:
        Object* owner;
        SDL_Surface* image;
        SDL_Texture* generateTexture(SDL_Renderer* mRenderer);
        DrawComponent(Object* owner);
        void Draw(SDL_Renderer* renderer);
};
#endif /* DrawComponent_hpp */
