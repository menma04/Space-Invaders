#pragma once
#include"GraphicService.h"
#include"EventService.h"
#include"PlayerShip.h"
#include"TimeService.h"

class ServiceLocator
{
private:
    
    GraphicService* graphic_service;
    EventService* Event_service;
    PlayerShip* Player_ship;
    TimeService* Time_service;
    ServiceLocator();
    
    ~ServiceLocator(); 

    
    void createServices(); 			
    void clearAllServices(); 		

public:
    
    static ServiceLocator* getInstance(); 			
    void initialize(); 			
    void update(); 				
    void render(); 				

    TimeService* getTimeService();
    PlayerShip* getPlayerShip();
    EventService* getEventService();
    GraphicService* getGraphicService();

};