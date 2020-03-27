#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "fox.h"
#include "superfood.h"
#include <future>
#include <mutex>

class Game {
 public:
  Game();
  ~Game();
  Game(std::size_t grid_width, std::size_t grid_height);
  Game(const Game &source);
  Game &operator=(const Game &source);
  Game(Game &&source);
  Game &operator=(Game &&source);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void FreezeFox(std::promise<std::string> &&promise,Fox &&fox);
  void DeadlineTimer();

 private:
  std::mutex _mtx;
  std::thread t;
  Snake snake;
  SDL_Point food;
  Fox fox;
  SuperFood superfood;
  int grid_height,grid_width;
  std::vector<std::thread> threads;;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  bool timeover;
  int time = 2; //sec

  int score{0};

  void PlaceFood();
  void PlaceSuperFood();
  void Update();
  bool isFreezeSnake();
};

#endif