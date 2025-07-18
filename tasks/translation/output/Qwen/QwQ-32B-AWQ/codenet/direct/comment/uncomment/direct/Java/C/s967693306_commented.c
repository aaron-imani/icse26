#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int required[10] = {0};
    for (int i = 0; i < 10; i++) required[i] = -1;

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (required[s] != -1 && required[s] != c) {
            printf("-1\n");
            return 0;
        }
        required[s] = c;
    }

    for (int i = 0; i <= 999; i++) {
        char s_str[5];
        sprintf(s_str, "%d", i);
        int len = strlen(s_str);
        if (len != n) continue;

        int flag = 1;
        for (int j = 0; j < n; j++) {
            int digit = s_str[j] - '0';
            int pos = j + 1;
            if (required[pos] != -1) {
                if (digit != required[pos]) {
                    flag = 0;
                    break;
                }
            } else {
                if (j == 0) {
                    if (digit != 1) {
                        flag = 0;
                        break;
                    }
                } else {
                    if (digit != 0) {
                        flag = 0;
                        break;
                    }
                }
            }
        }

        if (flag) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
} // End of Code
