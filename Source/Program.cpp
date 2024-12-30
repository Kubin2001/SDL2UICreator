#include <SDL.h>
#include <iostream>
#include <string>
#include "SDL_image.h"
#include "Program.h"
#include "GlobalVariables.h"
#include "TextureManager.h"


Program::Program() {
    window = nullptr;
    renderer = nullptr;
    ui = nullptr;
}

void Program::Start() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Methane UI Creator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Global::windowWidth, Global::windowHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    Global::defaultDrawColor[0] = 30;
    Global::defaultDrawColor[1] = 30;
    Global::defaultDrawColor[2] = 30;
    SDL_SetRenderDrawColor(renderer, Global::defaultDrawColor[0], Global::defaultDrawColor[1], Global::defaultDrawColor[2], 255);
    TextureManager::Start(renderer);
    LoadTextures();

    ui = std::make_unique<UI>(renderer);
    uiManager = std::make_unique<UIManager>(ui.get());
    ui->LoadTextures();
    ui->CreateFont("arial20px",TextureManager::GetTextureByName("arial20px"),"Textures/Interface/Fonts/arial20px.json");
    ui->CreateFont("arial12px", TextureManager::GetTextureByName("arial12px"), "Textures/Interface/Fonts/arial12px.json");
    

    ui->CreateButton("RightPanelUp", Global::windowWidth - 300, 0, 300, 150, nullptr,
        nullptr, "", 1.0, 0, 0, 2);
    ui->SetUIElementBorderColor("RightPanelUp", 135, 206, 250);

    ui->CreateButton("RightPanelDown", Global::windowWidth - 300, 150, 300, Global::windowHeight - 150, nullptr,
        nullptr, "", 1.0, 0, 0, 2);
    ui->SetUIElementBorderColor("RightPanelDown", 135, 206, 250);

    ui->CreateInteractionBox("ButtonCreator", Global::windowWidth - 290, 10, 50, 50, nullptr,
        ui->GetFont("arial20px"), "cBtn", 1.0, 2, 2, 2);
    ui->SetUIElementBorderColor("ButtonCreator", 135, 206, 250);

    ui->CreateInteractionBox("MassageBoxCreator", Global::windowWidth - 230, 10, 50, 50, nullptr,
        ui->GetFont("arial20px"), "", 1.0, 2, 2, 2);
    ui->SetUIElementBorderColor("MassageBoxCreator", 135, 206, 250);

    ui->CreateInteractionBox("InteractionBoxCreator", Global::windowWidth - 170, 10, 50, 50, nullptr,
        ui->GetFont("arial20px"), "", 1.0, 2, 2, 2);
    ui->SetUIElementBorderColor("InteractionBoxCreator", 135, 206, 250);
}



void Program::LoadTextures() {
    TextureManager::LoadMultipleTextures("Textures/Objects");
}

void Program::GameLogic() {
    EventsLogic();
    MovementLogic();
}

void Program::EventsLogic() {
    Global::frameCounter++;
    FiveTickEvents();
}

void Program::MovementLogic() {
}

void Program::FiveTickEvents() {
    if (Global::frameCounter % 5 == 0) {
        //FiveTicks
        //FiveTicks
        if (Global::frameCounter % 20 == 0) {
            TwentyTickEvents();
        }
        if (Global::frameCounter % 60 == 0) {
            OneSecondTickEvents();
        }
        if (Global::frameCounter % 50 == 0) {
            FiftyTickEvents();

            if (Global::frameCounter % 100 == 0) {
                HundretTickEvents();
            }
            if (Global::frameCounter % 500 == 0) {
                FiveHundretTickEvents();
            }
        }
    }
}

void Program::TwentyTickEvents() {

}

void Program::FiftyTickEvents() {

}

void Program::OneSecondTickEvents() {
}

void Program::HundretTickEvents() {

}

void Program::FiveHundretTickEvents() {

}

void Program::GameConstant() {
    EventsConstant();
    MovementConstant();
    Render();
}




void Program::EventsConstant() {
    while (SDL_PollEvent(&event)) {
        uiManager->OnClick(event);
        ui->ManageInput(event);

    }
    uiManager->ManageInput(event);
    uiManager->ManageRightPanelInput();
    Global::inputDelay++;
}

void Program::MovementConstant() {
    SDL_PumpEvents();
    const Uint8* state = SDL_GetKeyboardState(NULL);
    uiManager->MoveSeletedElement();
    Exit(state);
}




void Program::Exit(const Uint8* state) {
    if (state[SDL_SCANCODE_ESCAPE]) {
        Global::status = false;
    }
}


void Program::Render() {
    SDL_RenderClear(renderer);
    ui->Render();
    SDL_RenderPresent(renderer);
}

Program::~Program() {
    TextureManager::Clear();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //std::cout << "Resources Destroyed";
}
