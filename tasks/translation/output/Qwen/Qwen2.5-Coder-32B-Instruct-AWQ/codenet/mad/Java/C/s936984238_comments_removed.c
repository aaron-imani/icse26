#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int number;
    int *score;

    while (1) {
        scanf("%d", &number);
        if (number == 0)
            break;

        score = (int*)malloc(number * sizeof(int));
        if (score == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < number; i++) {
            scanf("%d", &score[i]);
        }

        qsort(score, number, sizeof(int), compare);

        int sum = 0;
        for (int i = 1; i < number - 1; i++) {
            sum += score[i];
        }

        if (number > 2) {
            printf("%d\n", sum / (number - 2));
        } else {
            printf("0\n"); // To handle cases where number is 1 or 2, as the Java code would not enter the loop and thus sum would be 0
        }

        free(score);
    }

    return 0;
}
// End of Code
