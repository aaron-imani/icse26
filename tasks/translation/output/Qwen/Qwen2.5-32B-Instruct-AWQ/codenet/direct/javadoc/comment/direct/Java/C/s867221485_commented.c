#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // consume newline character

    char s[10001];
    fgets(s, sizeof(s), stdin);

    int ans = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    int first = 1;

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = 0;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = 1;
            } else {
                // do nothing
            }
            sha++;
        } else {
            if (!first) {
                dot++;
            }
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    } else {
        // do nothing
    }

    printf("%d\n", ans + dot); // End of Code
