#include <SFML/Graphics.hpp>
#include <iostream>
#include "mysnake.h"
#include "Apple.h"
#include <vector>
#include <deque>

using namespace sf;
using namespace std;
#ifndef HELLO_SFML_SNAKEGAME_H
#define HELLO_SFML_SNAKEGAME_H

class SnakeGame{
private:
    RenderWindow mainWindow;
    int FPS =60;
    const Time timePerF= seconds(1.0/60.0);
    vector<mysnake> snake;
    deque<int> directionQueue;
    int snakeDirection,speed;
    Time timeSinceLastMove;
    Apple myApple;

public:
    enum Directions{UP, RIGHT, DOWN, LEFT};
    SnakeGame();

    void Run();

    void addDirections(int newDirection);
    void updateDirection();


    void DrawLoop();

    void Inputs();

    void RenderSnake();

    void SnakeAdd();

};




#endif //HELLO_SFML_SNAKEGAME_H
