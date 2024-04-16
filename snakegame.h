#include <SFML/Graphics.hpp>
#include <iostream>
#include "mysnake.h"
#include "Apple.h"
#include <vector>
#include <deque>
#include <Windows.h>
using namespace sf;
using namespace std;
#ifndef HELLO_SFML_SNAKEGAME_H
#define HELLO_SFML_SNAKEGAME_H

class SnakeGame{
private:

    Vector2f reso;
    RenderWindow mainWindow;
    int FPS =60;
    const Time timePerF= seconds(1.0/60.0);
    vector<mysnake> snake;
    vector<RectangleShape> mywall;
    deque<string>mylevels;

    deque<int> directionQueue;
    int snakeDirection,speed;
    Time timeSinceLastMove;
    Apple myApple;
    int numofSectionstobeadded;

    int currentGameState, lastGameState;
    int numofApplesEated;
public:
    enum Directions{UP, RIGHT, DOWN, LEFT};
    enum GameState{running, paused, gameOver};
    SnakeGame();
    void nextLevel();
    void loadlevel();
    void startnewgame();
    void loadalllevels();
    void Run();

    void addDirections(int newDirection);
    void updateDirection();
    void changeDirectionApple();


    void DrawLoop();

    void Inputs();

    void RenderSnake();

    void SnakeAdd();

};




#endif //HELLO_SFML_SNAKEGAME_H
