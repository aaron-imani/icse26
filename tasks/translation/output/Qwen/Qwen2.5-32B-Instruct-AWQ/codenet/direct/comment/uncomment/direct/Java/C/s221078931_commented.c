#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;
    int d1 = rectA->height * rectA->height + rectA->width * rectA->width;
    int d2 = rectB->height * rectB->height + rectB->width * rectB->width;
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
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0) {
            break;
        }
        IntegralRect tmpRect = {h, w};
        int diag = tmpRect.height * tmpRect.height + tmpRect.width * tmpRect.width;
        for (int i = 0; i < 40000; i++) {
            int d = rects[i].height * rects[i].height + rects[i].width * rects[i].width;
            if (d > diag) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    // End of Code
}
