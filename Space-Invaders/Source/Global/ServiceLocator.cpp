#include"../../Header/Global/ServiceLocator.h"

namespace Global {

	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr;
		Event_service = nullptr;
		Player_ship = nullptr;
		Time_service = nullptr;
		UI_Service = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator() {
		clearAllServices();
	}


	void ServiceLocator::createServices() {
		Time_service = new TimeService();
		Player_ship = new PlayerShip();
		Event_service = new EventService();
		graphic_service = new GraphicService();
		UI_Service = new UIService();
	}

	void ServiceLocator::clearAllServices() {
		delete(graphic_service);
		delete(Event_service);
		delete(Player_ship);
		delete(Time_service);
		delete(UI_Service);
		Player_ship = nullptr;
		Event_service = nullptr;
		graphic_service = nullptr;
		Time_service = nullptr;
		UI_Service = nullptr;
	}


	ServiceLocator* ServiceLocator::getInstance() {
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize() {
		Player_ship->initialize();
		graphic_service->initialize();
		Event_service->initialize();
		Time_service->initialize();
		UI_Service->initialize();
	}


	void ServiceLocator::update() {
		Player_ship->update();
		graphic_service->update();
		Event_service->update();
		Time_service->update();
		UI_Service->update();
	}


	void ServiceLocator::render() {
		graphic_service->render();
		UI_Service->render();
		Player_ship->render();
	}

	TimeService* ServiceLocator::getTimeService() { return Time_service; }
	PlayerShip* ServiceLocator::getPlayerShip() { return Player_ship; }
	EventService* ServiceLocator::getEventService() { return Event_service; }
	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
	UIService* ServiceLocator::getUIService() { return UI_Service; }
}