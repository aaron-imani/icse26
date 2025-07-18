#include <stdio.h>
#include <string.h>

int is_even_string(const char *str, int len) {
    if (len % 2 != 0) return 0;
    int half = len / 2;
    for (int i = 0; i < half; i++) {
        if (str[i] != str[i + half]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char s[1024];
    fgets(s, sizeof(s), stdin);
    size_t len = strlen(s);
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
    for (; current_len >= 2; current_len -= 2) {
        if (is_even_string(s, current_len)) {
            break;
        }
    }
    printf("%d\n", current_len);
    return 0;
}
// End of Code
