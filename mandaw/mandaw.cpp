#include "mandaw.hpp"

using namespace mandaw;

Mandaw::Mandaw(const char* title, int width, int height, int r, int g, int b)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    CreateWindow(title, width, height);
    running = true;
}

Mandaw::~Mandaw()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Mandaw::CreateWindow(const char* title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void Mandaw::loop()
{
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
        
        update(1.0 / 60.0);
        draw();
    }

    if(!running) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

void Mandaw::update(double delta_time)
{

}

void Mandaw::draw()
{
    
}
