#include <stdio.h>
#include <string.h>

#define MOD 1000000007

void solve() {
    char tmp[100005];
    scanf("%s", tmp);
    char *s = tmp;
    int n = strlen(s);
    int ans = 0;
    int cnt = 0;
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
