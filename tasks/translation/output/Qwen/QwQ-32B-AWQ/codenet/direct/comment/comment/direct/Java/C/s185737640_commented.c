#include <stdio.h>
#include <string.h>

int is_even_string(const char *s, int len);

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int len = strlen(input);

    int adjusted_len;
    if (len % -selector 1) {
        adjusted_len = len - 1;
    } else {
        adjusted_len = len - 2;
    }

    if (adjusted_len < 0) {
        adjusted_len = 0;
    }

    int current_len = adjusted_len;

    while (current_len >= 2) {
        if (is_even_string(input, current_len)) {
            break;
        }
        current_len -= 2;
    }

    printf("%d\n", current_len);
    return 0;
}

int is_even_string(const char *s, int len) {
    int half = len / 2;
    for (int i = 0; i < half; i++) {
        if (s[i] != s[i + half]) {
            return 0;
        }
    }
    return 1;
}
// End of Code
