#include <stdio.h>
#include <stdlib.h>

int ans = 100;
int balls[1000][2];
int N;
_Bool taken[1000];

int compare(const void *a, const void *b) {
    return (*(int(*)[2])a)[0] - (*(int(*)[2])b)[0];
}

int min(int a, int b) {
    return a < b ? a : b;
}

void solve() {
    for (int add = 1; add < N; add++) {
        for (int i = 0; i < N; i++) {
            taken[i] = 0;
        }
        int p = balls[add][0] - balls[0][0];
        int q = balls[add][1] - balls[0][1];
        ans = min(ans, check(p, q));
    }
}

int check(int p, int q) {
    int ret = 0;
    while (1) {
        _Bool added = 0;
        int start = 0;
        int x = -1;
        int y = -1;
        for (int i = 0; i < N; i++) {
            if (!taken[i]) {
                added = 1;
                ret++;
                start = i;
                taken[i] = 1;
                x = balls[i][0] + p;
                y = balls[i][1] + q;
                break;
            }
        }
        if (!added) break;
        for (int i = start + 1; i < N; i++) {
            if (balls[i][0] == x && balls[i][1] == y) {
                taken[i] = 1;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    ans = N;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &balls[i][0], &balls[i][1]);
    }
    qsort(balls, N, sizeof(balls[0]), compare);
    solve();
    for (int i = 0; i < N; i++) {
        int x = balls[i][0];
        int y = balls[i][1];
        balls[i][0] = y;
        balls[i][1] = x;
    }
    qsort(balls, N, sizeof(balls[0]), compare);
    solve();
    printf("%d\n", ans);
    return 0;
}
// End of Code
