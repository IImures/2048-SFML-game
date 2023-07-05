//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#include "Block.h"

Block::Block(int size, std::string text) {
    elem = sf::RectangleShape(sf::Vector2f(size, size));
    text = text;
}

Block::~Block() {}

void Block::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    target.draw(elem, states);
}

void Block::setFillColor(sf::Color color) {
    elem.setFillColor(color);
}

void Block::setPosition(float x, float y) {
    elem.setPosition(x, y);
}

