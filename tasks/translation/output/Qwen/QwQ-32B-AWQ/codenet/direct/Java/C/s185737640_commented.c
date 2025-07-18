#include <stdio.h>
#include <string.h>

int is_even_string(const char *s, int len) {
    if (len % 2 != 0) return 0;
    int half = len / 2;
    return strncmp(s, s + half, half) == 0;
}

int main() {
    char str[1001];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);

    if (len % 2 == 1) {
        len--;
    } else {
        len -= 2;
    }
    str[len] = '\0';

    while (len > 0) {
        if (is_even_string(str, len)) {
            break;
        }
        len -= 2;
        str[len] = '\0';
    }

    printf("%d\n", len);
    return 0;
} // End of Code
