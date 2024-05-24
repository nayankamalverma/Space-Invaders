#include "../../header/Event/EventService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include <iostream>

namespace Event
{

    using namespace Global;

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

                                                 
   

    bool EventService::isGameWindowOpen() { return game_window != nullptr; }    

    bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

    bool EventService::hasQuitGame() { return (isKeyboardEvent() && pressedEscapeKey()); }

    

    //mouse
    bool EventService::pressedLeftMouseButton() { return (game_event.type == sf::Event::MouseButtonPressed) && (game_event.mouseButton.button == sf::Mouse::Left); }

	bool EventService::pressedRightMouseButton()
    {
        return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right;
    }

    //keyboard
    bool EventService::isKeyboardEvent() { return game_event.type == sf::Event::KeyPressed;   }

    bool EventService::pressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }

	bool EventService::pressedLeftKey() { return  sf::Keyboard::isKeyPressed(sf::Keyboard::Left); }

    bool EventService::pressedRightKey() { return  sf::Keyboard::isKeyPressed(sf::Keyboard::Right); }
}