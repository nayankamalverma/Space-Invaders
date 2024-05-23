#include "../../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel()
{
	
}

PlayerModel::~PlayerModel()
{
	
}

void PlayerModel::initialize()
{
	reset();
}

void PlayerModel::reset()
{
	player_state = PlayerState::ALIVE;
	player_position = initial_player_position;
	player_score = 0;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return player_position;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	player_position = position;
}

PlayerState PlayerModel::getPlayerAlive()
{
	return player_state;
}

void PlayerModel::setPlayerAlive(PlayerState state)
{
	player_state = state;
}

int PlayerModel::getPlayerScore()
{
	return player_score;
}

void PlayerModel::setPlayerScore(int score)
{
	player_score = score;
}