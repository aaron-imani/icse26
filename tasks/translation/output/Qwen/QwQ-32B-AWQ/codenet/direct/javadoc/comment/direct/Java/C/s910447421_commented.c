#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

Point *balls;
int N;
int ans = 100;
char *taken;

int compare(const void *a, const void *b) {
    Point *p1 = (Point*)a;
    Point *p2 = (Point*)b;
    return p1->x - p2->x;
}

void solve() {
    for (int add = 1; add < N; add++) {
        memset(taken, 0, N * sizeof(char));
        int p = balls[add].x - balls[0].x;
        int q = balls[add].y - balls[0].y;
        int current = check(p, q);
        if (current < ans) ans = current;
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
                taken[i] = 1;
                start = i;
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
    balls = malloc(N * sizeof(Point));
    taken = malloc(N * sizeof(char));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &balls[i].x, &balls[i].y);
    }
    qsort(balls, N, sizeof(Point), compare);
    solve();
    for (int i = 0; i < N; i++) {
        int temp = balls[i].x;
        balls[i].x = balls[i].y;
        balls[i].y = temp;
    }
    qsort(balls, N, sizeof(Point), compare);
    solve();
    printf("%d\n", ans);
    free(balls);
    free(taken);
    return 0;
}
// End of Code
