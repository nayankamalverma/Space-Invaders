#include "../../Header/Player/PlayerController.h"
#include "../../Header/EventService.h"
#include "../../Header/ServiceLocator.h"
#include<algorithm>

PlayerController::PlayerController()
{
	player_view = new PlayerView();
	player_model = new PlayerModel();
}

PlayerController::~PlayerController()
{
	delete(player_view);
	delete(player_model);
}

void PlayerController::initialize()
{
	player_model->initialize();
	player_view->initialize(this);
}

void PlayerController::update()
{
	processPlayerInput();
	player_view->update();
}

void PlayerController::render()
{
	player_view->render();
}

sf::Vector2f PlayerController::getPlayerPosition()
{
	return player_model->getPlayerPosition();
}

void PlayerController::processPlayerInput()
{
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		move(-1);
	}
	// we will move this to event service at a later time
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		move(1);
	}
}

void PlayerController::move(float offsetX)
{
	sf::Vector2f currentPos = player_model->getPlayerPosition();
	currentPos.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	if (offsetX > 0) currentPos.x = std::min(currentPos.x, player_model->screen_right_bound.x);
	else currentPos.x = std::max(currentPos.x, player_model->screen_left_bound.x);
}