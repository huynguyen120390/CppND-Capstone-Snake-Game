#include "superfood.h"

SuperFood::SuperFood(){};
SuperFood::~SuperFood(){};
//SuperFood::SuperFood(int grid_width, int grid_height):grid_width(grid_width), grid_height(grid_height){}

void SuperFood::FreezeFox(Fox &&fox){
    fox.SetFreeze(true);
}

void SuperFood::CheckReleaseFox(Fox &&fox){
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    float elaspedT = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-startT).count();
    if(elaspedT >= FREEZE_TIME){
        fox.SetFreeze(false);
    }else{
        fox.SetFreeze(true);
    }
}
  
