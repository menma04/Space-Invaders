#include"../../Header/Global/ServiceLocator.h"

namespace Global {

	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr;
		Event_service = nullptr;
		Player_ship = nullptr;
		Time_service = nullptr;
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
	}

	void ServiceLocator::clearAllServices() {
		delete(graphic_service);
		delete(Event_service);
		delete(Player_ship);
		delete(Time_service);
		Player_ship = nullptr;
		Event_service = nullptr;
		graphic_service = nullptr;
		Time_service = nullptr;
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
	}


	void ServiceLocator::update() {
		Player_ship->update();
		graphic_service->update();
		Event_service->update();
		Time_service->update();
	}


	void ServiceLocator::render() {
		Player_ship->render();
		graphic_service->render();
	}

	TimeService* ServiceLocator::getTimeService() { return Time_service; }
	PlayerShip* ServiceLocator::getPlayerShip() { return Player_ship; }
	EventService* ServiceLocator::getEventService() { return Event_service; }
	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

}