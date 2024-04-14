#include "Apple.h"

Apple::Apple() {
    myApple.setSize(Vector2f (20,20));
    myApple.setFillColor(Color::Red);
    myApple.setPosition(Vector2f(400,400));
}

void Apple::changePos(Vector2f newPos) {

    myApple.setPosition(newPos);

}

RectangleShape Apple::getApple() {
    return myApple;
}
