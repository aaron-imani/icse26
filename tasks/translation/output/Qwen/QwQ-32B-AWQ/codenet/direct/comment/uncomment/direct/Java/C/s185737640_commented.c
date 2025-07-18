#include <stdio.h>
#include <string.h>

int is_even_string(const char *s, int len) {
    int half = len / 2;
    return strncmp(s, s + half, half) == 0;
}

int main() {
    char buffer[1001];
    fgets(buffer, sizeof(buffer), stdin);
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    int adjusted_len;
    if (len % 2 == 1) {
        adjusted_len = len - 1;
    } else {
        adjusted_len = len - 2;
    }

    int max_len = 0;
    for (int current_len = adjusted_len; current_len >= 2; current_len -= 2) {
        if (is_even_string(buffer, current_len)) {
            max_len = current_len;
            break;
        }
    }

    printf("%d\n", max_len);
    return 0;
} // End of Code
