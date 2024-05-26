#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
		EnemyView* enemy_view;
		EnemyModel* enemy_model;

		float vertical_movement_speed;
		float horizontal_movement_speed;

		virtual void move();
		void moveLeft();
		void moveRight();
		void moveDown();
	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

		float getVerticalMovementSpeed();
		void setVerticalMovementSpeed();

		float getHorizontalMovementSpeed();
		void setHorizontalMovementSpeed();
	};
}
