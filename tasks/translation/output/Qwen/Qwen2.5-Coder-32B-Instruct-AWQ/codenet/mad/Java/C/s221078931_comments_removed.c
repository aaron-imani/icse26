#include <stdio.h>
#include <stdlib.h>

#define MAX_RECTS 40000
#define INTEGER_MAX_VALUE 0x7fffffff

typedef struct {
    int height;
    int width;
} IntegralRect;

int diagonal(IntegralRect *rect) {
    if (rect->height >= rect->width) {
        return INTEGER_MAX_VALUE;
    }
    return rect->height * rect->height + rect->width * rect->width;
}

int compare(const void *a, const void *b) {
    IntegralRect *rect1 = (IntegralRect *)a;
    IntegralRect *rect2 = (IntegralRect *)b;

    int d1 = diagonal(rect1);
    int d2 = diagonal(rect2);

    if (d1 == d2) {
        return rect1->height - rect2->height;
    }
    return d1 - d2;
}

int main() {
    IntegralRect rects[MAX_RECTS];
    int index = 0;

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[index].height = i + 1;
            rects[index].width = j + 1;
            index++;
        }
    }

    qsort(rects, MAX_RECTS, sizeof(IntegralRect), compare);

    while (1) {
        int h, w;
        if (scanf("%d %d", &h, &w) != 2) {
            break;
        }

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect = {h, w};
        int diag = diagonal(&tmpRect);

        for (int i = 0; i < MAX_RECTS; i++) {
            if (compare(&rects[i], &tmpRect) > 0) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }

    return 0;
}
// End of Code
