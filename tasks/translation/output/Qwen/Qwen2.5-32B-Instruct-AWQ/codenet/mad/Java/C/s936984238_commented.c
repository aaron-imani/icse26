#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int score[MAX_SIZE];
int number;

int read() {
    scanf("%d", &number);
    if (number == 0) {
        return 0;
    }
    for (int i = 0; i < number; i++) {
        scanf("%d", &score[i]);
    }
    return 1;
}

void slove() {
    qsort(score, number, sizeof(int), compare);
    int sum = 0;
    for (int i = 1; i < number - 1; i++) {
        sum += score[i];
    }
    printf("%d\n", sum / (number - 2));
}

int main() {
    while (read()) {
        slove();
    }
    // End of Code
}
