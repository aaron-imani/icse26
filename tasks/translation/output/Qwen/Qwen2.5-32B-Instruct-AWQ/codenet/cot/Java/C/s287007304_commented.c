#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* readLine() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    return strdup(buffer);
}

int main() {
    char* line = readLine();
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
