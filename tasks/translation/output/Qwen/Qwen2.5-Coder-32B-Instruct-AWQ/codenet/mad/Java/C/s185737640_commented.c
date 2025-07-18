#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isEvenString(const char *s) {
    int len = strlen(s);
    char a[len / 2 + 1];
    char b[len / 2 + 1];
    strncpy(a, s, len / 2);
    a[len / 2] = '\0';
    strcpy(b, s + len / 2);
    return strcmp(a, b) == 0;
}

int main() {
    char S[1000];
    fgets(S, sizeof(S), stdin);
    size_t len = strlen(S);
    if (S[len - 1] == '\n') {
        S[len - 1] = '\0';
        len--;
    }

    if (len % 2 == 1) {
        S[len - 1] = '\0';
        len--;
    } else {
        S[len - 2] = '\0';
        len -= 2;
    }

    for (; len > 0; len -= 2) {
        if (isEvenString(S)) {
            break;
        }
        S[len] = '\0';
    }

    printf("%zu\n", len);
    return 0;
}
// End of Code
