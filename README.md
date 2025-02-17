# SDL3 C++ Basic Setup

[SDL](https://libsdl.org/) is a library for creating games.

This example in C++ shows how to render a square in a window.

![Screenshot From 2025-02-16 21-08-13](https://github.com/user-attachments/assets/e19d959b-137a-45d2-84d3-eb8aad543bf7)


## Installation

Depending on you system you can install it following the instructions of the [official site](https://github.com/libsdl-org/SDL/blob/main/INSTALL.md)

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



