#pragma once
#include "Player/PlayerController.h"

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
