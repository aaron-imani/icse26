#include <stdio.h>

int main() {
    int K, S, ans = 0;
    scanf("%d %d", &K, &S);
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - x - y;
            if (z >= 0 && z <= K) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
// End of Code
