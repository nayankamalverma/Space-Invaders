#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	event_service = nullptr;
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
	event_service = new EventService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphic_service);
	delete(event_service);
	graphic_service = nullptr;
	event_service = nullptr;
}

void ServiceLocator::initialize()
{
	event_service->initialize();
	graphic_service->initialize();
	
}

void ServiceLocator::update()
{
	event_service->update();
	graphic_service->update();
}

void ServiceLocator::render()
{
	graphic_service->render();
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphic_service;
}

EventService* ServiceLocator::getEventService()
{
	return event_service;
}
