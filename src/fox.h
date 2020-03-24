#ifndef FOXS_H
#define FOXS_H
//  Fox is the predator of snake.
#include <random>
#include <stdlib.h>
#include <time.h>

class Fox{
    public:
        enum class Direction{up,down,left,right};
        Fox();
        ~Fox();
        //Fox(int grid_width,int grid_height);
        //Fox &operator=(const Fox &source);
        //Fox(const Fox &source);
        //Fox(const Fox &&source);
        //Fox &operator=(const Fox &&source);
        bool appear{true};
        bool FoxCell(int x, int y);
        Direction direction = Direction::up;
        float speed{0.1f};
        int size{1};
        bool move{true};
        float x = 0;
        float y = 0;
        void UpdatePosition();
        void SelectMove();
        void Appear();
    private:
        int grid_width, grid_height;
        
        //std::random_device dev;
        //std::mt19937 engine(dev);
        //std::uniform_int_distribution<int> moveDirection(0,3);
        
        
        
};

#endif