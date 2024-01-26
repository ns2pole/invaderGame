//
//  main.cpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#include <iostream>
#include "./Game.hpp"

int main(int argc, const char * argv[]) {
    Game game;
    game.Initialize();
    game.RunLoop();
    game.ShutDown();
    return 0;
}
