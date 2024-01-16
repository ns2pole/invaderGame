#include "Game.hpp"
#include "Beam.hpp"
Game::Game()
:mWindow(nullptr)
{
}
bool Game::Initialize() {
    
    mWindow = SDL_CreateWindow(
        "InvaderGame", // Window title
        100,    // Top left x-coordinate of window
        100,    // Top left y-coordinate of window
        1024,    // Width of window
        768,    // Height of window
        0        // Flags (0 for no flags set)
    );
    SDL_Event e;
    bool quit = false;
    SDL_Renderer* mRenderer = SDL_CreateRenderer(
        mWindow, // Window to create renderer for
        -1,         // Usually -1
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    Beam b = Beam();
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            
        }
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255); // 背景色を設定
        SDL_Rect paddle{ b.x, b.y, b.size, b.size };
        b.x = b.x + 1;
        SDL_RenderClear(mRenderer);
        SDL_SetRenderDrawColor(mRenderer, 140, 240, 200, 255); // パドルの色を設定
        SDL_RenderFillRect(mRenderer, &paddle);
        SDL_RenderPresent(mRenderer); // 描画内容を画面に表示
    }
    return true;
};
