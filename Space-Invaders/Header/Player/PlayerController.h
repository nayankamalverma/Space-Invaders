﻿#pragma once
#include <SFML/System/Vector2.hpp>

//Forward Declarations
enum class PLayerState;
class PlayerView;
class PlayerModel;

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
