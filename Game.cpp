#include "Game.hpp"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
bool Game::Initialize() {
    //window生成
    mWindow = SDL_CreateWindow("InvaderGame", 100, 100, 1024, 768, 0);
    //描画エンジンの初期化
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096 );
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
            Beam* beam = new Beam(ship.x, ship.y - 10);
            beams.push_back(beam);
            beam->ac->Sound();
        }
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        ship.UpdateToRight(deltaTime);
    } else if (state[SDL_SCANCODE_LEFT]) {
        ship.UpdateToLeft(deltaTime);
    }
    for (Beam *beam : beams) {
        beam->Update(deltaTime);
    }
    mTicksCount = SDL_GetTicks();
}

void Game::ShutDown() {
    //    Mix_FreeChunk(beamAudio);
    //    Mix_CloseAudio();
    //描画エンジン
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
    //全画面塗りつぶし
    SDL_RenderClear(mRenderer);
    background.dc->Draw(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 140, 240, 200, 255); // パドルの色を設定
    for (Beam* beam : beams) {
        beam->dc->Draw(mRenderer);
    }
    ship.dc->Draw(mRenderer);
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
