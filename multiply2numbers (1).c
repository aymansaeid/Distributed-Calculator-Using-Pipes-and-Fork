#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "error from arguments\n");
        exit(1);
    }

    int num1, num2;
    sscanf(argv[1], "%d %d", &num1, &num2);

    int result = num1 * num2;

    printf("%d\n", result);

    char result_str[50];
    snprintf(result_str, sizeof(result_str), "%d", result);

    execl("./saver", "saver", result_str, NULL);

    perror("execl failed");
    exit(1);
}
