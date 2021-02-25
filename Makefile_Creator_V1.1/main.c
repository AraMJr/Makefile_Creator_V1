
#include "mc_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUIT (":q")

int main(int argc, char *argv[]) {
    // Home directory: C:\Users\Ara\OneDrive\Experiments_(OneDrive)\Makefile_Creator\Makefile_Creator_V1.1
    // Test directory: C:\Users\Ara\OneDrive\CSCI_112_Projects_(OneDrive)\Programs\Program_1

    char* user = "_UNLISTED_";
    int option;
    int strLength = sizeof(char)*128;
    char* out_file_directory = malloc(strLength);
    char* temp = malloc(strLength);
    struct return_values r = {};

    printf("\nChecking arguments...");
    if (argc == 3) {
        printf("\nValid arguments found:\n Program location:\t%s \n Makefile name:\t\t%s_makefile\n",
               argv[1], argv[2]);
    } else {
        printf("\nInvalid arguments entered.\nTerminating program...\n");
        exit(-1);
    }

    strcpy(out_file_directory, argv[1]);
    strcat(out_file_directory, "\\");
    strcat(out_file_directory, argv[2]);
    strcat(out_file_directory, "_makefile");
    if (out_file_directory[0] != argv[1][0]) {
        printf("\nFile error: File discrepancy detected: \n %s, \n %s\nTerminating program...\n",
               argv[1], out_file_directory);
        exit(-2);
    }

    printf("\nWelcome to the makefile creator!");
    boolean valid = TRUE;
    while(valid == TRUE) {
        printf("\n\n%s\n %s\n %s\n %s\n %s\n %s\n%s",
               "Select desired function below.",
               "1. Automatically configure makefile.",
               "2. Manually configure makefile.",
               "3. Change editor name.",
               "4. Print generated file name.",
               "0. Terminate program.",
               "function_");
        scanf(" %s", temp);
        option = strtol(temp, NULL, 10);
        printf("\nUser entered function_%d\n", option);
        switch (option) {
            case 1:
                printf("Running automatic configuration...");
                r = auto_config(argv[1]);
                print_makefile(r, user, out_file_directory, argv[2]);
                break;
            case 2:
                printf("Running manual configuration...");
                r = manual_config(QUIT);
                print_makefile(r, user, out_file_directory, argv[2]);
                break;
            case 3:
                printf("\nCurrent user set to %s.\nEnter desired user name or enter %s to cancel: ",
                       user, QUIT);
                scanf(" %s", temp);
                if (strcmp(temp, QUIT) != 0) {
                    user = malloc(strLength);
                    strcpy(user, temp);
                    printf("\nUser set to %s", user);
                } else {
                    printf("\nCancelling request...");
                }
                break;
            case 4:
                printf("\nPrinting makefile directory...");
                printf("\n %s", out_file_directory);
                break;
            case 0:
                printf("Terminating program...");
                valid = FALSE;
                break;
            default:
                printf("Invalid input.");
                break;
        }
    }
    free(out_file_directory);
    free(temp);
    printf(" goodbye.\n");
    return 0;
}
