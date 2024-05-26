#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
            float vertical_movement_speed =100.0f;

        	void move() override;
            void moveDown();
        public:
            SubzeroController();
            ~SubzeroController();

            void initialize() override;

        };
    }
}