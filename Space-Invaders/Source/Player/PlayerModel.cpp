#include "../../Header/Player/PlayerModel.h"  
#include "../../header/Entity/EntityConfig.h"

namespace Player
{
	PlayerModel::PlayerModel() { entity_type = Entity::EntityType::PLAYER; }

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize() { reset(); }

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

	int PlayerModel::getPlayerScore()
	{
		return player_score;
	}

	void PlayerModel::setPlayerScore(int score)
	{
		player_score = score;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	Entity::EntityType PlayerModel::getEntityType() {
		return entity_type;
	}
}
