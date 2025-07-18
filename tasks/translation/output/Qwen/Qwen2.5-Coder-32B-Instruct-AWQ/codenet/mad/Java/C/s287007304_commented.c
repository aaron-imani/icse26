#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line); // Free the allocated memory if an error occurs
        return NULL; // Return NULL to indicate an error
    }
    return line;
}

int main() {
    char* input = readLine();
    if (input == NULL) {
        fprintf(stderr, "Error reading line\n");
        return 1; // Return a non-zero value to indicate an error
    }
    int a, b;
    if (sscanf(input, "%d %d", &a, &b) != 2) {
        fprintf(stderr, "Invalid input format\n");
        free(input);
        return 1; // Return a non-zero value to indicate an error
    }
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    free(input);
    return 0;
}
// End of Code
