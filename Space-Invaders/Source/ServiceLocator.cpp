#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	time_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::createServices()
{
	graphic_service = new GraphicService();
	time_service = new TimeService();
	event_service = new EventService();
	player_service = new PlayerService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphic_service);
	delete(time_service);
	delete(event_service);
	delete(player_service);
	graphic_service = nullptr;
	time_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
}

void ServiceLocator::initialize()
{
	event_service->initialize();
	time_service->initialize();
	graphic_service->initialize();
	player_service->initialize();
}

void ServiceLocator::update()
{
	event_service->update();
	time_service->update();
	graphic_service->update();
	player_service->update();
}

void ServiceLocator::render()
{
	graphic_service->render();
	player_service->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
}

TimeService* ServiceLocator::getTimeService()
{
	return time_service;
}

EventService* ServiceLocator::getEventService()
{
	return event_service;
}

PlayerService* ServiceLocator::getPlayerService()
{
	return player_service;
}
