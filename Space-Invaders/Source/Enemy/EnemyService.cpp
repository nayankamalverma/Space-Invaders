#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService(){ std::srand(static_cast<unsigned>(std::time(nullptr))); }

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();
		for (EnemyController* enemy : enemy_list) enemy->update();
	}

	void EnemyService::render()
	{
		for (EnemyController* enemy : enemy_list) enemy->render();
	}

	

	void EnemyService::updateSpawnTimer()
	{
		   spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	 void EnemyService::processEnemySpawn()
	 {
		 if (spawn_timer >= spawn_interval)
		 {
			 spawnEnemy();
			 spawn_timer = 0.0f; 
		 }
	 }

	 EnemyController* EnemyService::spawnEnemy()
	 {
		 EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		 enemy_controller->initialize();

		 enemy_list.push_back(enemy_controller);
		 return enemy_controller;
	 }

	 EnemyType EnemyService::getRandomEnemyType()
	 {
		 int randomType = std::rand() % 4;
		 return static_cast<Enemy::EnemyType>(randomType);
	 }

	 EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	 {
		 switch (enemy_type)
		 {
		 case::Enemy::EnemyType::ZAPPER:
			 return new ZapperController(Enemy::EnemyType::ZAPPER);

		 case::Enemy::EnemyType::THUNDER_SNAKE:
				 return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		 case::Enemy::EnemyType::SUBZERO:
			 return new SubzeroController(Enemy::EnemyType::SUBZERO);

		 case::Enemy::EnemyType::UFO:
			 return new UFOController(Enemy::EnemyType::UFO);
		 }
	 }
	 void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	 {
		 enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		 delete(enemy_controller);
	 }

	void EnemyService::destroy()
	{
		for (EnemyController* enemy : enemy_list) delete(enemy);
	}
}
