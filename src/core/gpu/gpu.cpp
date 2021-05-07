#include "gpu.h"

#include <spdlog/spdlog.h>

/**
 * Initialize SDL and GPU timings
 */
void GPU::init() {
    gpu_mode = 2;
    mode_clock = 0;

    // Initialize SDL window and renderer
    window = SDL_CreateWindow("gbemu", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, GPUInfo::SCREEN_WIDTH,
                              GPUInfo::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        spdlog::error("Unable to create window: {}", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        spdlog::error("Unable to create renderer: {}", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_RenderSetLogicalSize(renderer, GPUInfo::SCREEN_WIDTH,
                             GPUInfo::SCREEN_HEIGHT);
    SDL_ShowCursor(SDL_FALSE);

    // Done initializing stuff I guess idk we'll see
}

GPU::~GPU() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}