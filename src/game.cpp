#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      fox(grid_width,grid_height),
      grid_width(grid_width), grid_height(grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}
Game::Game(){};
Game::~Game(){};
Game::Game(const Game &source){
  snake = source.snake;
  food = source.food;
  score = source.score;
};
Game &Game::operator=(const Game &source){
  if(this == &source){
    return *this;
  }
  snake = source.snake;
  food = source.food;
  score = source.score;
  return *this;
};
Game::Game(Game &&source){
  snake = source.snake;
  food = source.food;
  score = source.score;
  
  source.snake = Snake();
 // source.food = SDL_Point();
  source.score = 0;
};
Game &Game::operator=(Game &&source){
  if(this == &source){
    return *this;
  }
  snake = source.snake;
  food = source.food;
  score = source.score;
  
  source.snake = Snake();
  //source.food = SDL_Point();
  source.score = 0;
  return *this;
};
void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, fox);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    x = fmod(x + grid_width, grid_width);
    y = fmod(y + grid_height, grid_height);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  int fox_x = static_cast<int>(fox.x);
  int fox_y = static_cast<int>(fox.y);

  if (snake.SnakeCell(fox_x,fox_y)) {
    snake.alive = false;
    std::cout << "Fox eats Snake" <<std::endl;
    return;
  }

  fox.UpdatePosition();
  snake.Update();
  std::cout << "fox" <<fox.x <<" " <<fox.y <<std::endl;
  
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }