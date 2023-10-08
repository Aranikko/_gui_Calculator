#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Click_check(sf::Vector2i mousePos, sf::FloatRect rectBounds);
bool Nums_check(string chars[16], int i);

bool check_keys(sf::Event event);
bool check_nums_keyboard(sf::Event event);

void Calculator_Logic(string chars[16], int &i , sf::Event event, vector<string> &entered_chars, string &text_entered_str, sf::Text &text_entered, vector<int> &solveble);

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 600), "Calculator", sf::Style::Titlebar | sf::Style::Close);

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
    string operators[6] = {"+", "-", "*", "/", "=", "C"};

    vector<string> entered_chars;
    sf::Text text_entered;
    text_entered.setFont(font);
    text_entered.setCharacterSize(50);
    text_entered.setPosition(45, 150);
    text_entered.setString("0");

    vector<int> solveble;

    vector<string> operators_entered;

    string text_entered_str;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }else if (event.type == sf::Event::Resized){

                window.setSize(sf::Vector2u(500, 600));

            }else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(int i = 0; i < 16; i++) {
                    if (Click_check(mousePos, box[i].getGlobalBounds()) || check_keys(event)) {
                 
                        Calculator_Logic(chars, i, event, entered_chars, text_entered_str, text_entered, solveble);

                    }
                }
            }


        }

        window.clear();

        for (int i = 0; i < 16; i++) {
            window.draw(texts[i]);
        }

        for (int i = 0; i < 16; i++) {
            window.draw(box[i]);
        }
        
        window.draw(text_entered);

        window.display();
    }
    
    return 0;
    
}

bool Click_check(sf::Vector2i mousePos, sf::FloatRect rectBounds){
    if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        return true;
    } else {
        return false;
    }
}

bool Nums_check(string chars[16], int i) {

    if (chars[i] == "0" ||
        chars[i] == "1" ||
        chars[i] == "2" ||
        chars[i] == "3" ||
        chars[i] == "4" ||
        chars[i] == "5" || 
        chars[i] == "6" ||
        chars[i] == "7" ||
        chars[i] == "8" ||
        chars[i] == "9" ){

        return true;

       }else{

            return false;

       }

}   

bool check_keys(sf::Event event) {

    sf::Keyboard::Key key = event.key.code;
                // Check which key was pressed
                if (key == sf::Keyboard::Num0 ||
                    key == sf::Keyboard::Num1 ||
                    key == sf::Keyboard::Num2 ||
                    key == sf::Keyboard::Num3 ||
                    key == sf::Keyboard::Num4 ||
                    key == sf::Keyboard::Num5 ||
                    key == sf::Keyboard::Num6 ||
                    key == sf::Keyboard::Num7 ||
                    key == sf::Keyboard::Num8 ||
                    key == sf::Keyboard::Num9 ||
                    key == sf::Keyboard::Add ||
                    key == sf::Keyboard::Subtract ||
                    key == sf::Keyboard::Multiply ||
                    key == sf::Keyboard::Divide ||
                    key == sf::Keyboard::Equal ||
                    key == sf::Keyboard::C){

                        return true;

                    }else{

                        return false;

                    }

}
        
bool check_nums_keyboard(sf::Event event){

    if (event.type == sf::Event::KeyPressed) {

        sf::Keyboard::Key key = event.key.code;
        // Check which key was pressed
        if (key == sf::Keyboard::Num0 ||
            key == sf::Keyboard::Num1 ||
            key == sf::Keyboard::Num2 ||
            key == sf::Keyboard::Num3 ||
            key == sf::Keyboard::Num4 ||
            key == sf::Keyboard::Num5 ||
            key == sf::Keyboard::Num6 ||
            key == sf::Keyboard::Num7 ||
            key == sf::Keyboard::Num8 ||
            key == sf::Keyboard::Num9 ){

                return true;

            }

    }

    return false; // Add this line

}

