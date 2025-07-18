#include <stdio.h>
#include <string.h>

int main() {
    int required[1001];
    for (int i = 0; i <= 1000; i++) {
        required[i] = -1;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (required[s] != -1 && required[s] != c) {
            printf("-1\n");
            return 0;
        }
        required[s] = c;
    }
    for (int num = 0; num <= 999; num++) {
        char s[10];
        sprintf(s, "%d", num);
        int len = strlen(s);
        if (len != n) continue;
        int valid = 1;
        for (int j = 0; j < n; j++) {
            int pos = j + 1;
            int digit = s[j] - '0';
            if (required[pos] != -1) {
                if (digit != required[pos]) {
                    valid = 0;
                    break;
                }
            } else {
                if (digit != 0) {
                    if (j == 0 && digit == 1) {
                        // allowed
                    } else {
                        valid = 0;
                        break;
                    }
                }
            }
        }
        if (valid) {
            printf("%s\n", s);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
// End of Code
