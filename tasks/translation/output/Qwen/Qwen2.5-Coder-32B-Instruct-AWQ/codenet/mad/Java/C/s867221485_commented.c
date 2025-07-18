#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);

    getchar(); // To consume the newline character after the integer

    char s[N + 1];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove the newline character from the string

    int ans = 0;
    int sha = 0;
    int dot = 0;
    bool first = true;

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = false;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = true;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
    }

    printf("%d\n", ans + dot);

    return 0;
}
// End of Code
