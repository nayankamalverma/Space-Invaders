#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

GameService::GameService()
{
	service_locator = nullptr;
}

GameService::~GameService()
{
	destroy();
}

void GameService::ignite()
{
	service_locator = ServiceLocator::getInstance();
	initialize();
}

void GameService::initialize()
{
	service_locator->initialize();
	initializeVariables();
}

void GameService::initializeVariables()
{
	game_window = service_locator->getGraphicService()->getGameWindow();
}

void GameService::update()
{
	service_locator->update();
}

void GameService::render()
{
	game_window->clear(service_locator->getGraphicService()->getWindowColor());
	service_locator->render();
	game_window->display();
}


bool GameService::isRunning()
{
	// Checks if the game is currently running.
	return service_locator->getGraphicService()->isGameWindowOpen();
}

void GameService::destroy()
{

}

