# SDL3 C++ Basic Setup

[SDL](https://libsdl.org/) is a library for creating games.

This example in C++ shows how to render a square in a window.

![Screenshot From 2025-02-16 21-08-13](https://github.com/user-attachments/assets/e19d959b-137a-45d2-84d3-eb8aad543bf7)


## Installation

Depending on you system you can install it following the instructions of the [official site](https://github.com/libsdl-org/SDL/blob/main/INSTALL.md)

## Basic code
```C++
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
```

## Compiling

Depending on your compiler, you can do it like:

```
g++ main.cpp -lSDL3 -o main
```

## Execute
```
./main
```

## Adding modules

SDL adds features in form of other packages:

Core: [SDL](https://github.com/libsdl-org/SDL): Provides the main functionality.

Images: [SDL_image](https://github.com/libsdl-org/SDL_image): Used to render images.

Fonts: [SDL_ttf](https://github.com/libsdl-org/SDL_ttf): Used to render fonts.

Audio: [SDL_mixer](https://github.com/libsdl-org/SDL_mixer): Used to play music/sounds.

Networking: [SDL_net](https://github.com/libsdl-org/SDL_net): For networking or adding multiplayer functionality.


When using each module you need to also compile it using the proper flags, for example the following compile using the image package:

```
g++ main.cpp -lSDL3 -lSDL3_image -o main
```



