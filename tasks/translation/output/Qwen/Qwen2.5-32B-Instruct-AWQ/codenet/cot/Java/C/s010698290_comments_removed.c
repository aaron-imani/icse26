#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *penal;
    int *solved;
} Contestant;

void readInput(int *n, int *m, Contestant *contestant) {
    char str[2];
    int num;
    for (int i = 0; i < *m; i++) {
        scanf("%d", &num);
        scanf("%s", str);
        if (str[0] == 'A') {
            contestant->solved[num] = 1;
        } else {
            if (contestant->solved[num] == 0) {
                contestant->penal[num]++;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Contestant contestant = { .penal = (int *)calloc(n + 1, sizeof(int)), .solved = (int *)calloc(n + 1, sizeof(int)) };

    readInput(&n, &m, &contestant);

    int correct_ans = 0, num_penal = 0;
    for (int i = 1; i <= n; i++) {
        if (contestant.solved[i] == 1) {
            correct_ans++;
            num_penal += contestant.penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    free(contestant.penal);
    free(contestant.solved);

    return 0;
}
// End of Code
