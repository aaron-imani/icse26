#include <stdio.h>
#include <string.h>

int isEven(char *s, int len);

int main() {
    char S[1000];
    fgets(S, 1000, stdin);

    int len = strlen(S);
    if (len > 0 && S[len-1] == '\n') {
        S[len-1] = '\0';
        len--;
    }

    int current_len;

    if (len % 2 == 1) {
        S[len-1] = '\0';
        current_len = len - 1;
    } else {
        S[len-2] = '\0';
        current_len = len - 2;
    }

    while (current_len > 0) {
        if (isEven(S, current_len)) {
            break;
        }
        current_len -= 2;
        S[current_len] = '\0';
    }

    printf("%d\n", current_len);
    return 0;
}

int isEven(char *s, int len) {
    int half = len / 2;
    return strncmp(s, s + half, half) == 0;
}
// End of Code
