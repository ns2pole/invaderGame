#include "Game.hpp"
#include "Beam.hpp"
#include "SDL2/SDL_image.h"
Game::Game()
:ship(30)
{}


SDL_Surface *image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/ship.png");

bool Game::Initialize() {
    mWindow = SDL_CreateWindow("InvaderGame", 100, 100, 1024, 768, 0);
    Beam b = Beam(300, 100 ,20);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    image_texture = SDL_CreateTextureFromSurface(mRenderer, image); // 一度だけテクスチャを生成
    return true;
};

void Game::Loop() {
    bool running = true;
    SDL_Event e;
    while(running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            else if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.sym == SDLK_l) {
                    ship.x += 5;
                } else if (e.key.keysym.sym == SDLK_a) {
                    ship.x -= 5;
                }
            }
        }
        SDL_Rect shipRect = { ship.x, ship.y, ship.size, ship.size };
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
        SDL_RenderClear(mRenderer);
        SDL_RenderCopy(mRenderer, image_texture, NULL, &shipRect);
        SDL_RenderPresent(mRenderer);
    }
    // テクスチャの解放
    SDL_DestroyTexture(image_texture);
}
