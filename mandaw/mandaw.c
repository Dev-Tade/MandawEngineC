#include <SDL2/SDL.h>
#include "mandaw.h"

#include <string.h>

struct Mandaw_Core
{
    SDL_Window *window;
    SDL_Renderer *renderer; 
    SDL_Event event;
};

struct Mandaw_Window
{
    char *title;
    int width;
    int height;
};

void error(const char *m)
{
    printf("Error: %s\n", m);
    exit(1);
}

Mandaw_Core *mandaw_core_alloc(void)
{
    Mandaw_Core *core = (Mandaw_Core *)malloc(sizeof(Mandaw_Core));
    memset(core, 0, sizeof(Mandaw_Core));

    return core;
}

void mandaw_core_free(Mandaw_Core *core)
{
    free(core);
}

Mandaw_Window *mandaw_window_alloc(void)
{
    Mandaw_Window *window = (Mandaw_Window *)malloc(sizeof(Mandaw_Window));
    memset(window, 0, sizeof(window));

    return window;
}

void mandaw_window_free(Mandaw_Window *window)
{
    free(window);
}

void mandaw_core_init(Mandaw *mandaw)
{
    mandaw->core->window = SDL_CreateWindow(
        mandaw->window->title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        mandaw->window->width, mandaw->window->height,
        SDL_WINDOW_SHOWN
    );

    if (mandaw->core->window == NULL) error("Window");

    mandaw->core->renderer = SDL_CreateRenderer(mandaw->core->window, -1, 0);

    if (mandaw->core->renderer == NULL) error("Renderer");
}

void mandaw_core_poll_events(Mandaw_Core *core)
{
    SDL_PollEvent(&core->event);
}

void mandaw_init(Mandaw *mandaw, char *title, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    mandaw->is_running = true;

    mandaw->window = mandaw_window_alloc();
    mandaw->window->title = title;
    mandaw->window->width = width;
    mandaw->window->height = height;

    mandaw->core = mandaw_core_alloc();
    mandaw_core_init(mandaw);
}

void mandaw_run(Mandaw *mandaw) {
    mandaw->is_running = true;

    while (mandaw->is_running)
    {
        switch (mandaw->core->event.type)
        {
            case SDL_QUIT:
                mandaw->is_running = false;
                break;
        }

        mandaw->at_update(mandaw, 0, mandaw->user_data);
        mandaw->at_draw(mandaw, mandaw->user_data);

        SDL_RenderClear(mandaw->core->renderer);
        SDL_RenderPresent(mandaw->core->renderer);

        mandaw_core_poll_events(mandaw->core);
    }

    SDL_DestroyRenderer(mandaw->core->renderer);
    SDL_DestroyWindow(mandaw->core->window);

    mandaw_window_free(mandaw->window);
    mandaw_core_free(mandaw->core);

    SDL_Quit();
}
