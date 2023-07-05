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
    text.setCharacterSize(size);
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

void Block::setPosition(float x, float y) {
    elem.setPosition(x, y);
    text.setPosition(x + size/6,y - size/6);
}

void Block::checkEvent(sf::Event event) {
    int x = event.mouseButton.x, y = event.mouseButton.y;
    std::cout<<x << " " << y << '\n';
    if(
            (x >= elem.getPosition().x && x <= elem.getPosition().x + size) &&
                    (y >= elem.getPosition().y && y <= elem.getPosition().y + size)
    ){
        if(value == 0) value += 2;
        else value *= 2;
    }
    text.setString(std::to_string(value));

}

