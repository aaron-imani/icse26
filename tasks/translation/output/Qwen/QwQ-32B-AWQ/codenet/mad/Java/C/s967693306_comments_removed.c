#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int max_pos = n;
    int positions[max_pos + 1];

    for (int i = 0; i <= max_pos; i++) {
        positions[i] = -1;
    }

    int conflict = 0;

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (positions[s] != -1 && positions[s] != c) {
            conflict = 1;
            break;
        }
        positions[s] = c;
    }

    if (conflict) {
        printf("-1\n");
        return 0;
    }

    for (int num = 0; num < 1000; num++) {
        char str[5];
        sprintf(str, "%d", num);
        int len = strlen(str);
        if (len != n) continue;

        int valid = 1;
        for (int j = 0; j < len; j++) {
            int digit = str[j] - '0';
            int pos = j + 1;
            if (positions[pos] != -1) {
                if (digit != positions[pos]) {
                    valid = 0;
                    break;
                }
            } else {
                if (j == 0) {
                    if (digit == 0) {
                        valid = 0;
                        break;
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
}
// End of Code
