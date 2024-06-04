#pragma once
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Elements/ElementService.h"
#include "../Bullet/BulletService.h"
#include "../Powerup/PowerupConfig.h"
#include "../Powerup/PowerupService.h"
#include "../Sound/SoundService.h"
#include "../../Header/Collision/CollisionService.h"
#include "../../Header/AnimationSystem/AnimationService.h"


namespace Global{

	class ServiceLocator
	{
	private:
	    
	    // Private Attributes:
	    // - event_service: Manages event-related functionalities.
	    // - graphic_service: Handles graphics-related tasks.
	    // ..........................
	    Graphics::GraphicService* graphic_service;
	    Time::TimeService* time_service;
	    Event::EventService* event_service;
	    Player::PlayerService* player_service;
		Enemy::EnemyService* enemy_service;
		Gameplay::GameplayService* gameplay_service;
		Element::ElementService* element_service;
		UI::UIService* ui_service;
		Sound::SoundService* sound_service;
		Bullet::BulletService* bullet_service;
		Powerup::PowerupService* powerup_service;
		Collision::CollisionService* collision_service;
		Animation::AnimationService* animation_service;
		// ..........................

	    ServiceLocator();

	    // Destructor for cleaning up resources upon object deletion.
	    ~ServiceLocator();

	    // Private Methods:
	    void createServices(); 			// Creates instances of all services.
	    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

	public:
	    // Public Methods:
	    static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

	    void initialize(); 			//	Initializes the ServiceLocator.
	    void update(); 				//	Updates all services.
	    void render(); 				//	Renders using the services.

	    // Methods to Get Specific Services: 

	    Graphics::GraphicService* getGraphicService();
	    Time::TimeService* getTimeService();
	    Event::EventService* getEventService();
	    Player::PlayerService* getPlayerService();
		Enemy::EnemyService* getEnemyService();
		UI::UIService* getUIService();
		Element::ElementService* getElementService();
		Gameplay::GameplayService* getGamePlayService();
	    Sound::SoundService* getSoundService();
		Bullet::BulletService* getBulletService();
		Powerup::PowerupService* getPowerupService();
		Collision::CollisionService* getCollisionService();
		Animation::AnimationService* getAnimationService();
	};
}
