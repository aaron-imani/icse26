#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005

int n, m;
int penal[MAX_N];
int solved[MAX_N];

int main() {
    int i, num;
    char str[10];
    int correct_ans = 0, num_penal = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i <= n; i++) {
        solved[i] = 0;
        penal[i] = 0;
    }

    for (i = 0; i < m; i++) {
        scanf("%d %s", &num, str);
        if (str[0] == 'A') {
            solved[num] = 1;
        } else {
            if (solved[num] == 0) {
                penal[num]++;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (solved[i] == 1) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    return 0;
}
// End of Code
