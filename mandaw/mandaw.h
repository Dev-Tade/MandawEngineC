#pragma once

// #include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Mandaw_Core Mandaw_Core;
typedef struct Mandaw_Window Mandaw_Window;

typedef struct Mandaw
{
    Mandaw_Window *window;
    Mandaw_Core *core;

    void (*at_update)(struct Mandaw *, float, void *);
    void (*at_draw)(struct Mandaw *, void *);
    void *user_data;

    bool is_running;
} Mandaw;

typedef void (*MandawUpdateHandler) (Mandaw *, float, void *);
typedef void (*ManadwDrawHandler) (Mandaw *, void *);

extern Mandaw mandaw;

extern void mandaw_init(Mandaw *mandaw, char *title, int width, int height);
extern void mandaw_run(Mandaw *mandaw);