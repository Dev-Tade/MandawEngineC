#include "mandaw.h"

void initMandaw(Mandaw mandaw, char* title, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);

    mandaw.running = true;

    mandaw.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    mandaw.renderer = SDL_CreateRenderer(mandaw.window, -1, 0);
}

void loop(Mandaw mandaw) {
    mandaw.running = true;

    while(mandaw.running) {
        while(SDL_PollEvent(&mandaw.event) != 0) {
            switch(mandaw.event.type) {
                case SDL_QUIT:
                    mandaw.running = false;
                case SDL_KEYDOWN:
                    if(mandaw.event.key.keysym.sym == SDLK_ESCAPE) 
                        mandaw.running = false;
            }
        }

        SDL_RenderClear(mandaw.renderer);
        SDL_RenderPresent(mandaw.renderer);
    }

    if(mandaw.running == false) {
        SDL_DestroyRenderer(mandaw.renderer);
        SDL_DestroyWindow(mandaw.window);
        SDL_Quit();
    }
}
