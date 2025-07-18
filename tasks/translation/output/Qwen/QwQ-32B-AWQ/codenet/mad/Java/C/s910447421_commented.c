#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ball;

Ball *balls;
int ans = 100;
int N;

int compare_x(const void *a, const void *b) {
    Ball *pa = (Ball*)a;
    Ball *pb = (Ball*)b;
    return pa->x - pb->x;
}

int check(int p, int q, char *taken) {
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
            if (!taken[i] && balls[i].x == x && balls[i].y == y) {
                taken[i] = 1;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

void solve() {
    for (int add = 1; add < N; add++) {
        char *taken = (char*)malloc(N * sizeof(char));
        for (int i = 0; i < N; i++) taken[i] = 0;
        int p = balls[add].x - balls[0].x;
        int q = balls[add].y - balls[0].y;
        int current = check(p, q, taken);
        if (current < ans) ans = current;
        free(taken);
    }
}

int main() {
    scanf("%d", &N);
    ans = N;
    balls = (Ball*)malloc(N * sizeof(Ball));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &balls[i].x, &balls[i].y);
    }
    qsort(balls, N, sizeof(Ball), compare_x);
    solve();
    for (int i = 0; i < N; i++) {
        int temp = balls[i].x;
        balls[i].x = balls[i].y;
        balls[i].y = temp;
    }
    qsort(balls, N, sizeof(Ball), compare_x);
    solve();
    printf("%d\n", ans);
    free(balls);
    return 0;
}
// End of Code
