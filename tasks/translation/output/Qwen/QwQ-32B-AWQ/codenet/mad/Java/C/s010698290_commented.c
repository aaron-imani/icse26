#include <stdio.h>

#define MAX_N 100000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int penal[MAX_N + 1];
    int solved[MAX_N + 1]; 

    for (int i = 0; i <= n; i++) {
        penal[i] = 0;
        solved[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int num;
        char str[2];
        scanf("%d %s", &num, str);

        if (str[0] == 'A') {
            solved[num] = 1;
        } else {
            if (solved[num] == 0) {
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
