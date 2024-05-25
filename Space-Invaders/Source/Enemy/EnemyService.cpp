#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	EnemyService::EnemyService(){}

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

	 void EnemyService::spawnEnemy()
	 {
		 EnemyController* enemy = new EnemyController();
		 enemy->initialize();

		 enemy_list.push_back(enemy);
	 }

	void EnemyService::destroy()
	{
		for (EnemyController* enemy : enemy_list) delete(enemy);
	}
}
