#include <stdio.h>
#include <string.h>

int isEvenString(const char *s) {
    size_t len = strlen(s);
    size_t half = len / 2;
    return strncmp(s, s + half, half) == 0;
}

int main() {
    char S[1000];
    fgets(S, sizeof(S), stdin);

    // Remove trailing newline
    size_t len = strlen(S);
    if (len > 0 && S[len - 1] == '\n') {
        S[len - 1] = '\0';
        len--;
    }

    // Initial trimming based on parity
    len = strlen(S);
    if (len % 2 == 1) {
        S[len - 1] = '\0';
    } else {
        S[len - 2] = '\0';
    }

    while (strlen(S) > 0) {
        if (isEvenString(S)) {
            break;
        }
        len = strlen(S);
        S[len - 2] = '\0';
    }

    printf("%zu\n", strlen(S));
    return 0;
}
// End of Code
