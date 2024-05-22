#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{
    int health = 3;
    sf::Vector2f position = sf::Vector2f(480.0f, 600.0f);
    int movement_speed = 5;
    int player_score = 0;

    const sf::String player_texture_path = "assets/textures/player_ship.png";

    sf::Texture player_texture;
    sf::Sprite player_sprite;

    sf::RenderWindow* game_window;

    void initializePlayerSprite();
    void processPlayerInput();

public:
    PlayerService();
    ~PlayerService();

    void initialize();
    void update();
    void render();

    void move(float offSetX);
    int getMoveSpeed();
    sf::Vector2f getPlayerPosition();
};
