#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect rect;
    bool open;
} Popup;

Popup* popup_create(const char* filepath, int x, int y, int w, int h);

void popup_update(Popup* p);

void popup_destroy(Popup* p);