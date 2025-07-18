#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    char s[N+1];
    fgets(s, N+1, stdin);
    
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
            if (first == 0) {
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
