#include <sdl2/SDL.h>
#include <iostream>
#pragma once

namespace mandaw 
{
    class Mandaw {
    public:
        const char* title;
        int width;
        int height;
        
        bool running;

        int r;
        int g;
        int b;

        SDL_Window* window;
        SDL_Renderer* renderer; 

        SDL_Event event;

        Mandaw(const char* title = "Mandaw!", int width = 800, int height = 600, int r = 0, int g = 0, int b = 0);

        void CreateWindow(const char* title, int width, int height) {
            window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, 0);    
        }

        void update() {
            while(running != false) {
                while(SDL_PollEvent(&event)) {
                    switch(event.type) {
                        case SDL_QUIT:  
                            running = false;
                        case SDL_KEYDOWN:
                            if (event.key.keysym.sym == SDLK_ESCAPE) 
                                running = false;
                    }
                }

                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
            }

            if(!running) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
        }

        int getWidth() { return width; }
        int getHeight() { return height; }
    };

    Mandaw::Mandaw(const char* title, int width, int height, int r, int b, int g) {
        SDL_Init(SDL_INIT_EVERYTHING);
        CreateWindow(title, width, height);
        running = true;
    } 

}