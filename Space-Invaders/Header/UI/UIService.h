#pragma once
#include"MainMenu/MainMenuController.h"

namespace UI {

	class UIService
	{
	private:

		MainMenu::MainMenuController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();


	public:

		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}
