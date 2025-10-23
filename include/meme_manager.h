#pragma once
#include <stdlib.h>

typedef struct {
    char** paths;
    size_t count;
} MemeManager;

int load_memes(MemeManager* manager, const char* folder);

void free_memes(MemeManager* manager);

const char* get_random_meme(MemeManager* manager);