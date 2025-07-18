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
                ans++;
                cnt--;
            }
        }
    }
    printf("%d\n", n - 2 * ans);
}

int main() {
    char s[1000005];
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
    }
    solve(s);
    return 0;
}
// End of Code
