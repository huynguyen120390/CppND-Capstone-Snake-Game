#ifndef SUPERFOOD_H
#define SUPERFOOD_H
#include <iostream>
#include <thread>
#include <future>
#include <deque>
#include <condition_variable>
#include "fox.h"

class SuperFood{
    public:
        SuperFood();
        ~SuperFood();
        //SuperFood(int grid_width, int grid_height);
        void FreezeFox(Fox &&fox);
        void CheckReleaseFox(Fox &&fox);
        float x,y;
        bool appear{false};
        std::chrono::time_point<std::chrono::system_clock> startT; 
    private:
        const int FREEZE_TIME = 3;
        int grid_width,grid_height;

};
#endif