#pragma once

#include "PlayerModel.h"
#include "PlayerView.h"

class PlayerController
{
	PlayerModel* player_model;
	PlayerView* player_view;

	void processPlayerInput();
	void move(float offsetX);

public:
	PlayerController();
	~PlayerController();

	void initialize();
	void update();
	void render();

	sf::Vector2f getPlayerPosition();
};
