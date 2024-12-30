#include "UIManager.h"
#include <string>
#include "GlobalVariables.h"
#include "Colision.h"

UIManager::UIManager(UI* ui) {
	this->ui = ui;
}

void UIManager::CreateRightPanelInfo() {
    if (!sidePanel) {
        ui->CreateButton("PosXInfo", Global::windowWidth - 250, 180, 50, 30, nullptr, ui->GetFont("arial12px"), "X pos", 1.0f, 3, 3, 2);
        ui->CreateMassageBox("PosXInput", Global::windowWidth - 190, 180, 50, 30, nullptr, ui->GetFont("arial12px"), "", 1.0f, 3, 3, 2);
        ui->CreateInteractionBox("PosXConfirm", Global::windowWidth - 130, 180, 50, 30, nullptr, ui->GetFont("arial12px"), "Confirm", 1.0f, 3, 3, 2);

        ui->CreateButton("PosYInfo", Global::windowWidth - 250, 240, 50, 30, nullptr, ui->GetFont("arial12px"), "Y pos", 1.0f, 3, 3, 2);
        ui->CreateMassageBox("PosYInput", Global::windowWidth - 190, 240, 50, 30, nullptr, ui->GetFont("arial12px"), "", 1.0f, 3, 3, 2);
        ui->CreateInteractionBox("PosYConfirm", Global::windowWidth - 130, 240, 50, 30, nullptr, ui->GetFont("arial12px"), "Confirm", 1.0f, 3, 3, 2);

        ui->CreateButton("SizeWInfo", Global::windowWidth - 250, 300, 50, 30, nullptr, ui->GetFont("arial12px"), "Width", 1.0f, 3, 3, 2);
        ui->CreateMassageBox("SizeWInput", Global::windowWidth - 190, 300, 50, 30, nullptr, ui->GetFont("arial12px"), "", 1.0f, 3, 3, 2);
        ui->CreateInteractionBox("SizeWConfirm", Global::windowWidth - 130, 300, 50, 30, nullptr, ui->GetFont("arial12px"), "Confirm", 1.0f, 3, 3, 2);

        ui->CreateButton("SizeHInfo", Global::windowWidth - 250, 360, 50, 30, nullptr, ui->GetFont("arial12px"), "Height", 1.0f, 3, 3, 2);
        ui->CreateMassageBox("SizeHInput", Global::windowWidth - 190, 360, 50, 30, nullptr, ui->GetFont("arial12px"), "", 1.0f, 3, 3, 2);
        ui->CreateInteractionBox("SizeHConfirm", Global::windowWidth - 130, 360, 50, 30, nullptr, ui->GetFont("arial12px"), "Confirm", 1.0f, 3, 3, 2);

        ui->CreateButton("TextureInfo", Global::windowWidth - 250, 420, 50, 30, nullptr, ui->GetFont("arial12px"), "Texture", 1.0f, 3, 3, 2);
        ui->CreateMassageBox("TextureInput", Global::windowWidth - 190, 420, 50, 30, nullptr, ui->GetFont("arial12px"), "", 1.0f, 3, 3, 2);
        ui->CreateInteractionBox("TextureConfirm", Global::windowWidth - 130, 420, 50, 30, nullptr, ui->GetFont("arial12px"), "Confirm", 1.0f, 3, 3, 2);
        sidePanel = true;
    }
}

void UIManager::DeleteRightPanelInfo() {
    if (sidePanel) {
        infoButton = nullptr;
        ui->DeleteAnyButton("PosXInfo");
        ui->DeleteAnyButton("PosXInput");
        ui->DeleteAnyButton("PosXConfirm");

        ui->DeleteAnyButton("PosYInfo");
        ui->DeleteAnyButton("PosYInput");
        ui->DeleteAnyButton("PosYConfirm");

        ui->DeleteAnyButton("SizeWInfo");
        ui->DeleteAnyButton("SizeWInput");
        ui->DeleteAnyButton("SizeWConfirm");

        ui->DeleteAnyButton("SizeHInfo");
        ui->DeleteAnyButton("SizeHInput");
        ui->DeleteAnyButton("SizeHConfirm");

        ui->DeleteAnyButton("TextureInfo");
        ui->DeleteAnyButton("TextureInput");
        ui->DeleteAnyButton("TextureConfirm");
        sidePanel = false;
    }
}


void UIManager::ManageRightPanelInput() {
    if (sidePanel) {
        if (ui->GetInteractionBoxByName("PosXConfirm")->GetStatus()) {
            infoButton->GetRectangle()->x = std::stoi(ui->GetMassageBoxByName("PosXInput")->GetText());
            ui->GetInteractionBoxByName("PosXConfirm")->SetStatus(0);
        }
        if (ui->GetInteractionBoxByName("PosYConfirm")->GetStatus()) {
            infoButton->GetRectangle()->y = std::stoi(ui->GetMassageBoxByName("PosYInput")->GetText());
            ui->GetInteractionBoxByName("PosYConfirm")->SetStatus(0);
        }
        if (ui->GetInteractionBoxByName("SizeWConfirm")->GetStatus()) {
            infoButton->GetRectangle()->w = std::stoi(ui->GetMassageBoxByName("SizeWInput")->GetText());
            ui->GetInteractionBoxByName("SizeWConfirm")->SetStatus(0);
        }
        if (ui->GetInteractionBoxByName("SizeHConfirm")->GetStatus()) {
            infoButton->GetRectangle()->h = std::stoi(ui->GetMassageBoxByName("SizeHInput")->GetText());
            ui->GetInteractionBoxByName("SizeHConfirm")->SetStatus(0);
        }

        if (ui->GetInteractionBoxByName("TextureConfirm")->GetStatus()) {
            infoButton->SetTexture(TextureManager::GetTextureByName(ui->GetMassageBoxByName("TextureInput")->GetText()));
            ui->GetInteractionBoxByName("TextureConfirm")->SetStatus(0);
        }
    }
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
        if (event.key.keysym.sym == SDLK_m) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDL_Rect rect{ x,y,1,1 };
            for (auto& it : createdButtons) {
                if (SimpleCollision(*it->GetRectangle(), rect)) {
                    if (infoButton == nullptr) {
                        infoButton = it;
                        CreateRightPanelInfo();
                        break;

                    }
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
                        if (createdButtons[i] == infoButton) {
                            DeleteRightPanelInfo();
                        }
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