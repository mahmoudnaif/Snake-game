#include "snakegame.h"
//
// Created by mahmo on 4/14/2024.
//
SnakeGame::SnakeGame() {
    Vector2f reso = Vector2f(800,600);
mainWindow.create(VideoMode(reso.x,reso.y), "Snake", Style::Default);
mainWindow.setFramerateLimit(FPS);

 speed = 2;
 snakeDirection= Directions::RIGHT;
    RenderSnake();
    timeSinceLastMove= Time::Zero;
}



void SnakeGame::DrawLoop() {
mainWindow.clear(Color::Black);

for(int i=0; i<snake.size(); i++){

    mainWindow.draw(snake[i].getSnakeSection());

}


mainWindow.display();
}


void SnakeGame::Inputs() {
Event events{};

while(mainWindow.pollEvent((events))){
    switch (events.type) {

        case Event::Closed:
            mainWindow.close();
            break;
        case Event::KeyPressed: {

            switch (events.key.code) {

                case Keyboard::Escape:
                    mainWindow.close();
                    break;
                case Keyboard::Up:
                    addDirections(Directions::UP);
                    break;
                case Keyboard::Down:
                    addDirections(Directions::DOWN);
                    break;
                case Keyboard::Right:
                    addDirections(Directions::RIGHT);
                    break;
                case Keyboard::Left:
                    addDirections(Directions::LEFT);
                    break;
            }



        }
            break;



    }

}

}


void SnakeGame::RenderSnake() {
    snake.clear();

    snake.emplace_back(Vector2f(100, 100));
    snake.emplace_back(Vector2f(80, 100));
    snake.emplace_back(Vector2f(60, 100));


}

void  SnakeGame::SnakeAdd() {

    snake.emplace_back( snake[snake.size()-1].getPos());

}

void SnakeGame::addDirections(int newDirection) {
    if(directionQueue.empty()){
        directionQueue.emplace_back(newDirection);
    }
    else if(directionQueue.back() != newDirection){
        directionQueue.emplace_back(newDirection);
    }
}
void SnakeGame::Run() {
Clock clock;
    while(mainWindow.isOpen()){
        Time dt= clock.restart();
        timeSinceLastMove+=dt;
        Inputs();
        updateDirection();
        DrawLoop();


    }


}



