#include <SFML/Graphics.hpp>
int main()
{
    sf::VideoMode const video = *(new sf::VideoMode(800, 600));
    
    sf::RenderWindow* window = new sf::RenderWindow(video,"Hello world",sf::Style::Default);
    sf::Font font;
    font.loadFromFile("assets/fonts/OpenSans.ttf");
    window->setFramerateLimit(60);

    //adding text
    sf::Text text("SFML is Awesome",font,34);
    text.setFillColor(sf::Color::White);


    // Create a green circle
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100, 100); 

    // Create a red square
    sf::RectangleShape square(sf::Vector2f(100, 100)); 
    square.setFillColor(sf::Color::Red);
    square.setPosition(300, 100);

    //loading image
    sf::Texture logoTexture;
    logoTexture.loadFromFile("assets/textures/outscal_logo.png");

    sf::Sprite logoSprite;
    logoSprite.setTexture(logoTexture);

    logoSprite.setPosition(200, 300);
    logoSprite.setRotation(45);
    logoSprite.setScale(0.3, 0.3);

    // Create a blue triangle
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 100));
    triangle.setPoint(1, sf::Vector2f(50, 0));
    triangle.setPoint(2, sf::Vector2f(100, 100));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(500, 100);


    while(window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }
        
        // Clear the window
        window->clear();
        // Draw your content here
        window->draw(text);
        window->draw(circle);
        window->draw(square);
        window->draw(triangle);
        window->draw(logoSprite);

        
        // Display what was drawn
        window->display();
    }
    return 0;
}