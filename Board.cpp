//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#include "Board.h"

Board::Board(int size) : boardSize(size){
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            Block *b = new Block(100, 0);
            b->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            b->setPosition( { static_cast<float>(((i * 110 - size * 60) + (1980 / 2))), static_cast<float>((j * 110 - size * 60) + (1080 / 2)) } );
            elems[i][j] = b;
        }
    }
    genRandBlocks();
}

void Board::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j <  boardSize; j++){
            target.draw(*elems[i][j], states);
        }
    }
}

void Board::pollEvent(sf::Event event) {
    for(auto arrBloks : elems)
        for(auto block : arrBloks) block->checkEvent(event);
}
