﻿#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include<algorithm>
#include <iostream>

namespace Player
{
	using namespace Global;

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
		Event::EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			move(-1);
		}
		// we will move this to event service at a later time
		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			move(1);
		}
		if (event_service->pressedLeftMouseButton())  fireBullet();
	}
	 void PlayerController::fireBullet()
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER_BULLET,
		                                                                       player_model->getPlayerPosition() + player_model->barrel_position_offset,
		                                                                       Bullet::MovementDirection::UP);
	}
	void PlayerController::move(float offsetX)
	{
		sf::Vector2f currentPos = player_model->getPlayerPosition();
		currentPos.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime() * offsetX;

		if (offsetX > 0) currentPos.x = std::min(currentPos.x, player_model->screen_right_bound.x);
		else currentPos.x = std::max(currentPos.x, player_model->screen_left_bound.x);

		player_model->setPlayerPosition(currentPos);
	}
}