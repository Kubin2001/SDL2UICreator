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

		Button* infoButton = nullptr;
		MassageBox* infoInteractionBox = nullptr;
		InteractionBox* infoMassageBox = nullptr;

		std::vector<Button*> createdButtons;
		std::vector<MassageBox*> createdMassageBoxes;
		std::vector<InteractionBox*> createdInteractionBoxes;
		unsigned int idCounter = 0;
		bool sidePanel = false;
	public:
		UIManager(UI*ui);

		void ManageInput(SDL_Event &event);

		void CreateRightPanelInfo();

		void DeleteRightPanelInfo();

		void ManageRightPanelInput();

		void MoveSeletedElement();

		void OnClick(SDL_Event& event);


};
