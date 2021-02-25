
#include "mc_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct return_values manual_config(char* quit) {
    int counter = 0;
    int strLength = sizeof(char)*128;
    char** input_list = malloc(strLength);
    char* current = malloc(strLength);
    char* message = "Enter relevant file names below.";

    printf("\n\nWARNING: Manual configuration does not check directory veracity and will not notify user if "
           "directory is invalid.\n\t Please use automatic configuration if location veracity is uncertain.");

    printf("\n\n%s Enter %s when finished.\n", message, quit);
    while (strcmp(current, quit) != 0) {
        scanf(" %s", current);
        if(strcmp(current, quit) != 0) {
            if(current[strlen(current)-1] != 'c' || current[strlen(current)-2] != '.') {
                printf("Invalid Input: %s not a valid file type\n%s Enter %s when finished.\n",
                       current, message, quit);
            } else {
                printf("Adding %s to makefile...\n", current);
                input_list[counter] = malloc(strLength);
                strcpy(input_list[counter], current);
                counter++;
            }
        }
    }
    struct return_values r = {input_list, counter};
    return (r);
}
