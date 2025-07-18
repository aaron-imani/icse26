#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int c[MAX_SIZE][MAX_SIZE];
    int min[MAX_SIZE];
} Data;

void initialize(Data *data) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &data->c[i][j]);
        }
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        data->min[i] = data->c[i][1];
    }
}

void updateMin(Data *data) {
    for (int tc = 0; tc < MAX_SIZE; tc++) {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                data->min[i] = (data->min[i] < data->c[i][j] + data->min[j]) ? data->min[i] : data->c[i][j] + data->min[j];
            }
        }
    }
}

int main() {
    Data data;
    int H, W;
    scanf("%d %d", &H, &W);

    initialize(&data);
    updateMin(&data);

    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                ans += data.min[A];
            }
        }
    }

    printf("%d\n", ans);
    // End of Code
