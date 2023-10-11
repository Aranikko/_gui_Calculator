#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Keyboard Input");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bool is8Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Num8);
        bool isShiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

        if (is8Pressed && isShiftPressed)
        {
            std::cout << "Key * is pressed" << std::endl;
            // Do something when "Shift + 8" is pressed
        }
        else if (is8Pressed)
        {
            std::cout << "Key 8 is pressed" << std::endl;
            // Do something when only the "8" key is pressed
        }

        window.clear();
        window.display();
    }

    return 0;
}