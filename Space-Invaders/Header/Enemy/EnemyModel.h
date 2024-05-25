#pragma once
#include <SFML/System/Vector2.hpp>

namespace Enemy
{

	class EnemyModel
	{
		sf::Vector2f enemy_position;
		sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);

	public:
		EnemyModel();
		~EnemyModel();

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f pos);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f pos);
	};

}
