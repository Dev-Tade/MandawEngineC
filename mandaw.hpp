#pragma once

#include <SDL2/SDL.h>

namespace mandaw
{
    class Mandaw
    {
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
        ~Mandaw();
        
        void CreateWindow(const char* title, int width, int height);
        void loop();
        void update(double delta_time);
        void draw();
    };
}
