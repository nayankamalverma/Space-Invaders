#include <SFML/Graphics.hpp>
#include "Header/GameService.h"

using namespace std;

class Player
{

    
    int health;
    int movementSpeed;
	int playerScore;
    sf::Vector2f position;
      
    public:

        sf::Texture shipTexture;
        sf::Sprite shipSprite;


    Player(int hp=100,int speed=10): health(hp),movementSpeed(speed)
    {
        playerScore = 0;
    }
    //getter setter
    
    //score
        int getScore(){
            return playerScore;
		}

    void setScore(int sc) {
        playerScore = sc;
    }
    //health
    int getHealth() const {
        return health;
    }

    void setHealth(int hp) {
        health = hp;
    }

    //movement speed
    int getMoveSpeed()
	{
        return movementSpeed;
	}

    void setMoveSpeed(int speed)
	{
        movementSpeed = speed;
	}


    //position
    sf::Vector2f getPlayerPosition()
	{
        return position;
	}
    void setPlayerPosition(sf::Vector2f pos)
    {
        position = pos;
    }


    void takeDamage() {}
    void move(float offSet)
	{
        position.x -= offSet * movementSpeed;
	}
    void shootBullets() {}
};

int main()
{
    /*
    sf::VideoMode const video(1920, 1080);
    
    sf::RenderWindow window(video,"Space Invader",sf::Style::Default);
    sf::Font font;
    font.loadFromFile("assets/fonts/OpenSans.ttf");
    window.setFramerateLimit(60);

    Player player;

    //creating ship sprite
    player.shipTexture.loadFromFile("assets/textures/player_ship.png");
    player.shipSprite.setTexture(player.shipTexture);
    player.setPlayerPosition(sf::Vector2f(900, 870));
    player.shipSprite.setPosition(player.getPlayerPosition());


    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {

        	// Check for window closure
            if (event.type == sf::Event::Closed)  window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(1);
        }
    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(-1);
        }

        // Clear the window
        window.clear();
        player.shipSprite.setPosition(player.getPlayerPosition());
        // Draw your content here

        window.draw(player.shipSprite);
    	// Display what was drawn
        window.display();
        
    }*/

    GameService game_service;

    game_service.ignite();

    while (game_service.isRunning())
    {
        game_service.update();
        game_service.render();
    }

    return 0;
}