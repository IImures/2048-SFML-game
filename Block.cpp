//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#include "Block.h"
#include <iostream>

Block::Block(int size, int value) {
    elem = sf::RectangleShape(sf::Vector2f(size, size));
    this->size = size;
    this->value = value;
    text = sf::Text();
    if(!font.loadFromFile("/Users/vladyslavkalinchenko/CLionProjects/2048/Assets/arial.ttf")){
        std::cout<<"Failed to load a font\n";
    }
    text.setFont(font);
    text.setString(std::to_string(value));
    text.setCharacterSize(size - 10);
    text.setFillColor(sf::Color::Black);
}

Block::~Block() {}

void Block::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    target.draw(elem, states);
    if(value != 0) target.draw(text, states);

}

void Block::setFillColor(sf::Color color) {
    elem.setFillColor(color);
}

void Block::setPosition(sf::Vector2f pos) {
    elem.setPosition(pos.x, pos.y);
    float xPos = (pos.x + elem.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
    float yPos = (pos.y + elem.getGlobalBounds().height / 4) - (text.getGlobalBounds().height / 2);
    text.setPosition(xPos , yPos);
}

void Block::checkEvent(sf::Event event) {
    int x = event.mouseButton.x, y = event.mouseButton.y;
    if(
            (x >= elem.getPosition().x && x <= elem.getPosition().x + size) &&
                    (y >= elem.getPosition().y && y <= elem.getPosition().y + size)
    ){
        addNumber();
    }


}

void Block::addNumber() {

    std::cout<<"---------\n";
    if(value == 0) value += 2;
    else value *= 2;

    text.setString(std::to_string(value));


    if(text.getGlobalBounds().width >= 100){
        while (text.getGlobalBounds().width >= 80) {
            text.setCharacterSize(text.getCharacterSize() - 1);
            text.setString(std::to_string(value));
        }
    }

    float xPos = (elem.getPosition().x + elem.getGlobalBounds().width / 2) - (text.getGlobalBounds().width/2 + 5);
    float yPos = (elem.getPosition().y + elem.getGlobalBounds().height / 3) - (text.getGlobalBounds().height/ 2 + 5);

    text.setPosition(xPos , yPos);

    std::cout<< text.getGlobalBounds().width << " " << text.getGlobalBounds().height  << " " << text.getCharacterSize() << '\n';
    std::cout<< elem.getGlobalBounds().width << " " << elem.getGlobalBounds().height << '\n';

}

