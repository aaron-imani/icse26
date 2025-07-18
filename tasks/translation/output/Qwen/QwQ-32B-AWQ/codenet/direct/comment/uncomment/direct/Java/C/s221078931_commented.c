#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 40000

struct IntegralRect {
    int height;
    int width;
};

static int computeDiagonal(const struct IntegralRect *rect) {
    if (rect->height >= rect->width) {
        return INT_MAX;
    }
    return rect->height * rect->height + rect->width * rect->width;
}

static int compare(const void *a, const void *b) {
    struct IntegralRect *rectA = (struct IntegralRect*)a;
    struct IntegralRect *rectB = (struct IntegralRect*)b;

    int dA = computeDiagonal(rectA);
    int dB = computeDiagonal(rectB);

    if (dA < dB) return -1;
    if (dA > dB) return 1;
    if (rectA->height < rectB->height) return -1;
    if (rectA->height > rectB->height) return 1;
    return 0;
}

int main() {
    struct IntegralRect rects[MAX];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            int index = i * 200 + j;
            rects[index].height = i + 1;
            rects[index].width = j + 1;
        }
    }
    qsort(rects, MAX, sizeof(struct IntegralRect), compare);

    int h, w;
    while (scanf("%d %d", &h, &w) == 2 && !(h == 0 && w == 0)) {
        struct IntegralRect tmpRect = {h, w};
        for (int i = 0; i < MAX; i++) {
            if (compare(&rects[i], &tmpRect) > 0) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    return 0;
} // End of Code
