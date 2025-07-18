#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        char* line = (char*) malloc((len + 1) * sizeof(char));
        strcpy(line, buffer);
        return line;
    }
    return NULL;
}

int main() {
    char* line = readLine();
    if (line == NULL) {
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
