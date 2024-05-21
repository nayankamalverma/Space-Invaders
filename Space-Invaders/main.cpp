#include <SFML/Graphics.hpp>
#include <iostream>
#include <__msvc_filebuf.hpp>

using namespace std;

class Player
{

    int playerScore;
    int health;
    int movementSpeed;
    sf::Vector2f position;
      
    public:

        sf::Texture shipTexture;
        sf::Sprite shipSprite;

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
    void move()
	{
        cout << "move";
	}
    void shootBullets() {}
};

int main()
{
    sf::VideoMode const video(1920, 1080);
    
    sf::RenderWindow window(video,"Space Invader",sf::Style::Default);
    sf::Font font;
    font.loadFromFile("assets/fonts/OpenSans.ttf");
    window.setFramerateLimit(60);

    Player player;

    //creating ship sprite
    player.shipTexture.loadFromFile("assets/textures/player_ship.png");
    player.shipSprite.setTexture(player.shipTexture);
    player.setPlayerPosition(sf::Vector2f(900, 500));
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
            player.move();
        }
    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move();
        }

        // Clear the window
        window.clear(sf::Color::Blue);
        // Draw your content here
        window.draw(player.shipSprite);
        // Display what was drawn
        window.display();
    }
    return 0;
}