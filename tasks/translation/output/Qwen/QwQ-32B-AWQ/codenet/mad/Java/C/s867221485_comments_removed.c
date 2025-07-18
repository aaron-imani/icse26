#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    char s[100001];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    int ans = 0, sha = 0, dot = 0;
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
    return 0;
}
// End of Code
