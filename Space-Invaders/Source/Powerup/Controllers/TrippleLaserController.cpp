#include "../../Header/Powerup/Controllers/TrippleLaserController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controller
	{	  
		using namespace Global;

		TrippleLaserController::TrippleLaserController(PowerupType type)   : PowerupController(type)
		{
			
		}
		TrippleLaserController::~TrippleLaserController()
		{
			
		}
		void TrippleLaserController::onCollected()
		{
			
		}
		 void TrippleLaserController::applyPowerup()
        {
            ServiceLocator::getInstance()->getPlayerService()->enableTrippleLaser();
        }

	}
}
