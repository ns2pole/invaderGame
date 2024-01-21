//
//  Game.hpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#ifndef Game_hpp
#define Game_hpp
#include "Ship.hpp"
#include "Beam.hpp"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"

#include <list>
#endif /* Game_hpp */
class Game {
public:
    bool Initialize();
    void Update();
    void ShutDown();
    void ProcessInput();
    void Draw();
    void RunLoop();

private:
    SDL_Window* mWindow;
    Uint32 mTicksCount;
    Ship ship;
    SDL_Renderer* mRenderer;
    SDL_Texture* image_texture;
    Mix_Chunk* beamAudio;
    std::list<Beam> beams;
    bool mIsRunning;
};
