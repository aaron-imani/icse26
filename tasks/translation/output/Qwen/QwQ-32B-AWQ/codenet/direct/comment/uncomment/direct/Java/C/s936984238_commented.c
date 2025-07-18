#include <stdio.h>
#include <stdlib.h>

static int *score = NULL;
static int number;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int read() {
    if (score != NULL) {
        free(score);
        score = NULL;
    }
    if (scanf("%d", &number) != 1) return 0;
    if (number == 0) return 0;
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
    while (read()) {
        solve();
    }
    return 0;
} // End of Code
