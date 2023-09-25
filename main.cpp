#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

bool Click_check(sf::Vector2i mousePos, sf::FloatRect rectBounds);

int* array_additional(int* numbers, int& capacity, int& size_current, string &stopChar);

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Calculator");

    sf::Font font;
    font.loadFromFile("BebasNeue-Regular.ttf");

    sf::RectangleShape box[16];
    for (int i = 0; i < 16; i++) {
        box[i] = sf::RectangleShape(sf::Vector2f(100, 100));
        box[i].setFillColor(sf::Color::Transparent);

        if (i == 15){
            box[i].setSize(sf::Vector2f(100, 300));
            box[i].setPosition(0 + (100 * 4), window.getSize().y - 100 - 200);
        }else if (i == 10 || i == 11 || i == 12 || i == 13 || i == 14) { 
            box[i].setPosition(0 + (100 * (i - 10)), (window.getSize().y - 100 )- 300);
        }else if (i == 6 || i == 7 || i == 8 || i == 9) { 
            box[i].setPosition(0 + (100 * (i - 6)), (window.getSize().y - 100 )- 200);
        }else if (i == 2 || i == 3 || i == 4 || i == 5){
            box[i].setPosition(0 + (100 * (i-2)), window.getSize().y - 100 - 100);
        }else if (i == 0 || i == 1){
            if (i == 0) {
                box[i].setSize(sf::Vector2f(300, 100));
                box[i].setPosition(0 + (100 * i), window.getSize().y - 100);
            }else{
                box[i].setPosition(0 + (100 * (i+2)), window.getSize().y - 100);
            }
        }
        
    }

    std::string chars[16] = {"0", "/", "1", "2", "3", "*", "4", "5", "6", "-", "7", "8", "9", "+", "C", "="};
    sf::Text texts[16];
    for(int i = 0; i < 16; i++) {
        
        texts[i].setFont(font);
        texts[i].setCharacterSize(50);
        texts[i].setString(chars[i]);

        if (i == 15){
            texts[i].setPosition(box[i].getPosition().x + box[i].getSize().x / 2 - texts[i].getGlobalBounds().width /2,
                                box[i].getPosition().y + box[i].getSize().y / 2.5 + texts[i].getGlobalBounds().height/2);
        }else if (i == 10 || i == 11 || i == 12 || i == 13 || i == 14) {
            texts[i].setPosition(box[i].getPosition().x + box[i].getSize().x / 2 - texts[i].getGlobalBounds().width /2,
                                box[i].getPosition().y + box[i].getSize().y / 5.5 + texts[i].getGlobalBounds().height/2);
        }else if (i == 6 || i == 7 || i == 8 || i == 9) { 
            texts[i].setPosition(box[i].getPosition().x + box[i].getSize().x / 2 - texts[i].getGlobalBounds().width /2,
                                box[i].getPosition().y + box[i].getSize().y / 5.5 + texts[i].getGlobalBounds().height/2);
        }else if (i == 2 || i == 3 || i == 4 || i == 5){
            texts[i].setPosition(box[i].getPosition().x + box[i].getSize().x / 2 - texts[i].getGlobalBounds().width /2,
                                box[i].getPosition().y + box[i].getSize().y / 5.5 + texts[i].getGlobalBounds().height/2);
        }else if (i == 0 || i == 1){
            texts[i].setPosition(box[i].getPosition().x + box[i].getSize().x / 2 - texts[i].getGlobalBounds().width /2,
                                box[i].getPosition().y + box[i].getSize().y / 5.5 + texts[i].getGlobalBounds().height/2);
        }
        
    }

    string nums[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string operators[5] = {"+", "-", "*", "/", "="};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(int i = 0; i < 16; i++) {
                    if (Click_check(mousePos, box[i].getGlobalBounds())) {
                    }
                }
            }
        }

        window.clear();

        for (int i = 0; i < 16; i++) {
            window.draw(box[i]);
        }
        for (int i = 0; i < 16; i++) {
            window.draw(texts[i]);
        }
        
        window.display();
    }

    return 0;
}

bool Click_check(sf::Vector2i mousePos, sf::FloatRect rectBounds) {
    if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        return true;
    } else {
        return false;
    }
}

int* array_additional(int* numbers, int& capacity, int& size_current, string &stopChar) {
    int input;
    numbers = new int[capacity];

    while (true) {
        std::cin >> input;

        if (input == stopChar) {
            break; // Прекращаем ввод, когда введено -1
        }

        // Проверяем, заполнен ли массив, и изменяем размер при необходимости
        if (size_current == capacity) {
            capacity *= 2; // Удваиваем ёмкость
            int* newNumbers = new int[capacity];

            // Копируем существующие элементы в новый массив
            for (int i = 0; i < size_current; i++) {
                newNumbers[i] = numbers[i];
            }

            // Освобождаем старую память и обновляем указатель
            delete[] numbers;
            numbers = newNumbers;
        }

        // Добавляем введённое число в массив
        numbers[size_current] = input;
        size_current++;
    }
    return numbers;
}
