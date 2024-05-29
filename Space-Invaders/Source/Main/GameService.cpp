#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"

namespace Main{

	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;

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
		showMainMenu();

		game_window->setFramerateLimit(frame_rate);
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
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

	GameState GameService::getGameState() { return current_state; }
	void GameService::setGameState(GameState state) { current_state = state; }

	void GameService::showMainMenu()
	{
		setGameState(GameState::MAIN_MENU);
	}

	void GameService::destroy()
	{
		
	}
}

