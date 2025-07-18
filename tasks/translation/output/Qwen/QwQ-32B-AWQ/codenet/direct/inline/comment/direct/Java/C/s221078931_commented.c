#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int diagonal(const IntegralRect *rect) {
    if (rect->height >= rect->width) {
        return INT_MAX;
    }
    return rect->height * rect->height + rect->width * rect->width;
}

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;
    int dA = diagonal(rectA);
    int dB = diagonal(rectB);
    if (dA != dB) {
        return dA - dB;
    }
    return rectA->height - rectB->height;
}

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
        if (h == 0 && w == 0) break;
        IntegralRect tmp = {h, w};
        for (int i = 0; i < 40000; i++) {
            IntegralRect *current = &rects[i];
            int cmp = compare(current, &tmp);
            if (cmp > 0) {
                printf("%d %d\n", current->height, current->width);
                break;
            }
        }
    }
    return 0;
}
// End of Code
