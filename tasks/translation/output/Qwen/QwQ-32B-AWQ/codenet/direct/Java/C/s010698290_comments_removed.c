#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int penal[n + 1];
    char solved[n + 1];

    for (int i = 1; i <= n; i++) {
        solved[i] = 0;
        penal[i] = 0;
    }

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
    return 0;
}
// End of Code
