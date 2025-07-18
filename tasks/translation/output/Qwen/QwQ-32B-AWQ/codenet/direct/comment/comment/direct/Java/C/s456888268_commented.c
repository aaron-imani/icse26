#include <stdio.h>
#include <string.h>

void solve() {
    char s[1000001];
    if (fgets(s, sizeof(s), stdin) == NULL) return;
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }
    int n = (int)len;
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    printf("%d\n", n - 2 * ans);
}

int main() {
    solve();
    return 0;
}

// End of Code
