#include <stdio.h>

int main() {
    int n, m, i, num, correct_ans = 0, num_penal = 0;
    int penal[10001] = {0};
    char str[2]; // Only need space for 'A' or 'W' plus null terminator
    int solved[10001] = {0};

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %s", &num, str);
        if (str[0] == 'A') {
            solved[num] = 1;
        } else if (solved[num] == 0) {
            penal[num]++;
        }
    }

    for (i = 1; i <= n; i++) {
        if (solved[i] == 1) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);
    // End of Code
}
