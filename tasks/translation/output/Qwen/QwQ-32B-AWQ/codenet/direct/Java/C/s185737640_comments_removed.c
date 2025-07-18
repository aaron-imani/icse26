#include <stdio.h>
#include <string.h>

int is_even_string(const char *s, int len) {
    if (len % 2 != 0) return 0;
    int half = len / 2;
    return strncmp(s, s + half, half) == 0;
}

int main() {
    char input[1024];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int original_len = strlen(input);
    int initial_len;
    if (original_len % 2 == 1) {
        initial_len = original_len - 1;
    } else {
        initial_len = original_len - 2;
    }

    int current_len = initial_len;
    while (current_len > 0) {
        if (is_even_string(input, current_len)) {
            break;
        }
        current_len -= 2;
    }

    printf("%d\n", current_len);
    return 0;
}
// End of Code
