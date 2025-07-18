#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char s[1024];
    fgets(s, N + 1, stdin);

    int ans = 0, sha = 0, dot = 0, first = 1;

    for (int i = 0; i < N; i++) {
        char c = s[i];
        if (c == '#') {
            first = 0;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = 1;
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
    }

    printf("%d\n", ans + dot);
    return 0;
}
// End of Code
