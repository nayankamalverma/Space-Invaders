#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    enum class EnemyType;
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
            float vertical_movement_speed =100.0f;

            float subzero_rate_of_fire = 3;

        	void move() override;
            void moveDown();
            void fireBullet() override;

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void initialize() override;

        };
    }
}
