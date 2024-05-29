#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>


namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
		const float spawn_interval = 2.f;

		std::vector<EnemyController*> enemy_list;
		float spawn_timer;

		void updateSpawnTimer();
		void processEnemySpawn();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);
		void destroy();

	public:

		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}
