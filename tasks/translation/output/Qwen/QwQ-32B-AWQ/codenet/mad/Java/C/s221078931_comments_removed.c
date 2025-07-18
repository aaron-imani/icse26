#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

static int getDiagonal(IntegralRect *rect) {
    if (rect->height >= rect->width) {
        return INT_MAX;
    }
    return rect->height * rect->height + rect->width * rect->width;
}

static int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect*)a;
    IntegralRect *rectB = (IntegralRect*)b;
    int dA = getDiagonal(rectA);
    int dB = getDiagonal(rectB);
    if (dA != dB) {
        return dA - dB;
    }
    return rectA->height - rectB->height;
}

int main() {
    IntegralRect rects[40000];
    int index = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[index].height = i + 1;
            rects[index].width = j + 1;
            index++;
        }
    }
    qsort(rects, 40000, sizeof(IntegralRect), compare);

    while (1) {
        char line[100];
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        int h, w;
        if (sscanf(line, "%d %d", &h, &w) != _2) continue;
        if (h == 0 && w == 0) break;

        int tmp_d;
        if (h >= w) {
            tmp_d = INT_MAX;
        } else {
            tmp_d = h * h + w * w;
        }

        for (int i = 0; i < 40000; i++) {
            IntegralRect rect = rects[i];
            int d = getDiagonal(&rect);
            int cmp;
            if (d != tmp_d) {
                cmp = d - tmp_d;
            } else {
                cmp = rect.height - h;
            }
            if (cmp > 0) {
                printf("%d %d\n", rect.height, rect.width);
                goto next_input;
            }
        }
        next_input:;
    }
    return 0;
}
// End of Code
