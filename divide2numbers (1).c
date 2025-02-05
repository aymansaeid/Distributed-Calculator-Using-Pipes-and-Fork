#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments\n");
        exit(1);
    }

    int num1, num2;
    sscanf(argv[1], "%d %d", &num1, &num2);

    if (num2 == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(1);
    }

    int result = num1 / num2;

    // print the result (this will be captured by the parent)
    printf("%d\n", result);

    // call the saver program to save the result to the file
    char result_str[50];
    snprintf(result_str, sizeof(result_str), "%d", result);

    // using execl to call saver program and save the result
    execl("./saver", "saver", result_str, NULL);

    perror("execl failed");
    exit(1);
}
