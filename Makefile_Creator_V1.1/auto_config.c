
#include "mc_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

struct return_values auto_config(char* file_directory) {
    int strLength = sizeof(char)*128;
    char** file_list = malloc(strLength);
    char* current;
    int counter = 0;
    struct dirent *dir;
    DIR* file = opendir(file_directory);

    if(file) {
        while ((dir = readdir(file)) != NULL) {
            current = dir->d_name;
            if (current[strlen(current) - 1] == 'c' && current[strlen(current) - 2] == '.') {
                file_list[counter] = malloc(strLength);
                strcpy(file_list[counter], current);
                if (counter < 1) {
                    printf("\n\nDetected: ");
                }
                printf("%s ", file_list[counter]);
                counter++;
            }
        }
        closedir(file);
    } else {
        printf("\nInvalid path specified\nTerminating program...\n");
        exit(-4);
    }
    struct return_values r = {file_list, counter};
    return (r);
}
