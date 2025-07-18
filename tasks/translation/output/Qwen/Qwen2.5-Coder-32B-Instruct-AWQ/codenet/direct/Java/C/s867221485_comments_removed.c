#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    getchar(); // To consume the newline character after the integer

    char s[N + 1];
    fgets(s, sizeof(s), stdin);

    int ans = 0;
    int sha = 0;
    int dot = 0;
    int i = 0;

    while (s[i] != '\0' && i < N) {
        if (s[i] == '#') {
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
            }
            sha++;
        } else if (s[i] == '.') {
            dot++;
        }
        i++;
    }

    if (sha <= dot) {
        ans += sha;
    }

    printf("%d\n", ans + dot);

    return 0;
}
// End of Code
