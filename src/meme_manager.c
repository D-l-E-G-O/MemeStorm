#include "meme_manager.h"
#include <dirent.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_MEMES 3

const char* memes[NUM_MEMES];

int load_memes(MemeManager* manager, const char* folder) {
    DIR* dir = opendir(folder);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    struct dirent* entry;
    manager->paths = NULL;
    manager->count = 0;

    while ((entry = readdir(dir)) != NULL) {
        // Ignoring "." and ".."
        if (entry->d_type != DT_REG) continue;

        // Verifying the extension (.png or .jpg)
        const char* ext = strrchr(entry->d_name, '.');
        if (!ext) continue;
        if (strcasecmp(ext, ".png") != 0 && strcasecmp(ext, ".jpg") != 0) continue;

        // Building the full path
        char* fullPath = malloc(strlen(folder) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", folder, entry->d_name);

        // Adding to the list
        manager->paths = realloc(manager->paths, sizeof(char*) * (manager->count + 1));
        manager->paths[manager->count] = fullPath;
        manager->count++;
    }

    closedir(dir);

    if (manager->count == 0) {
        fprintf(stderr, "No memes found in %s\n", folder);
        return -1;
    }

    srand(time(NULL));
    return 0;
}

void free_memes(MemeManager* manager) {
    for (size_t i = 0; i < manager->count; i++) {
        free(manager->paths[i]);
    }
    free(manager->paths);
    manager->paths = NULL;
    manager->count = 0;
}

const char* get_random_meme(MemeManager* manager) {
    if (manager->count == 0) return NULL;
    int index = rand() % manager->count;
    return manager->paths[index];
}