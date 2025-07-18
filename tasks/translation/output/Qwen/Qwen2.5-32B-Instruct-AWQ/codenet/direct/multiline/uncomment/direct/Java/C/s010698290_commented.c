#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10005

int n, m;
int penal[MAXN];
char str[10];

int main() {
    int i, num, correct_ans = 0, num_penal = 0;
    bool solved[MAXN] = {false};

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
