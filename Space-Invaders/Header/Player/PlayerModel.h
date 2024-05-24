#pragma once
#include <SFML/System/Vector2.hpp>

namespace Player
{

    enum class PlayerState //Our Enum
    {
        ALIVE,
        DEAD
    };

    class PlayerModel
    {
        const sf::Vector2f initial_player_position = sf::Vector2f(950.0f, 950.0f);
        sf::Vector2f player_position;
        PlayerState player_state;
        int player_score;

    public:

        const float player_movement_speed = 350.0f;
        const sf::Vector2f screen_right_bound = sf::Vector2f(1800.0f, 950.0f);
        const sf::Vector2f screen_left_bound = sf::Vector2f(50.0f, 950.0f);

        PlayerModel();
        ~PlayerModel();

        void initialize();

        void reset(); //new method

        //getters and setters
        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

        PlayerState getPlayerAlive();
        void setPlayerAlive(PlayerState state);
        int getPlayerScore();
        void setPlayerScore(int score);

    };
}