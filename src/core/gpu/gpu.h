#pragma once

#include <SDL2/SDL.h>

namespace GPUInfo {
const int SCREEN_WIDTH = 160;
const int SCREEN_HEIGHT = 144;
}  // namespace GPUInfo

class GPU {
   public:
    ~GPU();
    void init();

   private:
    int gpu_mode;
    int mode_clock = 0;

    SDL_Renderer* renderer;
    SDL_Window* window;
};