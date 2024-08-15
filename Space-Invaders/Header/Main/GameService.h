#pragma once
#include<SFML/Graphics.hpp>
#include"../Global/ServiceLocator.h"
namespace Main
{   
	using namespace Global;
	enum class GameState {
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};
	class GameService
	{
	private:
		static GameState current_state;
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void destroy();
		void showMainMenu();

	public:

		GameService();			
		~GameService();	

		void ignite();			
		void update();			
		void render();			
		bool isRunning();		
		static GameState getGameState();
		static void setGameState(GameState new_state);
	};
}
