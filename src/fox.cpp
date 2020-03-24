#include "fox.h"
#include <cmath>
#include <iostream>



Fox::Fox(){};
Fox::~Fox(){};
//Fox &Fox::operator=(const Fox &source){};
//Fox(const Fox &source){};
//Fox(const Fox &&source){};
//Fox &Fox::operator=(const Fox &&source){};

void Fox::SelectMove(){
    //direction = moveDirection(engine);
    direction = Fox::Direction::up;
    return direction;
}

void Fox::UpdatePosition(){
    switch (direction) {
        case Direction::up:
        y -= speed;
        break;

        case Direction::down:
        y += speed;
        break;

        case Direction::left:
        x -= speed;
        break;

        case Direction::right:
        x += speed;
        break;
    }
}

bool Fox::FoxCell(int x, int y) {
  if (x == static_cast<int>(this->x) && y == static_cast<int>(this->y)) {
    return true;
  }
  return false;
}