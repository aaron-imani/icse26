#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECTS 40000

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
    IntegralRect rects[MAX_RECTS];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j].height = i + 1;
            rects[i * 200 + j].width = j + 1;
        }
    }
    qsort(rects, MAX_RECTS, sizeof(IntegralRect), compare);

    char input[10];
    while (fgets(input, sizeof(input), stdin)) {
        int h, w;
        sscanf(input, "%d %d", &h, &w);
        if (h == 0 && w == 0) break;

        IntegralRect tmpRect = { .height = h, .width = w };
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
