#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	EnemyService::EnemyService()
	{
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}


	void EnemyService::update()
	{
		
	}

	void EnemyService::render()
	{
		
	}

	void EnemyService::destroy()
	{
		
	}




}
