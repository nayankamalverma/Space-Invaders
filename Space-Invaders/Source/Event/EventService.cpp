#include "../Header/EventService.h"
#include "../Header/ServiceLocator.h"

EventService::EventService()
{
	game_window = nullptr;
}

EventService::~EventService() = default;

void EventService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update()
{
	
}

void EventService::processEvents()
{
    if (isGameWindowOpen()) {
        while (game_window->pollEvent(game_event)) {
            // Check for window closure
            if (gameWindowWasClosed() || hasQuitGame())
            {
                game_window->close();
            }
        }
    }
}

bool EventService::hasQuitGame()
{
	return (pressedEscapeKey());
}

bool EventService::isKeyboardEvent()
{
	return game_event.type == sf::Event::KeyPressed;
}




bool EventService::pressedEscapeKey() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape); }

bool EventService::isGameWindowOpen() { return game_window != nullptr; }

bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

bool EventService::pressedLeftKey(){ return  sf::Keyboard::isKeyPressed(sf::Keyboard::Left); }

bool EventService::pressedRightKey(){ return  sf::Keyboard::isKeyPressed(sf::Keyboard::Right); }