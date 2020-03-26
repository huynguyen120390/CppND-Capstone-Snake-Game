#include "superfood.h"

SuperFood::SuperFood(){};
SuperFood::~SuperFood(){};
void SupperFood::FreezeSnake(){
    std::unique_lock<std::mutex> ulock(_mutex)
    free = true;
    std::this_thread::sleep_for(std::chrono:milliseconds(3000));
    free = false;
};




  
