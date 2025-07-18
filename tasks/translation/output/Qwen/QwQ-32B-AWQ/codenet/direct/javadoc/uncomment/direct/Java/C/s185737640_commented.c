#include <stdio.h>
#include <string.h>

#define MAX 1000001

int isEvenString(const char *s, int len) {
    int half = len / 2;
    return strncmp(s, s + half, half) == 0;
}

int main() {
    char str[MAX];
    fgets(str, MAX, stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[--len] = '\0';
    }

    if (len % 2 != 0) {
        len--;
        str[len] = '\0';
    } else {
        len -= 2;
        str[len] = '\0';
    }

    while (len >= 2) {
        if (isEvenString(str, len)) {
            break;
        }
        len -= 2;
    }

    printf("%d\n", len);
    return 0;
}
// End of Code
