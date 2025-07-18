#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    char *s = (char *)malloc(1000005 * sizeof(char));
    if (s == NULL) {
        exit(EXIT_FAILURE);
    }
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    free(s);
    printf("%d\n", n - 2 * ans);
}

int main() {
    solve();
    return 0;
}
// End of Code
