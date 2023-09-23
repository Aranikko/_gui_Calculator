#include <SFML/Graphics.hpp>
#include <iostream>

bool Click_check(sf::Vector2i mousePos, sf::FloatRect rectBounds);

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Calculator");

    sf::Font font;
    font.loadFromFile("BebasNeue-Regular.ttf");

    sf::RectangleShape rect(sf::Vector2f(100, 100));
    rect.setPosition(0, window.getSize().y - rect.getSize().y);
    rect.setFillColor(sf::Color::Transparent);

    sf::Text text;
    text.setString("0");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setPosition(
        rect.getPosition().x + rect.getSize().x / 2 - text.getGlobalBounds().width / 2,
        rect.getPosition().y + rect.getSize().y / 2 - text.getGlobalBounds().height / 2
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (Click_check(mousePos, rect.getGlobalBounds())){
                    std::cout << "Left button clicked inside the rectangle!" << std::endl;
                }
            }
        }

        window.clear();
        window.draw(rect);
        window.draw(text);
        window.display();
    }

    return 0;
}

bool Click_check(sf::Vector2i mousePos, sf::FloatRect rectBounds) {
    if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        return true;
    }
    else{
        return false;
    }
}