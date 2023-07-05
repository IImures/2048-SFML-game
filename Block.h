//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#ifndef INC_2048_BLOCK_H
#define INC_2048_BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::Drawable {
public:
    Block(int size, int value);
    ~Block();

    void setFillColor(sf::Color color);

    void setPosition(float x, float y);

    void checkEvent(sf::Event event);

private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    int size;
    int value;
    sf::RectangleShape elem;
    sf::Text text;
    sf::Font font;
};


#endif //INC_2048_BLOCK_H
