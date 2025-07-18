#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isEvenString(char *s) {
    int len = strlen(s);
    char *a = malloc((len/2 + 1) * sizeof(char));
    char *b = malloc((len/2 + 1) * sizeof(char));
    strncpy(a, s, len/2);
    a[len/2] = '\0';
    strcpy(b, s + len/2);
    int result = strcmp(a, b) == 0;
    free(a);
    free(b);
    return result;
}

int main() {
    char S[1000];
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0'; // Remove newline character

    int len = strlen(S);
    if (len % 2 == 1) {
        S[len - 1] = '\0';
    } else {
        S[len - 2] = '\0';
    }

    while (strlen(S) > 0) {
        if (isEvenString(S)) {
            break;
        }
        S[strlen(S) - 2] = '\0';
    }

    printf("%lu\n", strlen(S));
    return 0;
}
// End of Code
