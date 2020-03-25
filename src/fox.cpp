#include "fox.h"
#include <cmath>
#include <iostream>



Fox::Fox(){};
Fox::~Fox(){};
Fox::Fox(int grid_width, int grid_height):grid_width(grid_width), grid_height(grid_height){}
//Fox &Fox::operator=(const Fox &source){};
//Fox(const Fox &source){};
//Fox(const Fox &&source){};
//Fox &Fox::operator=(const Fox &&source){};

void Fox::SelectMove(){
    //direction = moveDirection(engine);
    direction = Fox::Direction::up;
}

void Fox::UpdatePosition(){
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> dis(0,3);
    int dir = dis(engine);
    if(dir == 0) direction = Direction::up;
    else if(dir == 1) direction = Direction::down;
    else if(dir == 2) direction = Direction::left;
    else if(dir == 3) direction = Direction::right;
        
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

    x = fmod(x + grid_width, grid_width);
    y = fmod(y + grid_height, grid_height);
}

bool Fox::FoxCell(int x, int y) {
  if (x == static_cast<int>(this->x) && y == static_cast<int>(this->y)) {
    return true;
  }
  return false;
}