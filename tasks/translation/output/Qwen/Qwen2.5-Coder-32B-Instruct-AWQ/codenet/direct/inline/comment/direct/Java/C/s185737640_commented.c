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
    char S[1001];
    scanf("%s", S);

    int len = strlen(S);
    if (len % 2 == 1) {
        S[len - 1] = '\0';
    } else {
        S[len - 2] = '\0';
    }

    for (; strlen(S) > 0; ) {
        if (isEvenString(S)) {
            break;
        }
        S[strlen(S) - 2] = '\0';
    }

    printf("%lu\n", strlen(S));
    return 0;
}
// End of Code
