#include "UIManager.h"

UIManager::UIManager(UI* ui) {
	this->ui = ui;
}

void UIManager::ManageInput(SDL_Event& event) {
    if (ui->GetInterctionBoxByName("ButtonCreator")->GetStatus() && selectedButton == nullptr) {
        ui->GetInterctionBoxByName("ButtonCreator")->SetStatus(false);
        int x, y;
        SDL_GetMouseState(&x, &y);
        ui->CreateButton("Button", x, y, 100, 100, nullptr, "Button", 20, 18, 0, 0, 2);
        ui->SetUIElementBorderColor("Button", 135, 206, 250);
        selectedButton = ui->GetButtonByName("Button");
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