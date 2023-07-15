#include <iostream>

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Block.h"

const int width = 1920;
const int height = 1080;

short boardSize = 5;

bool swipe = false;
sf::Vector2i mousePosPres;
sf::Vector2i mousePosRel;

sf::RenderWindow window(
        sf::VideoMode({width, height}),
        "2048!!!"
);
Board *board = nullptr;

auto pollEvents() -> void;

auto drawAll() -> void;

auto detectSwipe() ->void;

int main() {
    board = new Board(boardSize);
    while ( window.isOpen() ){

        window.clear();

        pollEvents();

        drawAll();

        window.display();

    }
    return 0;
}

auto drawAll() -> void {
    //board.resize();
    window.draw(*board);
////    sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(20,20));
////    rect.setFillColor(sf::Color(200, 100, 100));
////    rect.setPosition( 200, 110);
//    sf::CircleShape rect = sf::CircleShape(30);
//    rect.setFillColor(sf::Color(200, 100, 100));
//    rect.setPosition( 200, 110);
//    window.draw(rect);
}

auto pollEvents() -> void {
    sf::Event event{};
    while (window.pollEvent(event)){
        if(event.type == sf::Event::Closed) window.close();
        if(event.type == sf::Event::MouseButtonPressed) board->pollEvent(event);
        if(event.type == sf::Event::MouseButtonPressed && sf::Event::MouseMoved) {
            swipe = true;
            int x = event.mouseButton.x, y = event.mouseButton.y;
            mousePosPres = {x,y};
            //std::cout<< x << " " << y << " mouse pressed\n";
        }
        if(event.type == sf::Event::MouseButtonReleased){
            swipe = false;
            int x = event.mouseButton.x, y = event.mouseButton.y;
            mousePosRel = {x,y};
            //std::cout<< x << " " << y << " mouse released\n";
            detectSwipe();
        }
    }
}

auto detectSwipe() ->void{
    std::cout<< mousePosPres.x << " " << mousePosPres.y << " mouse press\n";
    std::cout<< mousePosRel.x << " " << mousePosRel.y << " mouse release\n";
    auto vector = mousePosPres - mousePosRel;
    std::cout<< vector.x << " " << vector.y << " mouse result\n";
    if(vector.x > 100 || vector. x <= -100 || vector.y > 100 || vector.y < -100)
        board->processSwipe(vector);
}