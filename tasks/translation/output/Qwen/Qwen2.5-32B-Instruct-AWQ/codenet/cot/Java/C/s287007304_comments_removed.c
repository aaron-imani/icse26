#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        return strdup(buffer);
    }
    return NULL;
}

int main() {
    char* line = readLine();
    if (line == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    char* token = strtok(line, " ");
    int a = atoi(token);
    token = strtok(NULL, " ");
    int b = atoi(token);
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    free(line);
    return 0;
}
// End of Code
