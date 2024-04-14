#include <SFML/Graphics.hpp>
#ifndef HELLO_SFML_APPLE_H
#define HELLO_SFML_APPLE_H
using namespace sf;

class Apple {
private:
    RectangleShape myApple;
public:
    Apple();
    RectangleShape getApple();
    void changePos(Vector2f);


};


#endif //HELLO_SFML_APPLE_H
