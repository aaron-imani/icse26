#include <stdio.h>
#include <string.h>

#define MAXN 100005

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int penal[MAXN];
    char solved[MAXN];
    memset(penal, 0, sizeof(penal));
    memset(solved, 0, sizeof(solved));

    for (int i = 0; i < m; i++) {
        int num;
        char str[10];
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
