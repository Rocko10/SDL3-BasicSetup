#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

int main (int argc, char *argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Error on init application: %s", SDL_GetError());

        return -1;
    }

    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 500;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_CreateWindowAndRenderer("My game", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_VULKAN, &window, &renderer);

    bool isPlaying = true;
    SDL_Event event;

    SDL_FRect square = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f, 30, 30};

    while (isPlaying) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isPlaying = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &square);

        SDL_RenderPresent(renderer);

    }
    
    return 0;
}

