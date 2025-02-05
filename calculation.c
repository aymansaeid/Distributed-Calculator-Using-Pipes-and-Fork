#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void handle_operation(const char *operation) {
    int pipe_parent_to_child[2];//pipes for parent to child to commuicate
    int pipe_child_to_parent[2]; // pipes child to parent to communication
    pid_t pid;
 
    if (pipe(pipe_parent_to_child) == -1 || pipe(pipe_child_to_parent) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        close(pipe_parent_to_child[1]); // close write for pipe_parent_to_child
        close(pipe_child_to_parent[0]); // close read for pipe_child_to_parent

        char input[50];
        read(pipe_parent_to_child[0], input, sizeof(input)); // read input from the parent

        // go to the other files
        if (execl(operation, operation, input, NULL) == -1) {
            perror("execl failed");
            exit(1);
        }
    } else {
        // Parent process
        close(pipe_parent_to_child[0]); // close read of pipe_parent_to_child
        close(pipe_child_to_parent[1]); // close write of pipe_child_to_parent

        int num1, num2;
        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        // send the numbers to the child process using pipe_parent_to_child
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d %d", num1, num2);
        write(pipe_parent_to_child[1], buffer, strlen(buffer) + 1);

        // wait for the result from the child process using pipe_child_to_parent
        char result[50];
        read(pipe_child_to_parent[0], result, sizeof(result));

        
        printf("The result is: ");
        printf("");
        printf("%s\n", result);

        // close pipes
        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);
    }
}

int main() {
    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handle_operation("./sum2numbers");
                break;
            case 2:
                handle_operation("./subtract2numbers");
                break;
            case 3:
                handle_operation("./multiply2numbers");
                break;
            case 4:
                handle_operation("./divide2numbers");
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
