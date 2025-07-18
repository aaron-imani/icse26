#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

void solve(int testNumber) {
    int ans = 0;
    int K = nextInt();
    int S = nextInt();
    int wk = 0;
    for(int x=0; x <= K; x++) {
        for(int y=0; y <= K; y++) {
            wk = S - x - y;
            if(wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve(1);
    return 0;
}
// End of Code
