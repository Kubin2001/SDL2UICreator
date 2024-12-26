#pragma once
#include "UI.h"
#include <SDL.h>

class UIManager {
	private:
		UI* ui;
		Button* selectedButton = nullptr;
		MassageBox* selectedInteractionBox = nullptr;
		InteractionBox* selectedMassageBox = nullptr;
	public:
		UIManager(UI*ui);

		void ManageInput(SDL_Event &event);

		void MoveSeletedElement();


};
