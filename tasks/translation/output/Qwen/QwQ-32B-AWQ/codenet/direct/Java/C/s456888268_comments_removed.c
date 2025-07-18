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
    char s[100001];
    scanf("%s", s);
    solve(s);
    return 0;
}
// End of Code
