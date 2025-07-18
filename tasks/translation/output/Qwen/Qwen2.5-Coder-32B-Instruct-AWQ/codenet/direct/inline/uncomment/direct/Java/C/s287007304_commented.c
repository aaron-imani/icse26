#include <stdio.h>
#include <stdlib.h>

char* readLine() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    if (read == -1) {
        return "Error reading line";
    }
    return line;
}

int main() {
    char* input = readLine();
    int a, b;
    sscanf(input, "%d %d", &a, &b);
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    free(input);
    return 0;
}
// End of Code
