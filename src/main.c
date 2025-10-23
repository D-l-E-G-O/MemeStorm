#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "popup.h"
#include "meme_manager.h"


int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    MemeManager meme_manager;
    if (load_memes(&meme_manager, "assets/") != 0) {
        printf("load_memes Error\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Creating the random popup
    int screenWidth = 800, screenHeight = 600;
    const char* memeFile = get_random_meme(&meme_manager);

    int w = rand() % (screenWidth / 2) + 100;
    int h = rand() % (screenHeight / 2) + 100;
    int x = rand() % (screenWidth - w);
    int y = rand() % (screenHeight - h);

    Popup* popup = popup_create(memeFile, x, y, w, h);
    if (!popup) return EXIT_FAILURE;

    while (popup->open) {
        popup_update(popup);
        SDL_Delay(16); // Every 16 miliseconds -> ~60fps
    }

    popup_destroy(popup);
    IMG_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
