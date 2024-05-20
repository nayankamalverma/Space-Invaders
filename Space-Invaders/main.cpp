#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Player
{
    sf::Texture texture;
    sf::Sprite sprite;
    int playerScore;
    int health;
    int movementSpeed;
    sf::Vector2f position;


public:
    void takeDamage() {}
    void move() {}
    void shootBullets() {}
};

int main()
{
    sf::VideoMode const video = *(new sf::VideoMode(1920, 1080));
    
    sf::RenderWindow window(video,"Space Invader",sf::Style::Default);
    sf::Font font;
    font.loadFromFile("assets/fonts/OpenSans.ttf");
    window.setFramerateLimit(60);


    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Clear the window
        window.clear();
        // Draw your content here

        // Display what was drawn
        window.display();
    }
    return 0;
}