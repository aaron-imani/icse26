#include <stdio.h>

int main() {
    int K, S;
    scanf("%d %d", &K, &S);
    
    int ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
// End of Code
