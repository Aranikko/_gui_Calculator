#include <SFML/Graphics.hpp>

int main()
{
    // Create a window with the Titlebar and Close buttons (but no Resize button)
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fixed Size Window", sf::Style::Titlebar | sf::Style::Close);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
            {
                // If the window is resized, set it back to the fixed size
                window.setSize(sf::Vector2u(800, 600));
            }
        }

        // Your rendering and game logic goes here...

        window.clear();
        // Draw your objects here...
        window.display();
    }

    return 0;
}
