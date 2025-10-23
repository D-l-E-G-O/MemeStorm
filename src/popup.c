#include "popup.h"
#include <stdio.h>
#include <stdlib.h>

Popup* popup_create(const char* filepath, int x, int y, int w, int h) {
    Popup* p = (Popup*)malloc(sizeof(Popup));
    if (!p) return NULL;

    // Creating the window
    p->window = SDL_CreateWindow("MemeStorm", x, y, w, h, SDL_WINDOW_SHOWN);
    if (!p->window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        free(p);
        return NULL;
    }

    // Creating the renderer
    p->renderer = SDL_CreateRenderer(p->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!p->renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(p->window);
        free(p);
        return NULL;
    }

    // Loading the image
    SDL_Surface* surface = IMG_Load(filepath);
    if (!surface) {
        printf("IMG_Load Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(p->renderer);
        SDL_DestroyWindow(p->window);
        free(p);
        return NULL;
    }

    p->texture = SDL_CreateTextureFromSurface(p->renderer, surface);
    SDL_FreeSurface(surface);
    p->rect.x = 0;
    p->rect.y = 0;
    p->rect.w = w;
    p->rect.h = h;
    p->open = true;

    return p;
}

void popup_update(Popup* p) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            p->open = false;
        }
    }

    SDL_RenderClear(p->renderer);
    SDL_RenderCopy(p->renderer, p->texture, NULL, &p->rect);
    SDL_RenderPresent(p->renderer);
}

void popup_destroy(Popup* p) {
    if (!p) return;
    SDL_DestroyTexture(p->texture);
    SDL_DestroyRenderer(p->renderer);
    SDL_DestroyWindow(p->window);
    free(p);
}