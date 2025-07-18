#include <stdio.h>
#include <stdlib.h>

int number;
int* score;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int read() {
    scanf("%d", &number);
    if (number == 0)
        return 0;
    score = (int*)malloc(number * sizeof(int));
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
    return 0;
} // End of Code
