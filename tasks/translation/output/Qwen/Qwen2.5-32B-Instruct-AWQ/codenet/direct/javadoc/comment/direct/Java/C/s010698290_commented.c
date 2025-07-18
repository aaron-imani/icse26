#include <stdio.h>
#include <string.h>

#define MAX_N 100005

int n, m;
int penal[MAX_N];
char str[10];

int main() {
    int i, num, correct_ans = 0, num_penal = 0;
    bool solved[MAX_N] = {false};

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %s", &num, str);
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
