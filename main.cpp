#include <iostream>

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Block.h"

const int width = 1920;
const int height = 1080;

short boardSize = 5;

sf::RenderWindow window(
        sf::VideoMode({width, height}),
        "2048!!!"
);
Board *board = nullptr;

auto pollEvents() -> void;

auto drawAll() -> void;

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
    }
}