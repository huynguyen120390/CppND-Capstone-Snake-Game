#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
    public:
        //Memory Management: Senmantics
        Controller();//contructor 
        ~Controller();//destructor
        Controller(const Controller &source);//copy constructor 
        Controller &operator=(const Controller &source);//copy operator
        Controller(Controller &&source); //move constructor
        Controller &operator=(Controller &&source); //move operator
        void HandleInput(bool &running, Snake &snake) const;
    private:
        void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif