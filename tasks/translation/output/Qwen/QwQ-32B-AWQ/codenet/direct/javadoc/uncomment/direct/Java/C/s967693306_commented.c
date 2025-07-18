#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int required_digits[1001];
    for (int i = 0; i <= 1000; i++) {
        required_digits[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (required_digits[s] != -1 && required_digits[s] != c) {
            printf("-1\n");
            return 0;
        }
        required_digits[s] = c;
    }
    for (int i = 0; i < 1000; i++) {
        char str[12];
        sprintf(str, "%d", i);
        int len = strlen(str);
        if (len != n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            int pos = j + 1;
            int digit = str[j] - '0';
            int req = required_digits[pos];
            if (req != -1) {
                if (digit != req) {
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
        if (flag) {
            printf("%s\n", str);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
// End of Code
