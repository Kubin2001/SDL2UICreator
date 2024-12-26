#pragma once
#include <SDL.h>
#include "UI.h"
#include "UIManager.h"
#include <memory>

class Program {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    std::unique_ptr<UI> ui;
    std::unique_ptr<UIManager> uiManager;


public:
    Program();

    void Start();

    void LoadTextures();

    void GameLogic();

    void EventsLogic();

    void MovementLogic();

    void FiveTickEvents();

    void TwentyTickEvents();

    void FiftyTickEvents();

    void OneSecondTickEvents();

    void HundretTickEvents();

    void FiveHundretTickEvents();

    void GameConstant();

    void EventsConstant();

    void MovementConstant();

    void Exit(const Uint8* state);

    void Render();

    ~Program();

};
