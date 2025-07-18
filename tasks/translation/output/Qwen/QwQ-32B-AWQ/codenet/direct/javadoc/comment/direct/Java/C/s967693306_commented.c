#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int required_digits[n + 1];
    for (int i = 0; i <= n; i++) {
        required_digits[i] = -1;
    }
    
    int conflict = 0;
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (required_digits[s] != -1 && required_digits[s] != c) {
            conflict = 1;
        }
        required_digits[s] = c;
    }
    
    if (conflict) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 0; i < 1000; i++) {
        char s[5];
        sprintf(s, "%d", i);
        if (strlen(s) != n) continue;
        
        int flag = 1;
        for (int j = 0; j < n; j++) {
            int digit = s[j] - '0';
            int pos = j + 1;
            int req = required_digits[pos];
            
            if (req != -1) {
                if (digit != req) {
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
            printf("%s\n", s);
            return 0;
        }
    }
    
    printf("-1\n");
    return 0;
}
// End of Code
