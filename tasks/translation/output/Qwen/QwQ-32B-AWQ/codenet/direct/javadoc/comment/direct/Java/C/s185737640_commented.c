#include <stdio.h>
#include <string.h>

static int isEvenString(const char *str, int len) {
    int half = len / 2;
    return strncmp(str, str + half, half) == 0;
}

int main() {
    char buffer[100001];
    fgets(buffer, sizeof(buffer), stdin);

    // Remove trailing newline
    char *newline = strchr(buffer, '\n');
    if (newline) {
        *newline = '\0';
    }
    int len = strlen(buffer);

    // Initial trimming
    if (len % 2 == 1) {
        len -= 1;
    } else {
        len -= 2;
    }
    if (len < 0) {
        len = 0;
    }
    buffer[len] = '\0'; // Truncate to new length

    int current_len = len;
    while (current_len > 0) {
        if (isEvenString(buffer, current_len)) {
            break;
        }
        current_len -= 2;
    }

    printf("%d\n", current_len);
    return 0;
}
// End of Code
