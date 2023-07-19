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
        moveBlocks(true);
    }

    //-------------------variables
    int boardSize;
    std::array<std::array<Block*, 5>,5> elems;

private:
    Swipes moveTo;

    void genRandBlocks(){
        int freeBlocks = 0;
        for(auto tab : elems)
            for(auto el : tab)
                if(el->getValue() == 0) freeBlocks++;

        int count = rand() % 4 + 2;
        while (count > freeBlocks) count--;
        //if(freeBlocks == 0) // loose;

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

    void moveBlocks(bool isFrist){
        switch (moveTo) {
            case RIGHT:
                for(int y = 0; y <= boardSize - 1; y++){
                    for(int x = boardSize - 1; x >= 0; x--){
                        if(elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = selBlock;
                        int count = x;
                        while (count < boardSize-1){
                            if(elems[count + 1][y]->getValue() == 0) nextBlock = elems[++count][y];
                            else break;
                        }
                        int val = selBlock->getValue();
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
            case LEFT:
                for(int y = 0; y <= boardSize - 1; y++){
                    for(int x = 0; x <= boardSize - 1; x++){
                        if(elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = selBlock;
                        int count = x;
                        while (count > 0){
                            if(elems[count -1][y]->getValue() == 0) nextBlock = elems[--count][y];
                            else break;
                        }
                        int val = selBlock->getValue();
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
            case UP:

                for(int x = 0; x <= boardSize - 1; x++){
                    for(int y = 0 ; y <= boardSize - 1 ; y++){
                        if(elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = selBlock;
                        int count = y;
                        while (count > 0){
                            if(elems[x][count - 1]->getValue() == 0) nextBlock = elems[x][--count];
                            else break;
                        }
                        int val = selBlock->getValue();
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
            case DOWN:

                for(int x = 0; x <= boardSize - 1; x++) {
                    for (int y = boardSize - 1; y >= 0; y--) {
                        if (elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = selBlock;
                        int count = y;
                        while (count < boardSize - 1) {
                            if (elems[x][count + 1]->getValue() == 0) nextBlock = elems[x][++count];
                            else break;
                        }
                        int val = selBlock->getValue();
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
        }

        if(isFrist) {
            mergeBlocks();
            moveBlocks(false);
            genRandBlocks();
        }
    }

    void mergeBlocks(){
        switch (moveTo) {
            case RIGHT:
                for(int y = 0; y <= boardSize - 1; y++){
                    for(int x = boardSize - 2; x >= 0; x--){
                        if(elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = elems[x + 1][y];
                       if(selBlock->getValue() != nextBlock->getValue()) continue;
                        int val = selBlock->getValue() * 2;
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
            case LEFT:
                for(int y = 0; y <= boardSize - 1; y++){
                    for(int x = 1; x <= boardSize - 1; x++){
                        if(elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = elems[x - 1][y];
                        if(selBlock->getValue() != nextBlock->getValue()) continue;
                        int val = selBlock->getValue() * 2;
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
            case UP:
                for(int x = 0; x <= boardSize - 1; x++){
                    for(int y = 1 ; y <= boardSize - 1 ; y++){
                        if(elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = elems[x][y - 1];
                        if(selBlock->getValue() != nextBlock->getValue()) continue;
                        int val = selBlock->getValue() * 2;
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
            case DOWN:
                for(int x = 0; x <= boardSize - 1; x++) {
                    for (int y = boardSize - 2; y >= 0; y--) {
                        if (elems[x][y]->getValue() == 0) continue;
                        Block *selBlock = elems[x][y];
                        Block *nextBlock = elems[x][y + 1];
                        if(selBlock->getValue() != nextBlock->getValue()) continue;
                        int val = selBlock->getValue() * 2;
                        selBlock->setValue(0);
                        nextBlock->setValue(val);
                    }
                }
                break;
        }
    }



    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
};


#endif //INC_2048_BOARD_H
