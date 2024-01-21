#include "Game.hpp"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
bool Game::Initialize() {
    mWindow = SDL_CreateWindow("InvaderGame", 100, 100, 1024, 768, 0);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    ship_texture = SDL_CreateTextureFromSurface(mRenderer, ship.image);
    bg_texture = SDL_CreateTextureFromSurface(mRenderer, bg.image);
    Mix_OpenAudio( 22050, AUDIO_S16SYS, 2, 4096 );
    beamAudio = Mix_LoadWAV("/Users/nakamura/Program/C++/invader/invader/beam.wav");
    Mix_Volume(-1, MIX_MAX_VOLUME / 3);
    return true;
};

void Game::RunLoop() {
    while(mIsRunning) {
        Game::ProcessInput();
        Game::Update();
        Game::Draw();
    }
    
}


void Game::Update() {
    float deltaTime = Game::GetDeltaTime();
    const Uint8* state = SDL_GetKeyboardState(NULL);
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if(state[SDL_SCANCODE_SPACE]) {
            beams.push_back(Beam(ship.x, ship.y - 10));
            Mix_PlayChannel(-1, beamAudio, 0);
        }
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        ship.UpdateToRight(deltaTime);
    } else if (state[SDL_SCANCODE_LEFT]) {
        ship.UpdateToLeft(deltaTime);
    }
    for (Beam &beam : beams) {
        beam.Update(deltaTime);
    }
    mTicksCount = SDL_GetTicks();
}

void Game::ShutDown() {
    //    Mix_FreeChunk(beamAudio);
    //    Mix_CloseAudio();
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::ProcessInput() {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_Q]) {
        mIsRunning = false;
	}
}

void Game::Draw() {
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 140, 240, 200, 255); // パドルの色を設定
    for (Beam &beam : beams) {
        SDL_Rect paddle{static_cast<int>(beam.x), static_cast<int>(beam.y), beam.width, beam.length};
        SDL_RenderFillRect(mRenderer, &paddle);
    }
    SDL_Rect shipRect = { static_cast<int>(ship.x), static_cast<int>(ship.y)
        , ship.size, ship.size };
//    SDL_Rect bgRect = { static_cast<int>(ship.x + 100),static_cast<int>(ship.y)
//        , ship.size * 4, ship.size * 4};
    SDL_RenderCopy(mRenderer, ship_texture, NULL, &shipRect);
//
//    SDL_RenderCopy(mRenderer, bg_texture, nullptr, &bgRect);
    SDL_RenderPresent(mRenderer);
}

float Game::GetDeltaTime() {
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    return deltaTime;
}
