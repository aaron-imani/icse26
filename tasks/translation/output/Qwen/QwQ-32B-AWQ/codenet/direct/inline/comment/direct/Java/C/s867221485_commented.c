#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    char s[N+1];
    fgets(s, N+1, stdin);
    s[strcspn(s, "\n")] = '\0';
    
    int ans = 0, sha = 0, dot = 0;
    int first = 1;
    
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
