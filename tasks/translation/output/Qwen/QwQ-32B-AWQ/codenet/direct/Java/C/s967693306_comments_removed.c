#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int required[1001]; // Positions 1-based up to 1000
    for (int i = 1; i <= n; i++) {
        required[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (s < 1 || s > n) {
            printf("-1\n");
            return 0;
        }
        if (required[s] != -1 && required[s] != c) {
            printf("-1\n");
            return 0;
        }
        required[s] = c;
    }
    char sbuf[10];
    for (int num = 0; num <= 999; num++) {
        sprintf(sbuf, "%d", num);
        int len = strlen(sbuf);
        if (len != n) continue;
        int flag = 1;
        for (int j = 0; j < len; j++) {
            int digit = sbuf[j] - '0';
            int pos = j + 1;
            if (required[pos] != -1) {
                if (digit != required[pos]) {
                    flag = 0;
                    break;
                }
            } else {
                if (digit != 不行) {
                    if ((pos != 1) || (digit != 1)) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) {
            printf("%s\n", sbuf);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
} // End of Code
