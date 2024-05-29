#include "../../header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
    namespace Controller
    {
        using namespace Global;

        UFOController::UFOController(EnemyType type)  :EnemyController(type)   {}

        UFOController::~UFOController()
        {
	        
        }

        void UFOController::initialize()
        {
            EnemyController::initialize();
            enemy_model->setMovementDirection(MovementDirection::LEFT);
        }

        void UFOController::fireBullet()
        {
	        
        }
        Powerup::PowerupType UFOController::getRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
            return static_cast<Powerup::PowerupType>(random_value);
        }
        void UFOController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
                // If the movement direction is LEFT
            case::Enemy::MovementDirection::LEFT:
                moveLeft();
                break;

                // If the movement direction is RIGHT
            case::Enemy::MovementDirection::RIGHT:
                moveRight();
                break;
            }
        }
        void UFOController::moveLeft()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move left
            currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::RIGHT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }
        void UFOController::moveRight()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move right
            currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                // Set movement direction to DOWN and update reference position
                enemy_model->setMovementDirection(MovementDirection::LEFT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }







        
    }
}