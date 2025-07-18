#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

int main() {
    int n, m, i, num, correct_ans = 0, num_penal = 0;
    int penal[MAX];
    bool solved[MAX];
    char str[10];

    for (i = 0; i <= MAX; i++) {
        solved[i] = false;
        penal[i] = 0;
    }

    if (scanf("%d %d", &n, &m) != 2) {
        perror("Failed to read n and m");
        return 1;
    }

    for (i = 0; i < m; i++) {
        if (scanf("%d %s", &num, str) != 2) {
            perror("Failed to read num and str");
            return 1;
        }
        if (str[0] == 'A') {
            solved[num] = true;
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
