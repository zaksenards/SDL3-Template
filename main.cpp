#include <cstdlib>
#include <cstdio>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define APP_TITLE "Lifez"

struct Window
{
    uint32_t id;
    bool shouldClose;
    SDL_Window* canvas;
    SDL_Renderer* renderer;
};

int main()
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Can't initialize SDL: %s\n",SDL_GetError());
        return -1;
    }

    Window* window = new Window;
    window->shouldClose = false;
    // https://wiki.libsdl.org/SDL3/SDL_CreateWindow
    window->canvas = SDL_CreateWindow(APP_TITLE, 600, 600, 0);
    if(!window->canvas){
        fprintf(stderr, "Can't initialize SDL -> Window: %s\n", SDL_GetError());
        return -1;
    }
    window->id = SDL_GetWindowID(window->canvas);

    SDL_Event event;
    //https://wiki.libsdl.org/SDL3/SDL_Event
    while(!window->shouldClose)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            //https://wiki.libsdl.org/SDL3/SDL_KeyboardEvent
            case SDL_EVENT_KEY_DOWN:
                window->shouldClose = (event.key.key == SDLK_Q);
                break;
            case SDL_EVENT_QUIT:
                window->shouldClose = true;
                break;
        }

        SDL_UpdateWindowSurface(window->canvas);
    }

    SDL_DestroyWindow(window->canvas);
    return 0;
}
