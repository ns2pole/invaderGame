//
//  AudioComponent.cpp
//  invader
//
//  Created by nakamura on 2024/01/26.
//

#include "AudioComponent.hpp"

AudioComponent::AudioComponent(Object* owner, const char* audioURL) : Component(owner){
     audio = Mix_LoadWAV(audioURL);
};

void AudioComponent::Sound() {
    Mix_PlayChannel(-1, audio, 0);
}
