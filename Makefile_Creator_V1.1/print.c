
#include "mc_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_makefile(struct return_values r, char* user, char* out_file_directory, char* executable_name) {
    FILE* out_file = fopen(out_file_directory, "w");
    int strLength = sizeof(char)*128;
    time_t t = time(NULL);
    struct tm clock = *localtime(&t);
    char** o_list = malloc(strLength);
    char** file_list = r.file_list;
    int array_length = r.array_length;

    printf("\nCreating makefile...");
    fprintf(out_file, "# Last user: %s\n# Edited: %d:%d, %d/%d/%d\n# \n# File list: ", user,
            clock.tm_hour, clock.tm_min, clock.tm_mon, clock.tm_mday, clock.tm_year + 1900);
    for (int i=0; i<array_length; i++) {
        fprintf(out_file, "%s ", file_list[i]);
    }
    fprintf(out_file, "\n\n%s: ", executable_name);
    for (int i=0; i<array_length; i++) {
        char* temp = malloc(strLength);
        o_list[i] = malloc(strLength);
        strcpy(temp, file_list[i]);
        temp[strlen(temp)-1] = 'o';
        strcpy(o_list[i], temp);
        free(temp);
        fprintf(out_file, "%s ", o_list[i]);
    }
    fprintf(out_file, "\n\tgcc -o %s -Wall ", executable_name);
    for (int i=0; i<array_length; i++) {
        fprintf(out_file, "%s ", o_list[i]);
    }
    fprintf(out_file, "\n\n");
    for (int i=0; i<array_length; i++) {
        fprintf(out_file, "%s: %s\n\tgcc -c %s\n\n", o_list[i], file_list[i], file_list[i]);
    }
    fclose(out_file);
    printf(" done");
}
