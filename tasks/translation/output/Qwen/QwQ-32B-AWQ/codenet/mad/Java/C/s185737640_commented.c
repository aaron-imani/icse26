#include <stdio.h>
#include <string.h>

int isEvenString(const char *str, int len) {
    if (len % 2 != 0) return 0;
    int half = len / 2;
    return strncmp(str, str + half, half) == 0;
}

int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    int len = strlen(s);

    if (len % 2 == 1) {
        len--;
    } else {
        len -= 2;
    }

    if (len < 0) {
        len = 0;
    }
    s[len] = '\0';

    while (len > 0) {
        if (isEvenString(s, len)) {
            break;
        }
        len -= 2;
        s[len] = '\0';
    }

    printf("%d\n", len);
    return 0;
} // End of Code
