#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

void write_to_pixels(Uint32 *data, Uint32 *pixels)
{
    memcpy(pixels, data, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
}

void blue_interpolation(Uint32 *pixels)
{
    for (int y = 0; y <= SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)

        {
            
        }
    }
}

class Object
{
};

class Sphere : public Object
{
};

class Ray
{
    glm::vec3 origin;
    glm::vec3 direction;
};

int main(int argc, char **argv)
{
    bool leftMouseButtonDown = false;
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("stingray3d",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture *texture = SDL_CreateTexture(renderer,
                                             SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    Uint32 *pixels = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    Uint32 *twelve = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(twelve, 120, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    write_to_pixels(twelve, pixels);

    while (!quit)
    {
        SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));

        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                leftMouseButtonDown = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
                leftMouseButtonDown = true;
        case SDL_MOUSEMOTION:
            if (leftMouseButtonDown)
            {
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                pixels[mouseY * SCREEN_WIDTH + mouseX] = 0;
            }
            break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}