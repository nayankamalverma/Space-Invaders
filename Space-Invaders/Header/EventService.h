#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService
{
	sf::Event game_event;
	sf::RenderWindow* game_window;

	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool GameWindowWasClosed();
	bool hasQuitGame();

public:
	EventService();
	~EventService();

	void initialize();
	void update();
	void processEvents(); 

	bool pressedEscapeKey();
	bool isKeyboardEvent();
	bool pressedLeftKey();
	bool pressedRightKey();
	
};