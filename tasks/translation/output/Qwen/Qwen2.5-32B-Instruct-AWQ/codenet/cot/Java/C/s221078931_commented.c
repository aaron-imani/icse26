#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECTS 40000
#define MAX_DIM 200

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare(const void *a, const void *b) {
    IntegralRect *rect1 = (IntegralRect *)a;
    IntegralRect *rect2 = (IntegralRect *)b;
    int d1 = rect1->height * rect1->height + rect1->width * rect1->width;
    int d2 = rect2->height * rect2->height + rect2->width * rect2->width;
    if (d1 == d2) {
        return rect1->height - rect2->height;
    }
    return d1 - d2;
}

int main() {
    IntegralRect rects[MAX_RECTS];
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            rects[i * MAX_DIM + j].height = i + 1;
            rects[i * MAX_DIM + j].width = j + 1;
        }
    }
    qsort(rects, MAX_RECTS, sizeof(IntegralRect), compare);

    char input[100];
    while (1) {
        fgets(input, sizeof(input), stdin);
        int h, w;
        sscanf(input, "%d %d", &h, &w);
        if (h == 0 && w == 0) {
            break;
        }
        IntegralRect tmpRect = {h, w};
        int diag = tmpRect.height * tmpRect.height + tmpRect.width * tmpRect.width;
        for (int i = 0; i < MAX_RECTS; i++) {
            int d = rects[i].height * rects[i].height + rects[i].width * rects[i].width;
            if (d > diag) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    // End of Code
}
