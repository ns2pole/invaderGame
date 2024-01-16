//
//  Game.hpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#endif /* Game_hpp */
class Game {
public:
    Game();
    bool Initialize();
    void Loop();
    void ShutDown();

private:
    SDL_Window* mWindow;
    
};
