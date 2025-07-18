#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005

int main() {
    int n, m, i, num;
    char str[2];

    scanf("%d %d", &n, &m);

    int penal[MAX_N] = {0};
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

    int correct_ans = 0, num_penal = 0;
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
