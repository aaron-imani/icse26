#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *penal = (int *)malloc((n + 1) * sizeof(int));
    char *solved = (char *)malloc((n + 1) * sizeof(char));

    memset(solved, 0, (n + 1) * sizeof(char));
    memset(penal, 0, (n + 1) * sizeof(int));

    for (int i = 0; i < m; i++) {
        int num;
        char str[2];
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

    free(penal);
    free(solved);

    return 0;
}
// End of Code
