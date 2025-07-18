#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void initializeMatrix(Matrix *matrix) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            matrix->data[i][j] = 0;
        }
    }
}

void readMatrix(Matrix *matrix) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

void updateMinDistances(int *minDistances, Matrix *matrix) {
    for (int i = 0; i < MAX_SIZE; i++) {
        minDistances[i] = matrix->data[i][1];
    }
    for (int tc = 0; tc < MAX_SIZE; tc++) {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                minDistances[i] = (minDistances[i] < matrix->data[i][j] + minDistances[j]) ? minDistances[i] : matrix->data[i][j] + minDistances[j];
            }
        }
    }
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    Matrix c;
    initializeMatrix(&c);
    readMatrix(&c);

    int minDistances[MAX_SIZE];
    updateMinDistances(minDistances, &c);

    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                ans += minDistances[A];
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

// End of Code
