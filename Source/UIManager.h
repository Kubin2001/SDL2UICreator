#pragma once
#include "UI.h"
#include <SDL.h>
#include <vector>

class UIManager {
	private:
		UI* ui;
		Button* selectedButton = nullptr;
		MassageBox* selectedInteractionBox = nullptr;
		InteractionBox* selectedMassageBox = nullptr;
		std::vector<Button*> createdButtons;
		std::vector<MassageBox*> createdMassageBoxes;
		std::vector<InteractionBox*> createdInteractionBoxes;
		unsigned int idCounter = 0;
	public:
		UIManager(UI*ui);

		void ManageInput(SDL_Event &event);

		void MoveSeletedElement();

		void OnClick(SDL_Event& event);


};
