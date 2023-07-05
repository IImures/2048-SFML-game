//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#include "Board.h"

Board::Board(int size) : boardSize(size){
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            Block *b = new Block(50, "hello");
            b->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
//            if(j <= 0 && i <= 0 )  b->setPosition(300,150);
//            else b->setPosition(i * 150, j * 140);
            b->setPosition(i * 150 + 1980 / 3, j * 140 + 1080 / 3);
            elems[i][j] = b;

        }
    }
}

void Board::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j <  boardSize; j++){
            target.draw(*elems[i][j], states);
        }
    }
}
//
//void Board::draw(sf::RenderWindow &window) {
//    for(int i = 0; i < boardSize; i++){
//        for(int j = 0; j <  boardSize; j++){
//            window.draw(*elems[i][j]);
//        }
//    }
//}
