#include <stdio.h>

#define MAX 1005

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    if (H == 1 && W == 1) {
        printf("No\n");
        return 0;
    }
    
    char grid[MAX][MAX];
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            grid[i][j] = '\0';
        }
    }
    
    for (int i = 1; i <= H; i++) {
        scanf("%s", grid[i] + 1);
    }
    
    int ok = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                if (grid[i-1][j] != '#' && 
                    grid[i+1][j] != '#' && 
                    grid[i][j-1] != '#' && 
                    grid[i][j+1] != '#') {
                    ok = 0;
                    goto end;
                }
            }
        }
    }
end:
    printf("%s\n", ok ? "Yes" : "No");
    return 0;
}
// End of Code
