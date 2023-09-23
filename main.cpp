#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SG");
    
    sf::Texture texture;
    texture.loadFromFile("img/shape_texture.png");
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}