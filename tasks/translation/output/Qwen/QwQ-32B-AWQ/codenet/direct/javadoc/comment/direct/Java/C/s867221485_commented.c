#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char s[N+1];
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(s, N+1, stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove trailing newline if present

    int ans = 0;
    int sha = 0;
    int dot = 0;
    int first = 1;

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = 0;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = 1;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    }

    printf("%d\n", ans + dot);
}

// End of Code
