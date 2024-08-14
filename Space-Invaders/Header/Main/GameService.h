#pragma once
#include<SFML/Graphics.hpp>
#include"../Global/ServiceLocator.h"
namespace Main
{   
	using namespace Global;
	class GameService
	{
	private:

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void destroy();			

	public:

		GameService();			
		~GameService();	

		void ignite();			
		void update();			
		void render();			
		bool isRunning();		
	};
}
