#include <stdio.h>
#include <string.h>

void solve(char *s) {
    int n = strlen(s);
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt > 0) {
                cnt--;
                ans++;
            }
        }
    }
    printf("%d\n", n - 2 * ans);
}

int main() {
    char s[100005];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    solve(s);
    return 0;
}
// End of Code
