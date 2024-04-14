
#include "mysnake.h"

mysnake::mysnake(sf::Vector2f startPos) {
    snakeSection.setSize(Vector2f(20,20));
    snakeSection.setFillColor(Color::Blue);
    snakeSection.setPosition(startPos);
    pos=startPos;

}


Vector2f mysnake::getPos() {
    return pos;
}

RectangleShape mysnake::getSnakeSection() {

    return snakeSection;
}

void mysnake::setPos(sf::Vector2f newPos) {
this->pos= newPos;
}

void mysnake::changepos() {

    snakeSection.setPosition(pos);
}

