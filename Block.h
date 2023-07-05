//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#ifndef INC_2048_BLOCK_H
#define INC_2048_BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::Drawable {
public:
    Block(int size, std::string text);
    ~Block();

    void setFillColor(sf::Color color);

    void setPosition(float x, float y);

private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    int size;
    int value;
    sf::RectangleShape elem;
    std::string text;
};


#endif //INC_2048_BLOCK_H
