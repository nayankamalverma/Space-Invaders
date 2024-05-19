#include <SFML/Graphics.hpp>
int main()
{
    sf::VideoMode const video = *(new sf::VideoMode(800, 600));
    
    sf::RenderWindow* window = new sf::RenderWindow(video,"Hello world",sf::Style::Default);


    while(window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }
        
        // Clear the window
        window->clear(sf::Color::Blue);
        // Draw your content here
        
        // Display what was drawn
        window->display();
    }
    return 0;
}