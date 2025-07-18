#include <stdio.h>
#include <string.h>

#define MOD 1000000007

void solve() {
    char tmp[1024];
    fgets(tmp, sizeof(tmp), stdin);
    tmp[strcspn(tmp, "\n")] = 0; // Remove newline character
    int n = strlen(tmp);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == 'S') {
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
