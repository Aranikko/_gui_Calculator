#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard Input");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                sf::Keyboard::Key key = event.key.code;
                std::cout << "Key Pressed: " << key << std::endl;
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}