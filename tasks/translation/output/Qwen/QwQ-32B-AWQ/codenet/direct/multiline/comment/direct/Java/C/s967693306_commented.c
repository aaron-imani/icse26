#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int constraints[4]; // assuming n <= 3
    for (int i = 0; i < 4; i++) constraints[i] = -1;
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (s < 1 || s > n) {
            printf("-1\n");
            return 0;
        }
        if (constraints[s] != -1 && constraints[s] != c) {
            printf("-1\n");
            return 0;
        }
        constraints[s] = c;
    }
    for (int num = 0; num < 1000; num++) {
        char str[5];
        sprintf(str, "%d", num);
        int len = strlen(str);
        if (len != n) continue;
        int valid = 1;
        for (int j = 0; j < n; j++) {
            int digit = str[j] - '0';
            int pos = j + 1;
            int required = constraints[pos];
            if (required != -1) {
                if (digit != required) {
                    valid = 0;
                    break;
                }
            } else {
                if (j == 0) {
                    if (n == 1) {
                        continue;
                    } else {
                        if (digit < 1) {
                            valid = 0;
                            break;
                        }
                    }
                } else {
                    if (digit != 0) {
                        valid = 0;
                        break;
                    }
                }
            }
        }
        if (valid) {
            printf("%s\n", str);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
} // End of Code
