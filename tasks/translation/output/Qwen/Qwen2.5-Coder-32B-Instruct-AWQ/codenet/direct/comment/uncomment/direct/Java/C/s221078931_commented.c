#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;
    int d1 = rectA->height >= rectA->width ? INT_MAX : rectA->height * rectA->height + rectA->width * rectA->width;
    int d2 = rectB->height >= rectB->width ? INT_MAX : rectB->height * rectB->height + rectB->width * rectB->width;
    if (d1 == d2) {
        return rectA->height - rectB->height;
    }
    return d1 - d2;
}

int main() {
    IntegralRect rects[40000];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j].height = i + 1;
            rects[i * 200 + j].width = j + 1;
        }
    }
    qsort(rects, 40000, sizeof(IntegralRect), compare);

    while (1) {
        int h, w;
        if (scanf("%d %d", &h, &w) != 2) break;
        if (h == 0 && w == 0) break;

        int diag = h >= w ? INT_MAX : h * h + w * w;
        for (int i = 0; i < 40000; i++) {
            int currentDiag = rects[i].height >= rects[i].width ? INT_MAX : rects[i].height * rects[i].height + rects[i].width * rects[i].width;
            if (currentDiag > diag) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }

    return 0;
}
// End of Code
