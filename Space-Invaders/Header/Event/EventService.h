#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event{
	class EventService
	{
		sf::Event game_event;
		sf::RenderWindow* game_window;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();

	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();

		//mouse input
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();

		//keyboard input
		bool pressedEscapeKey();
		bool isKeyboardEvent();
		bool pressedLeftKey();
		bool pressedRightKey();

	};
}