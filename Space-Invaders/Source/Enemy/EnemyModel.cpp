#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyModel::EnemyModel()
	{
		
	}

	EnemyModel::~EnemyModel()
	{
		
	}

	void EnemyModel::initialize()
	{
		movement_direction = MovementDirection::RIGHT;
		enemy_position = reference_position;
	}

	void EnemyModel::update()
	{
		
	}

	void EnemyModel::render()
	{
		
	}

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f pos)
	{
		reference_position = pos;
	}

	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f pos)
	{
		enemy_position = pos;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}


}
