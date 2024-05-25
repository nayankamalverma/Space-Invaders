#pragma once
#include <SFML/Graphics/RenderWindow.hpp>



namespace Enemy
{
	class EnemyController;

	class EnemyService
	{

		void destroy();
	public:

		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();
	};
}
