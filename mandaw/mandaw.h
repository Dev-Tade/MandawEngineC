#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Mandaw {
    const char* title;
    int width;
    int height;

    bool running;

    SDL_Window *window;
    SDL_Renderer *renderer; 
    SDL_Event event; 
} Mandaw;

extern Mandaw mandaw;

extern void initMandaw(Mandaw mandaw, char* title, int width, int height);
extern void loop(Mandaw mandaw);