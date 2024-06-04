#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global{

	using namespace Main;
	using namespace Graphics;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;
	using namespace Collision;
	using namespace Animation;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		enemy_service = nullptr;
		ui_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
		bullet_service = nullptr;
		collision_service = nullptr;
		animation_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		time_service = new TimeService();
		event_service = new EventService();
		player_service = new PlayerService();
		enemy_service = new EnemyService();	
		ui_service = new UIService();
		element_service = new ElementService();
		gameplay_service = new GameplayService();
		sound_service = new SoundService();
		bullet_service = new BulletService();
		powerup_service = new PowerupService();
		collision_service = new CollisionService();
		animation_service = new AnimationService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(time_service);
		delete(event_service);
		delete(player_service);
		delete(enemy_service);	 
		delete(ui_service);
		delete(gameplay_service);
		delete(enemy_service);
		delete(sound_service);
		delete(bullet_service);
		delete(powerup_service);
		delete(collision_service);
		delete(animation_service);
		graphic_service = nullptr;
		time_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		enemy_service = nullptr;  
		ui_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
		sound_service = nullptr;
		bullet_service = nullptr;
		powerup_service = nullptr;
		collision_service = nullptr;
		animation_service = nullptr;
	}

	void ServiceLocator::initialize()
	{
		event_service->initialize();
		sound_service->initialize();
		time_service->initialize();
		graphic_service->initialize(); 
		ui_service->initialize();
		element_service->initialize();
		gameplay_service->initialize();
		player_service->initialize();
		enemy_service->initialize();
		bullet_service->initialize();
		powerup_service->initialize();
		collision_service->initialize();
		animation_service->initialize();
	}

	void ServiceLocator::update()
	{
		event_service->update();
		time_service->update();
		graphic_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
			bullet_service->update();
			element_service->update();
			powerup_service->update();
			collision_service->update();
			animation_service->update();
		}
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		if(GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			bullet_service->render();
			element_service->render();
			powerup_service->render();
			animation_service->render();
		}
		ui_service->render();
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	UIService* ServiceLocator::getUIService(){
		return ui_service;
	}

	Enemy::EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	Gameplay::GameplayService* ServiceLocator::getGamePlayService()
	{
		return gameplay_service;
	}

	Element::ElementService* ServiceLocator::getElementService()
	{
	   return element_service;
	}

	SoundService* ServiceLocator::getSoundService()
	{
		return sound_service;
	}
	Bullet::BulletService* ServiceLocator::getBulletService()
	{
		return bullet_service;
	}
	Powerup::PowerupService* ServiceLocator::getPowerupService()
	{
		return powerup_service;
	}

	Collision::CollisionService* ServiceLocator::getCollisionService() {
		return collision_service;
	}

	Animation::AnimationService* ServiceLocator::getAnimationService() { return animation_service; }
}