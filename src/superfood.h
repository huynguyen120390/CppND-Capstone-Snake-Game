#ifndef SUPERFOOD_H
#define SUPERFOOD_H
#include <mutex>
#include <iostream>
#include <thread>
#include <future>

class SuperFood{
    public:
        SuperFood();
        ~SuperFood()
        void FreezeSnake();
        float x,y;
        bool appear{false};
        bool freeze{false};
    private:
        std::mutex _mutex; 
        std::condition_variable _cond;
        std::deque<bool> _mess;


};
#endif