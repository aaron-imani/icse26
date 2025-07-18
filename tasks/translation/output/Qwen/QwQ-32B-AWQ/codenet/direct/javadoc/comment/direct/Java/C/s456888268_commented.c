#include <stdio.h>
#include <string.h>

void solve(const char *s) {
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
    printf("%d\n", n - 2 * ans);
}

int main() {
    char input[100001];
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    solve(input);
    return 0;
}
// End of Code
