#include <stdio.h>
#include <string.h>

void solve() {
    char s[1000005];
    fgets(s, sizeof(s), stdin);
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n') {
        s[--n] = '\0';
    }
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
    printf("%ld\n", n - 2 * ans);
}

int main() {
    solve();
    return 0;
}
// End of Code
