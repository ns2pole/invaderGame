#include "Game.hpp"
#include "Beam.hpp"
#include "SDL2/SDL_image.h"
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
    Beam b = Beam(300, 100 ,20);
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
        SDL_RenderClear(mRenderer);
        SDL_Rect paddle{ b.x, b.y, b.size, b.size };
        b.y = b.y + 1;
        printf("Current directory: %s\n", SDL_GetBasePath());
        SDL_Surface *image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/ship2.png");
        if(!image) {
            printf("IMG_Load: %s\n", IMG_GetError());
        }
        SDL_Texture *image_texture = SDL_CreateTextureFromSurface(mRenderer, image);
        SDL_Rect shipRect = { 300, 300, 50, 50 };
        SDL_RenderCopy(mRenderer,image_texture, NULL, &shipRect);
        SDL_SetRenderDrawColor(mRenderer, 140, 240, 200, 255); // パドルの色を設定
        SDL_RenderFillRect(mRenderer, &paddle);
        SDL_RenderPresent(mRenderer); // 描画内容を画面に表示
    }
    return true;
};
