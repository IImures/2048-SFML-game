//
// Created by Vladyslav Kalinchenko on 05.07.2023.
//

#ifndef INC_2048_BOARD_H
#define INC_2048_BOARD_H

#include <SFML/Graphics.hpp>
#include "Block.h"
#include <iostream>

enum Swipes{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class Board : public sf::Drawable{
public:
    Board(int size);

    void pollEvent(sf::Event event);

    void processSwipe(sf::Vector2i &swipe){
        int x = swipe.x, y = swipe.y;
        if(x > 100){
            moveTo = LEFT;
        }else if(y > 100){
            moveTo = UP;
        }else if(x <= -100){
            moveTo = RIGHT;
        }else if(y <= - 100){
            moveTo = DOWN;
        }
        switch (moveTo) {
            case LEFT:
                std::cout<<" Move to LEFT\n";
                break;
            case UP:
                std::cout<<" Move to UP\n";
                break;
            case RIGHT:
                std::cout<<" Move to RIGHT\n";
                break;
            case DOWN:
                std::cout<<" Move to DOWN\n";
                break;
        }
        moveBlocks();
    }

    //-------------------variables
    int boardSize;
    std::array<std::array<Block*, 5>,5> elems;

private:
    Swipes moveTo;

    void genRandBlocks(){
        int count = rand() % 4 + 2;
        for(int i = 0; i < count; i++){
            int y = rand() % boardSize, x = rand() % boardSize;
            auto block = elems[y][x];
            if(block->getValue() == 0) {
                block->setValue(2);
                std::cout << "x: " << x << " y: " << y << '\n';
            }
            else i--;
        }
    }

    void moveBlocks(){
        switch (moveTo) {
            case RIGHT:
                for(int y = 0; y <= boardSize - 1; y++){
                    for(int x = boardSize - 2; x >= 0; x--){
                        auto selBlock = elems[x][y];
                        if(selBlock->getValue() == 0) continue;
                        auto nextBlock = elems[x + 1][y];
                        int nextPossible = x + 1;
                        while (nextBlock->getValue() == 0 && nextPossible < boardSize - 1){
                            nextPossible++;
                            nextBlock = elems[nextPossible][y];
                        }
                        if(nextBlock->getValue() != 0)
                            while (nextBlock->getValue() != 0 && nextPossible >= 0) {
                                nextBlock = elems[nextPossible--][y];
                            }
                        if(nextBlock->getValue() == 0) {
                            nextBlock->setValue(selBlock->getValue());
                            selBlock->setValue(0);
                        }
                    }
                }
                break;
            case LEFT:
                for(int y = 0; y <= boardSize - 1; y++){
                    for(int x = 1; x <= boardSize - 1; x++){
                        auto selBlock = elems[x][y];
                        if(selBlock->getValue() == 0) continue;
                        auto nextBlock = elems[x - 1][y];
                        int nextPossible = 0;
                        while (nextBlock->getValue() == 0 && nextPossible >= 0){
                            nextBlock = elems[nextPossible][y];
                            nextPossible--;
                        }
                        if(nextBlock->getValue() != 0)
                            while (nextBlock->getValue() != 0 && nextPossible <= boardSize - 1) {
                                nextPossible++;
                                nextBlock = elems[nextPossible][y];
                            }
                        if(nextBlock->getValue() == 0) {
                            nextBlock->setValue(selBlock->getValue());
                            selBlock->setValue(0);
                        }
                    }
                }
                break;
        }
        mergeBlocks();
    }

    void mergeBlocks(){

    }



    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
};


#endif //INC_2048_BOARD_H