void Calculator_Logic(string chars[16], int &i , sf::Event event, vector<string> &entered_chars, string &text_entered_str, sf::Text &text_entered, vector<int> &solveble){

    if(Nums_check(chars, i) || check_nums_keyboard(event)) { 
        
        cout << "Pressed" << endl;

        if (entered_chars.size() < 1 
        || entered_chars.back() == "+"
        || entered_chars.back() == "-"
        || entered_chars.back() == "*"
        || entered_chars.back() == "/"){

            entered_chars.push_back(chars[i]);
            text_entered_str += chars[i];

        }else{
                
            entered_chars[0+entered_chars.size()-1] += chars[i];
            text_entered_str += chars[i];

        }
        text_entered.setString(text_entered_str);

    }else{

        if (chars[i] == "C") {

            entered_chars.clear();
            text_entered_str = "";
            text_entered.setString("0");

        }else if (chars[i] == "+") {

            if (entered_chars.back() != "+" 
            && entered_chars.back()!= "-" 
            && entered_chars.back()!= "*"
            && entered_chars.back()!= "/") {

                entered_chars.push_back(chars[i]);
                text_entered_str += " " + chars[i] + " ";
                text_entered.setString(text_entered_str);

            }


        }else if (chars[i] == "-") {

            if (entered_chars.back() != "+" 
            && entered_chars.back()!= "-" 
            && entered_chars.back()!= "*"
            && entered_chars.back()!= "/") {

                entered_chars.push_back(chars[i]);
                text_entered_str += " " + chars[i] + " ";
                text_entered.setString(text_entered_str);

            }

        }else if (chars[i] == "*") {

            if (entered_chars.back() != "+" 
            && entered_chars.back()!= "-" 
            && entered_chars.back()!= "*"
            && entered_chars.back()!= "/") {

                entered_chars.push_back(chars[i]);
                text_entered_str += " " + chars[i] + " ";
                text_entered.setString(text_entered_str);

            }

        }else if (chars[i] == "/") {

            if (entered_chars.back() != "+" 
            && entered_chars.back()!= "-" 
            && entered_chars.back()!= "*"
            && entered_chars.back()!= "/") {

                entered_chars.push_back(chars[i]);
                text_entered_str += " " + chars[i] + " ";
                text_entered.setString(text_entered_str);

            }

        }else{
                
            if(entered_chars.size() >= 3){

                int count = 0;

            for(int j = 0; j < entered_chars.size(); j++){

                if(entered_chars[j] == "+" 
                || entered_chars[j] == "-" 
                || entered_chars[j] == "*" 
                || entered_chars[j] == "/"){

                    count++;

                }

            }

            for(int j = 0; j < count; j++){

                for(int k = 0; k < entered_chars.size(); k++) {

                    if(entered_chars[k] == "+" ){

                        double result = stoi(entered_chars[k-1]) + stoi(entered_chars[k+1]);

                        entered_chars[0] = to_string(result);
                        entered_chars.erase(entered_chars.begin() + 1);
                        entered_chars.erase(entered_chars.begin() + 1);

                    }else if(entered_chars[k] == "-" ){

                        double result = stoi(entered_chars[k-1]) - stoi(entered_chars[k+1]);

                        entered_chars[0] = to_string(result);
                        entered_chars.erase(entered_chars.begin() + 1);
                        entered_chars.erase(entered_chars.begin() + 1);

                    }else if(entered_chars[k] == "*" ){

                        double result = stoi(entered_chars[k-1]) * stoi(entered_chars[k+1]);

                        entered_chars[0] = to_string(result);
                        entered_chars.erase(entered_chars.begin() + 1);
                        entered_chars.erase(entered_chars.begin() + 1);

                    }else if(entered_chars[k] == "/" ){

                        double result = stoi(entered_chars[k-1]) / stoi(entered_chars[k+1]);

                        entered_chars[0] = to_string(result);
                        entered_chars.erase(entered_chars.begin() + 1);
                        entered_chars.erase(entered_chars.begin() + 1);

                    }

                }

            }

            text_entered_str = entered_chars[0];
            text_entered.setString(text_entered_str);


            }else{

                

            }
            
        }

    }

}