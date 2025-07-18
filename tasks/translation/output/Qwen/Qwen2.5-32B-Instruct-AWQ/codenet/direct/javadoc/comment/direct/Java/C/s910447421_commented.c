#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct {
    int x, y;
} Ball;

int ans = 100;
Ball balls[MAX_N];
int N;
int taken[MAX_N];

int compare(const void *a, const void *b) {
    Ball *ballA = (Ball *)a;
    Ball *ballB = (Ball *)b;
    return ballA->x - ballB->x;
}

void solve() {
    for (int add = 1; add < N; add++) {
        for (int i = 0; i < N; i++) {
            taken[i] = 0;
        }
        int p = balls[add].x - balls[0].x;
        int q = balls[add].y - balls[0].y;
        ans = ans < check(p, q) ? ans : check(p, q);
    }
}

int check(int p, int q) {
    int ret = 0;
    while (1) {
        int added = 0;
        int start = 0;
        int x = -1, y = -1;
        for (int i = 0; i < N; i++) {
            if (!taken[i]) {
                added = 1;
                ret++;
                start = i;
                taken[i] = 1;
                x = balls[i].x + p;
                y = balls[i].y + q;
                break;
            }
        }
        if (!added) break;
        for (int i = start + 1; i < N; i++) {
            if (balls[i].x == x && balls[i].y == y) {
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
        scanf("%d %d", &balls[i].x, &balls[i].y);
    }
    qsort(balls, N, sizeof(Ball), compare);
    solve();
    for (int i = 0; i < N; i++) {
        int temp = balls[i].x;
        balls[i].x = balls[i].y;
        balls[i].y = temp;
    }
    qsort(balls, N, sizeof(Ball), compare);
    solve();
    printf("%d\n", ans);
    return 0;
}

// End of Code
