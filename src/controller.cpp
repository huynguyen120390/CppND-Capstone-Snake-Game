#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

//Mempry Management:Rule of 5
//contructor 
Controller::Controller(){
  std::cout << "Controller Default Constructor" << std::endl;
};
//destructor
Controller::~Controller(){
  std::cout << "Controller Default Destructor" << std::endl;
};
//copy constructor
Controller::Controller(const Controller &source){
  std::cout << "Controller Copy Constructor" << std::endl;
  *this = source;
};
//copy operator
Controller &Controller::operator=(const Controller &source){
  std::cout << "Controller Copy Operator" <<std::endl;
  return *this;
};
//move constructor
Controller::Controller(Controller &&source){
  if(this != &source){
    delete this;
    *this = source;
    //delete source;
  }
}; 
//move operator
Controller &Controller::operator=(Controller &&source){
  if(this == &source){
    return *this;
  }
  delete this;
  *this = source;
  //delete source;
  return *this;
}; 

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}