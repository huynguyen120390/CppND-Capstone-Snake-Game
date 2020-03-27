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
        Fox(int grid_width,int grid_height);
        bool appear{true};
        bool FoxCell(int x, int y);
        Direction direction = Direction::up;
        float speed{1.0f};
        float x{0};
        float y{0};
        void UpdatePosition();
        void SetFreeze(bool freezed);
        bool GetFreeze();
    private:
        int grid_width, grid_height;
        bool freezed{false};
};

#endif