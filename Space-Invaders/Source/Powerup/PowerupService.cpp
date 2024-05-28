#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	

	 PowerupService::PowerupService()
	 {
		 
	 }

	PowerupService::~PowerupService()
	{
		destroy();
	}
	 PowerupController* PowerupService::createPowerup(PowerupType powerup_type)
	{
		 return new PowerupController(powerup_type);
	}

	 
	 void PowerupService::initialize()
	{
		
	}
	void PowerupService::update()
	{
		
	}
	void PowerupService::render()
	{
		
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{

	}


	void PowerupService::destroy()
	{
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
	}

}
