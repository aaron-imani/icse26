#include <stdio.h>
#include <string.h>

#define MAX_N 10005

int main() {
    int n, m, i, num, correct_ans = 0, num_penal = 0;
    char str[2];
    int penal[MAX_N] = {0};
    int solved[MAX_N] = {0};

    scanf("%d %d", &n, &m);

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

    return 0;
}

// End of Code
