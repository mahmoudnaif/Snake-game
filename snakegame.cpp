#include "snakegame.h"
#include <fstream>
//
// Created by mahmo on 4/14/2024.
//
SnakeGame::SnakeGame() {
    reso = Vector2f(800,600);
mainWindow.create(VideoMode(reso.x,reso.y), "Snake", Style::Default);
mainWindow.setFramerateLimit(FPS);
startnewgame();

}

void SnakeGame::loadalllevels() {
    mylevels.clear();
    ifstream file("./levels.txt");
    if(file.is_open()) {
        string x;
        while (getline(file, x)) {
            mylevels.push_back(x);
        }
    }
    file.close();
}

void SnakeGame::loadlevel() {

 ifstream levelO(mylevels[0]);
 if(levelO.is_open()) {
     numofApplesbeforenextlevel=10;
     mylevels.pop_front();
     string line = "";

     for (int r = 0; r < 30; r++) {
         if (getline(levelO, line)) {
             for (int c = 0; c < line.length(); c++) {
                 if (line[c] == 'X') {
                     mywall.emplace_back(Vector2f(20, 20));
                     mywall[mywall.size() - 1].setFillColor(Color::White);
                     mywall[mywall.size() - 1].setPosition(Vector2f((c * 20), (r * 20)));
                 }
             }

         }
     }
 }

 else{

     numofApplesbeforenextlevel=10000;
 }
    levelO.close();

}

void SnakeGame::nextLevel() {
    if(!mylevels.empty()) {
        mywall.clear();
        currentGameState = lastGameState = GameState::running;
        snakeDirection = Directions::RIGHT;
        RenderSnake();
        timeSinceLastMove = Time::Zero;
        numofSectionstobeadded = 0;
        changeDirectionApple();
        speed += 5;
        numofApplesEated=0;
        loadlevel();
    }
}

void SnakeGame::startnewgame() {
    mywall.clear();
    currentGameState = lastGameState = GameState::running;
    speed = 2;
    snakeDirection= Directions::RIGHT;
    RenderSnake();
    timeSinceLastMove= Time::Zero;
    numofSectionstobeadded=0;
    changeDirectionApple();
    loadalllevels();
    loadlevel();
    numofApplesEated=0;


}



void SnakeGame::DrawLoop() {
mainWindow.clear(Color::Black);
mainWindow.draw(myApple.getApple());
for(int i=0; i<snake.size(); i++){

    mainWindow.draw(snake[i].getSnakeSection());

}
for(int i=0; i< mywall.size(); i++){
    mainWindow.draw(mywall[i]);
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

                if(currentGameState== GameState::gameOver){
                    SnakeGame::startnewgame();
                }

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


void SnakeGame::changeDirectionApple(){
    Vector2f appleReso= Vector2f(reso.x/20-2, reso.y/20-2);
    Vector2f newapplelocation;
    bool locationBad;

    do {locationBad= false;
        srand(time(nullptr));

    newapplelocation.x= (float)(1+rand() / ((RAND_MAX +1u) / (int)appleReso.x)) *20;
        newapplelocation.x= (float)(1+rand() / ((RAND_MAX +1u) / (int)appleReso.x)) *20;
    newapplelocation.y= (float)(1+rand() / ((RAND_MAX +1u) / (int)appleReso.y)) *20;
        newapplelocation.y= (float)(1+rand() / ((RAND_MAX +1u) / (int)appleReso.y)) *20;

    for(int i=0; i<snake.size(); i++){
        if(snake[i].getPos().x == newapplelocation.x  && snake[i].getPos().y == newapplelocation.y ){
            locationBad= true;
            break;
        }
    }




    } while(locationBad);
    myApple.changePos(newapplelocation);

}

void SnakeGame::Run() {
Clock clock;
    while(mainWindow.isOpen()){
        Time dt= clock.restart();
        timeSinceLastMove+=dt;
        Inputs();
        if(currentGameState== GameState::paused || currentGameState== GameState::gameOver  ){


            sf::sleep(sf::milliseconds(2));
            continue;
        }



        updateDirection();
        DrawLoop();


    }


}



