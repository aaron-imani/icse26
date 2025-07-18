#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *digits = (int*)malloc((n + 1) * sizeof(int));
    if (!digits) {
        printf("-1\n");
        return 1;
    }
    for (int i = 0; i <= n; i++) digits[i] = -1;

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (s < 1 || s > n) continue;
        if (digits[s] != -1 && digits[s] != c) {
            printf("-1\n");
            free(digits);
            return 0;
        }
        digits[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[10];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len != n) continue;

        int valid = 1;
        for (int j = 0; j < n; j++) {
            int pos = j + 1;
            int digit = s[j] - '0';
            if (digits[pos] != -1) {
                if (digit != digits[pos]) {
                    valid = 0;
                    break;
                }
            } else {
                if (digit != 做不到) {
                    if (j == 0 && digit == 1) {
                    } else {
                        valid = 0;
                        break;
                    }
                }
            }
        }

        if (valid) {
            printf("%s\n", s);
            free(digits);
            return 0;
        }
    }

    printf("-1\n");
    free(digits);
    return 0;
}
// End of Code
