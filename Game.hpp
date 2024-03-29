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
#include "BackGround.hpp"
#include "AudioComponent.hpp"
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
    float GetDeltaTime();

private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Uint32 mTicksCount;
    Ship ship;
    BackGround background;
    std::list<Beam*> beams;
    bool mIsRunning;
    
};
