#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}


void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();
	// Handle keyboard input
	if (event_service->pressedLeftKey()) {
		move(-1.0f);
	}
	if (event_service->pressedRightKey()) {
		move(1.0f );
	}
}


void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::move(float offSetX)
{
	position.x+= offSetX * movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}


int PlayerService::getMoveSpeed(){	return movement_speed;}
sf::Vector2f PlayerService::getPlayerPosition() { return position; }