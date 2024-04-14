#include "snakegame.h"


void SnakeGame::updateDirection() {
        if(timeSinceLastMove.asSeconds() >= seconds(1.f/float(speed)).asSeconds()){
            Vector2f firstPOS = snake[0].getPos();
            Vector2f lastPos = firstPOS;

        if(!directionQueue.empty()){
            Directions s = static_cast<Directions>(snakeDirection);
            Directions q =  static_cast<Directions>(directionQueue.front());
            Directions newS,newQ;
            newS = static_cast<Directions>((s+1) % (Directions::LEFT+1));
            newQ = static_cast<Directions>((q+1) % (Directions::LEFT+1));

            if(s==newQ || q == newS){
            snakeDirection= directionQueue.front();
            }
            directionQueue.pop_front();
        }


            switch (snakeDirection) {
            case Directions::RIGHT:
                if(firstPOS.x+20>800){
                    snake[0].setPos(Vector2f(0, firstPOS.y));
                }else {
                    snake[0].setPos(Vector2f(firstPOS.x + 20, firstPOS.y));
                }
                    break;
                case Directions::DOWN:
                    if(firstPOS.y+20>600) {
                        snake[0].setPos(Vector2f(firstPOS.x,0));
                    }
                    else {
                        snake[0].setPos(Vector2f(firstPOS.x, firstPOS.y + 20));
                    }
                    break;
                case Directions::LEFT:
                    if(firstPOS.x-20<0){
                        snake[0].setPos(Vector2f(800, firstPOS.y));
                    }else {
                        snake[0].setPos(Vector2f(firstPOS.x - 20, firstPOS.y));
                    }
                    break;
                case Directions::UP:
                    if(firstPOS.y-20<0){
                        snake[0].setPos(Vector2f(firstPOS.x, 600) );
                    }else {
                        snake[0].setPos(Vector2f(firstPOS.x, firstPOS.y - 20));
                    }
                    break;
        }

        for(int i=1; i<snake.size(); i++){
            firstPOS= snake[i].getPos();
            snake[i].setPos(lastPos);
            lastPos= firstPOS;
        }
            for(int i=0; i<snake.size(); i++){

                snake[i].changepos();
            }


            timeSinceLastMove= Time::Zero;
    }
}
