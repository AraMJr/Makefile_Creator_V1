
typedef enum {
    TRUE,
    FALSE,
} boolean;

struct return_values {
    char** file_list;
    int array_length;
};

struct return_values auto_config(char* file_directory);

struct return_values manual_config(char* quit);

void print_makefile(struct return_values r, char* user, char* out_file_directory, char* executable_name);

