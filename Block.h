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

    void setPosition(sf::Vector2f pos);

    void checkEvent(sf::Event event);

    void setValue(int val){
        value = val;
        text.setString(std::to_string(value));
        resize();
    }
    int getValue(){
        return value;
    }

private:

    void addNumber();

    void resize();

    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    int size;
    int value;
    sf::RectangleShape elem;
    sf::Text text;
    sf::Font font;
};


#endif //INC_2048_BLOCK_H
