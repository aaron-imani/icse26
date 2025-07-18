#include <stdio.h>
#include <string.h>

#define MAX_N 100005

int n, m;
int penal[MAX_N];
char str[10];

void solve() {
    int i, num, correct_ans = 0, num_penal = 0;
    int solved[MAX_N] = {0};

    for (i = 0; i < m; i++) {
        scanf("%d %s", &num, str);
        if (str[0] == 'A') {
            solved[num] = 1;
        } else {
            if (!solved[num]) {
                penal[num]++;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);
}

int main() {
    scanf("%d %d", &n, &m);
    memset(penal, 0, sizeof(penal));
    solve();
    return 0;
}

// End of Code
