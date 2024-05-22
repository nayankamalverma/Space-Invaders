#pragma once

#include "PlayerService.h"
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"

class ServiceLocator
{
private:
    
    // Private Attributes:
    // - event_service: Manages event-related functionalities.
    // - graphic_service: Handles graphics-related tasks.
    // ..........................
    GraphicService* graphic_service;
    EventService* event_service;
    PlayerService* player_service;
    // ..........................

    ServiceLocator();

    // Destructor for cleaning up resources upon object deletion.
    ~ServiceLocator();

    // Private Methods:
    void createServices(); 			// Creates instances of all services.
    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

public:
    // Public Methods:
    static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders using the services.

    // Methods to Get Specific Services: 
    
    GraphicService* getGraphicService();
    EventService* getEventService();
    PlayerService* getPlayerService();
};