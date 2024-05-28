#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
            float vertical_travel_distance = 100.f;

            float zapper_rate_of_fire = 3;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();
            void fireBullet() override;

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;
        };
    }
}