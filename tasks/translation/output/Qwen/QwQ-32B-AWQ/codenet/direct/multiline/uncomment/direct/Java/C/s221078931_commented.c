#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare(const void *a, const void *b);

int main() {
    IntegralRect rects[40000];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            int idx = i * 200 + j;
            rects[idx].height = i + 1;
            rects[idx].width = j + 1;
        }
    }
    qsort(rects, 40000, sizeof(IntegralRect), compare);

    int h, w;
    while (scanf("%d %d", &h, &w) == 2) {
        if (h == 0 && w == 0)
            break;
        IntegralRect tmp = {h, w};
        for (int i = 0; i < 40000; i++) {
            IntegralRect *r = &rects[i];
            if (compare(r, &tmp) > 0) {
                printf("%d %d\n", r->height, r->width);
                goto next;
            }
        }
    next:;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;

    int dA;
    if (rectA->height >= rectA->width) {
        dA = INT_MAX;
    } else {
        dA = rectA->height * rectA->height + rectA->width * rectA->width;
    }

    int dB;
    if (rectB->height >= rectB->width) {
        dB = INT_MAX;
    } else {
        dB = rectB->height * rectB->height + rectB->width * rectB->width;
    }

    if (dA != dB) {
        return dA - dB;
    }
    return rectA->height - rectB->height;
}
// End of Code
