#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
 // SDL_Window *sdl_window;
 // SDL_Renderer *sdl_renderer;   //convert raw pointers to unique pointers
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _sdlWindow;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _sdlRenderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif