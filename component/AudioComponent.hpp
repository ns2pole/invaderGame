//
//  AudioComponent.hpp
//  invader
//
//  Created by nakamura on 2024/01/26.
//

#ifndef AudioComponent_hpp
#define AudioComponent_hpp

#include <stdio.h>
#include "Component.hpp"
#include "SDL2/SDL_mixer.h"

class AudioComponent : public Component {
    public:
        AudioComponent(Object* owner, const char* audioURL);
        Mix_Chunk* audio;
        void Sound();
};
#endif /* AudioComponent_hpp */
