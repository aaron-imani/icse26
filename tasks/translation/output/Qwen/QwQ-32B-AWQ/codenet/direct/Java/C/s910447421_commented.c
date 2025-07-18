#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ball;

Ball *balls;
int N;
int ans = 100;
char *taken;

int compareBalls(const void *a, const void *b) {
    Ball *ballA = (Ball*)a;
    Ball *ballB = (Ball*)b;
    if (ballA->x < ballB->x) return -1;
    else if (ballA->x > ballB->x) return 1;
    else return 0;
}

void solve() {
    for (int add = 1; add < N; add++) {
        for (int i = 0; i < N; i++) taken[i] = 0;
        int p = balls[add].x - balls[0].x;
        int q = balls[add].y - balls[0].y;
        int temp = check(p, q);
        if (temp < ans) ans = temp;
    }
}

int check(int p, int q) {
    int ret = 0;
    while (1) {
        int added = 0;
        int start = 0;
        int x = -1;
        int y = -1;
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

int main() {
    scanf("%d", &N);
    ans = N;
    balls = (Ball*)malloc(N * sizeof(Ball));
    taken = (char*)malloc(N * sizeof(char));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &balls[i].x, &balls[i].y);
    }
    qsort(balls, N, sizeof(Ball), compareBalls);
    solve();
    for (int i = 0; i < N; i++) {
        int temp = balls[i].x;
        balls[i].x = balls[i].y;
        balls[i].y = temp;
    }
    qsort(balls, N, sizeof(Ball), compareBalls);
    solve();
    printf("%d\n", ans);
    free(balls);
    free(taken);
    return 0;
}
// End of Code
