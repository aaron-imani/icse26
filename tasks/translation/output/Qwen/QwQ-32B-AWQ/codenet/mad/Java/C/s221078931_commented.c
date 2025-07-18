#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare_rect(const void *a, const void *b);

int main() {
    IntegralRect rects[40000];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i*200 + j].height = i + 1;
            rects[i*200 + j].width = j + 1;
        }
    }
    qsort(rects, 40000, sizeof(IntegralRect), compare_rect);

    int h, w;
    while (scanf("%d %d", &h, &w) == 2) {
        if (h == 0 && w == 0) {
            break;
        }
        IntegralRect tmpRect = {h, w};
        for (int i = 0; i < 40000; i++) {
            if (compare_rect(&rects[i], &tmpRect) > 0) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    return 0;
}

int compare_rect(const void *a, const void *b) {
    IntegralRect *rect_a = (IntegralRect*)a;
    IntegralRect *rect_b = (IntegralRect*)b;
    int d1, d2;
    if (rect_a->height >= rect_a->width) {
        d1 = INT_MAX;
    } else {
        d1 = rect_a->height * rect_a->height + rect_a->width * rect_a->width;
    }
    if (rect_b->height >= rect_b->width) {
        d2 = INT_MAX;
    } else {
        d2 = rect_b->height * rect_b->height + rect_b->width * rect_b->width;
    }
    if (d1 != d2) {
        return d1 - d2;
    }
    return rect_a->height - rect_b->height;
}
// End of Code
