//
//  main.cpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#include <iostream>
#include "./Game.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Game game;
    game.Initialize();
    game.Loop();
    game.ShutDown();
    return 0;
}
