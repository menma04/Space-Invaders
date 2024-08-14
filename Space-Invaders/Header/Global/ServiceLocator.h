#pragma once
#include"../Graphic/GraphicService.h"
#include"../Event/EventService.h"
#include"../Player/PlayerShip.h"
#include"../Time/TimeService.h"

namespace Global {
    using namespace Graphic;
    using namespace Event;
    using namespace Player;
    using namespace Time;
    class ServiceLocator
    {
    private:

        Graphic::GraphicService* graphic_service;
        Event::EventService* Event_service;
        Player::PlayerShip* Player_ship;
        Time::TimeService* Time_service;
        ServiceLocator();

        ~ServiceLocator();


        void createServices();
        void clearAllServices();

    public:

        static ServiceLocator* getInstance();
        void initialize();
        void update();
        void render();

        Time::TimeService* getTimeService();
        Player::PlayerShip* getPlayerShip();
        Event::EventService* getEventService();
        Graphic::GraphicService* getGraphicService();

    };
} 