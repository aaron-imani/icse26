#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *solved = calloc(n + 1, sizeof(int));
    int *penal = calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int num;
        char str[10];
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
    for (int i = 1; i <= n; i++) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    free(solved);
    free(penal);
    return 0;
}
// End of Code
