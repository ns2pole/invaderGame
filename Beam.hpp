//
//  Beam.hpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#ifndef Beam_hpp
#define Beam_hpp

#include <stdio.h>
#include "Object.hpp"
#include "DrawComponent.hpp"

class Beam : public Object {
public:
    Beam(int x, int y);
    int velocity;
    void Update(float deltaTime);
    DrawComponent* dc;
    SDL_Texture* generateTexture(SDL_Renderer* mRenderer);

};

    
#endif /* Beam_hpp */
