#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {
    static char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        return buffer;
    } else {
        return "Error reading input";
    }
}

int main() {
    char* input = readLine();
    char* token = strtok(input, " ");
    int a = atoi(token);
    token = strtok(NULL, " ");
    int b = atoi(token);
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    // End of Code
    return 0;
}
