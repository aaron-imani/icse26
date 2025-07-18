#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Ball;

int ans = 0;
Ball *balls;
int N;
int *taken;

void solve();
int check(int p, int q);
int compare(const void *a, const void *b);

int main() {
    scanf("%d", &N);
    ans = N;
    balls = (Ball *)malloc(N * sizeof(Ball));
    taken = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &balls[i].x);
        scanf("%d", &balls[i].y);
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
    free(balls);
    free(taken);
    return 0;
}

void solve() {
    for (int add = 1; add < N; add++) {
        memset(taken, 0, N * sizeof(int));
        int p = balls[add].x - balls[0].x;
        int q = balls[add].y - balls[0].y;
        int res = check(p, q);
        if (res < ans) ans = res;
    }
}

int check(int p, int q) {
    int ret = 0;
    while (1) {
        int added = 0;
        int start = -1;
        int x, y;
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
            if (!taken[i] && balls[i].x == x && balls[i].y == y) {
                taken[i] = 1;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

int compare(const void *a, const void *b) {
    Ball *pa = (Ball *)a;
    Ball *pb = (Ball *)b;
    return pa->x - pb->x;
}
// End of Code
