#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	static EnemyController* spawn;
	EnemyService::EnemyService()
	{
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawn = spawnEnemy();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}


	void EnemyService::update()
	{
		spawn->update();
	}

	void EnemyService::render()
	{
		spawn ->render();
	}

	void EnemyService::destroy()
	{
		
	}




}
