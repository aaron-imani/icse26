#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int constraints[n+1];
    for(int i = 0; i <= n; i++) constraints[i] = -1;

    for(int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if(constraints[s] != -1 && constraints[s] != c) {
            printf("-1\n");
            return 0;
        }
        constraints[s] = c;
    }

    for(int i = 0; i < 1000; i++) {
        char s[5];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if(len != n) continue;

        int flag = 1;
        for(int j = 0; j < n; j++) {
            int pos = j + 1;
            int current_digit = s[j] - '0';
            int required = constraints[pos];
            if(required != -1) {
                if(current_digit != required) {
                    flag = 0;
                    break;
                }
            } else {
                if(j == 0) {
                    if(current_digit != 1) {
                        flag = 0;
                        break;
                    }
                } else {
                    if(current_digit != 0) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag) {
            printf("%s\n", s);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
// End of Code
