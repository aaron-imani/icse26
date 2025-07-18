#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int ans = 100;
int balls[MAX_N][2];
int N;
int taken[MAX_N];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void sort_balls() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (balls[j][0] > balls[j + 1][0]) {
                int temp[2];
                memcpy(temp, balls[j], sizeof(balls[j]));
                memcpy(balls[j], balls[j + 1], sizeof(balls[j + 1]));
                memcpy(balls[j + 1], temp, sizeof(temp));
            }
        }
    }
}

void solve() {
    for (int add = 1; add < N; add++) {
        memset(taken, 0, sizeof(taken));
        int p = balls[add][0] - balls[0][0];
        int q = balls[add][1] - balls[0][1];
        ans = min(ans, check(p, q));
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
    sort_balls();
    solve();
    for (int i = 0; i < N; i++) {
        int x = balls[i][0];
        int y = balls[i][1];
        balls[i][0] = y;
        balls[i][1] = x;
    }
    sort_balls();
    solve();
    printf("%d\n", ans);
    return 0;
}
// End of Code
