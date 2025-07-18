#include <stdio.h>

int compute_answer(int K, int S) {
    int ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - x - y;
            if (z >= 0 && z <= K) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int K, S;
    scanf("%d %d", &K, &S);
    printf("%d\n", compute_answer(K, S));
    return 0;
}
// End of Code
