#include"../../Header/Main/GameService.h"
#include"../../Header/Graphic/GraphicService.h"
#include"../../Header/Event/EventService.h"
#include"../../Header/Global/ServiceLocator.h"

using namespace Global;
namespace Main {

	GameState GameService::current_state = GameState::BOOT;
		GameService::GameService() {
			service_locator = nullptr;
			game_window = nullptr;
		}


		GameService::~GameService() {
			destroy();
		}


		void GameService::ignite() {
			service_locator = ServiceLocator::getInstance();
			initialize();
		}

		void GameService::showMainMenu()
		{
			setGameState(GameState::MAIN_MENU);
		}

		void GameService::initialize()
		{
			service_locator->initialize();
			initializeVariables();
			showMainMenu();
		}

		void GameService::initializeVariables()
		{
			game_window = service_locator->getGraphicService()->getGameWindow();
		}

		void GameService::destroy()
		{
			// don't need to do anything here for now.
		}


		void GameService::update() {

			service_locator->update();
		}


		void GameService::render() {

			game_window->clear(service_locator->getGraphicService()->getWindowColor());
			service_locator->render();
			game_window->display();
		}


		bool GameService::isRunning() {
			return service_locator->getGraphicService()->isGameWindowOpen();
		}

		void GameService::setGameState(GameState new_state) { current_state = new_state; }

		GameState GameService::getGameState() { return current_state; }
	
}