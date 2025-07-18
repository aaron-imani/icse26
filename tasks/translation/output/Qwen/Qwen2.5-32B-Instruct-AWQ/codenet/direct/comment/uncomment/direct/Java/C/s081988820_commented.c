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

void readMatrix(Matrix *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

void updateMinDistances(int *minDistances, int *c, int size) {
    for (int tc = 0; tc < size; tc++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                minDistances[i] = (minDistances[i] < c[i * size + j] + minDistances[j]) ? minDistances[i] : c[i * size + j] + minDistances[j];
            }
        }
    }
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    Matrix c;
    initializeMatrix(&c);
    readMatrix(&c, 10, 10);

    int minDistances[10];
    for (int i = 0; i < 10; i++) {
        minDistances[i] = c.data[i][1];
    }

    updateMinDistances(minDistances, (int *)c.data, 10);

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
