//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#ifndef INC_2048_BOARD_H
#define INC_2048_BOARD_H

#include <SFML/Graphics.hpp>
#include "Block.h"

class Board : public sf::Drawable{
public:
    Board(int size);

    void pollEvent(sf::Event event);

    //-------------------variables
public:
    int boardSize;
    std::array<std::array<Block*, 5>,5> elems;

private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
};


#endif //INC_2048_BOARD_H
