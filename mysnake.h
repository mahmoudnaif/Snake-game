#include <SFML/Graphics.hpp>
#ifndef HELLO_SFML_MYSNAKE_H
#define HELLO_SFML_MYSNAKE_H

using namespace sf;
class mysnake {
private:
    Vector2f pos;
    RectangleShape snakeSection;

public:

    mysnake(Vector2f startPos);

    Vector2f getPos();

    void setPos(Vector2f newPos);

    RectangleShape getSnakeSection();

    void changepos();


};


#endif //HELLO_SFML_MYSNAKE_H
