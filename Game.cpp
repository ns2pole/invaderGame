#include "Game.hpp"
#include "SDL2/SDL_image.h"
Game::Game()
:ship(30)
{}


SDL_Surface *image = IMG_Load("/Users/nakamura/Program/C++/invader/invader/ship.png");

bool Game::Initialize() {
    mWindow = SDL_CreateWindow("InvaderGame", 100, 100, 1024, 768, 0);
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
                } else if(e.key.keysym.sym == SDLK_SPACE) {
                    beams.push_back(Beam(ship.x, ship.y - 10));
                }
            }
        }
        SDL_Rect shipRect = { ship.x, ship.y, ship.size, ship.size };
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
        SDL_RenderClear(mRenderer);
        
        SDL_SetRenderDrawColor(mRenderer, 140, 240, 200, 255); // パドルの色を設定
        for (Beam &beam : beams) {
            beam.y -= beam.velocity;
            SDL_Rect paddle{beam.x, beam.y, beam.width, beam.length};
            SDL_RenderFillRect(mRenderer, &paddle);
        }
        SDL_RenderCopy(mRenderer, image_texture, NULL, &shipRect);
        SDL_RenderPresent(mRenderer);
    }
    // テクスチャの解放
    SDL_DestroyTexture(image_texture);
}
