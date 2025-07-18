#include <stdio.h>
#include <stdlib.h>

int number;
int *score = NULL;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int read_input() {
    int num;
    if (scanf("%d", &num) != 1) return 0;
    if (num == 0) return 0;

    if (score != NULL) {
        free(score);
    }

    number = num;
    score = (int*)malloc(number * sizeof(int));
    if (score == NULL) return 0;

    for (int i = 0; i < number; i++) {
        scanf("%d", &score[i]);
    }

    return 1;
}

void solve() {
    qsort(score, number, sizeof(int), compare);

    int sum = 0;
    for (int i = 1; i < number - 1; i++) {
        sum += score[i];
    }

    printf("%d\n", sum / (number - 2));
}

int main() {
    while (read_input()) {
        solve();
    }

    if (score != NULL) {
        free(score);
    }

    return 0;
}
// End of Code
