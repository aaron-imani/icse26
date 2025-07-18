#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // consume the newline character

    char s[10001];
    fgets(s, sizeof(s), stdin);

    int ans = 0;
    int sha = 0;
    int dot = 0;
    int first = 1;

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            if (!first) {
                if (sha <= dot) {
                    ans += sha;
                    sha = 0;
                    dot = 0;
                }
            }
            sha++;
            first = 0;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
    }

    printf("%d\n", ans + dot);
    // End of Code
}
