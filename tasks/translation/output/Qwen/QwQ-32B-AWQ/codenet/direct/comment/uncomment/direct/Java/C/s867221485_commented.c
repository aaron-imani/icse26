#include <stdio.h>
#include <string.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 1;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    char s[100001];
    if (fgets(s, sizeof(s), stdin) == NULL) return 1;
    s[strcspn(s, "\n")] = '\0';
    int flag = 0;
    int ans = 0;
    int hen = 0;
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
