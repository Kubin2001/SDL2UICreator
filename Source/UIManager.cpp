#include "UIManager.h"
#include <string>
#include "GlobalVariables.h"
#include "Colision.h"

UIManager::UIManager(UI* ui) {
	this->ui = ui;
}

void UIManager::ManageInput(SDL_Event& event) {
    if (ui->GetInteractionBoxByName("ButtonCreator")->GetStatus() && selectedButton == nullptr) {
        std::string btnName = "Button" + std::to_string(idCounter);
        int x, y;
        SDL_GetMouseState(&x, &y);
        ui->CreateButton(btnName, x, y, 100, 100, nullptr, ui->GetFont("arial12px"),
            "Button", 1.0f, 5, 7, 3);
        ui->SetUIElementBorderColor(btnName, 135, 206, 250);
        ui->SetUIElementFontColor(btnName, 255, 255, 255);
        selectedButton = ui->GetButtonByName(btnName);
        createdButtons.emplace_back(selectedButton);
        idCounter++;
        std::cout << "Created\n";
    }
}

void UIManager::MoveSeletedElement() {
    if (selectedButton != nullptr) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        selectedButton->GetRectangle()->x = x;
        selectedButton->GetRectangle()->y = y;
    }
}

void UIManager::OnClick(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONUP) {
        if (selectedButton != nullptr && selectedButton->GetRectangle()->x < Global::windowWidth - 300 
            - selectedButton->GetRectangle()->w) {
            ui->GetInteractionBoxByName("ButtonCreator")->SetStatus(false);
            selectedButton = nullptr;
            std::cout << "click!\n";
        }
        else if(selectedButton == nullptr)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDL_Rect rect{ x,y,1,1 };
            for (auto &it: createdButtons)
            {
                if (SimpleCollision(rect, *it->GetRectangle())) {
                    selectedButton = it;
                    break;
                }
            }
        }
        
    }
    if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_DELETE) {
            if (selectedButton != nullptr) {
                for (size_t i = 0; i < createdButtons.size(); i++)
                {
                    if (createdButtons[i]->GetName() == selectedButton->GetName()) {
                        createdButtons.erase(createdButtons.begin() + i);
                        ui->DeleteButton(selectedButton->GetName());
                        selectedButton = nullptr;
                        break;
                    }
                }
            }
        }
    }
}