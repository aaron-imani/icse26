#include <stdio.h>
#include <string.h>

void solve() {
    char s[1024];
    fgets(s, sizeof(s), stdin);
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    printf("%d\n", len - 2 * ans);
}

int main() {
    solve();
    return 0;
}
// End of Code
