#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int pos[100]; // Assuming n is at most 99
    for (int i = 0; i <= n; i++) pos[i] = -1;

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (pos[s] != -1 && pos[s] != c) {
            printf("-1\n");
            return 0;
        }
        pos[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s_str[5];
        sprintf(s_str, "%d", i);
        int len = strlen(s_str);
        if (len != n) continue;

        int flag = 1;
        for (int j = 0; j < len; j++) {
            int digit = s_str[j] - '0';
            int pos_num = j + 1;
            int required = pos[pos_num];
            if (required != -1) {
                if (digit != required) {
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
            printf("%s\n", s_str);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
} // End of Code
