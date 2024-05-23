#pragma once

namespace Player
{

    //forward declaration
    class PlayerController;

    class PlayerService
    {
        PlayerController* player_controller;

    public:
        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();

    };
}