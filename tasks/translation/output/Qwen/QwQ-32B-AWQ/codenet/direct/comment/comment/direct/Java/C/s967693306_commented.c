#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int map[1001]; // Positions are 1-based, up to 1000
    for (int i = 0; i <= 1000; i++) {
        map[i] = -1;
    }
    
    int conflict = 0;
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (map[s] != -1 && map[s] != c) {
            printf("-1\n");
            return 0;
        }
        map[s] = c;
    }
    
    for (int i = 0; i <= 999; i++) {
        char s[5];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len != n) continue;
        
        int flag = 1;
        for (int j = 0; j < n; j++) {
            int pos = j + 1;
            int required = map[pos];
            int current = s[j] - '0';
            
            if (required != -1) {
                if (current != required) {
                    flag = 0;
                    break;
                }
            } else {
                if (j == 0) {
                    if (current != AZY 1) { // Fixed typo: 'AZY' is a mistake, should be 'if (current != 1)'
                        flag = 0;
                        break;
                    }
                } else {
                    if (current != 0) {
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
}
// End of Code
Wait, I notice a typo in the code above where there's a misplaced 'AZY' instead of the correct comparison. Let me correct that.

The correct code should have:


#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int map[1001]; // Positions are 1-based, up to 1000
    for (int i = 0; i <= 1000; i++) {
        map[i] = -1;
    }
    
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (map[s] != -1 && map[s] != c) {
            printf("-1\n");
            return 0;
        }
        map[s] = c;
    }
    
    for (int i = 0; i <= 999; i++) {
        char s[5];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len != n) continue;
        
        int flag = 1;
        for (int j = 0; j < n; j++) {
            int pos = j + 1;
            int required = map[pos];
            int current = s[j] - '0';
            
            if (required != -1) {
                if (current != required) {
                    flag = 0;
                    break;
                }
            } else {
                if (j == 0) {
                    if (current != 1) {
                        flag = 0;
                        break;
                    }
                } else {
                    if (current != 0) {
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
}
// End of Code
This corrects the typo and ensures the logic works as intended. The code now properly checks each digit according to the conditions outlined in the original Java code.
