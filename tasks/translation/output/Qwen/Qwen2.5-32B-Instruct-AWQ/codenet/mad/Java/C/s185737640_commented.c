#include <stdio.h>
#include <string.h>

int isEvenString(char *s) {
    int len = strlen(s);
    int halfLen = len / 2;
    for (int i = 0; i < halfLen; i++) {
        if (s[i] != s[i + halfLen]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char S[1000];
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = 0; // Remove newline character

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

    printf("%ld\n", strlen(S));
    // End of Code
}
