#include <stdio.h>
#include <string.h>

int is_even_string(const char *s, int len) {
    int half = len / 2;
    return strncmp(s, s + half, half) == 0;
}

int main() {
    char s[10000];
    fgets(s, sizeof(s), stdin);

    // Remove trailing newline
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    int original_len = strlen(s);
    int current_len;

    if (original_len % 2 == 1) {
        current_len = original_len - 1;
    } else {
        current_len = original_len - 2;
    }

    s[current_len] = '\0';

    while (current_len > 0) {
        if (is_even_string(s, current_len)) {
            break;
        }
        current_len -= 2;
        s[current_len] = '\0';
    }

    printf("%d\n", current_len);
    return 0;
}
// End of Code
