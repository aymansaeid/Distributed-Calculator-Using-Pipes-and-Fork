#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Result not provided\n");
        exit(1);
    }

    // getting the result from the argument passed by the child process
    const char *result = argv[1];

    
    FILE *file = fopen("results.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

   
    fprintf(file, "%s\n", result);

    fclose(file);

    return 0;
}
