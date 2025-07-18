#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    fgets(s, sizeof(s), stdin);
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
        len--;
    }

    int ans = 0, cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt > 0) {
                ans++;
                cnt--;
            }
        }
    }
    printf("%d\n", (int)len - 2 * ans);
    return 0;
}
// End of Code
