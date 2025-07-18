#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 2147483647

typedef struct {
    int height;
    int width;
} IntegralRect;

int diagonal(IntegralRect rect) {
    if (rect.height >= rect.width) {
        return MAX_INT;
    }
    return rect.height * rect.height + rect.width * rect.width;
}

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;
    int d1 = diagonal(*rectA);
    int d2 = diagonal(*rectB);
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
        char input[100];
        if (!fgets(input, 100, stdin)) break;
        int h, w;
        if (sscanf(input, "%d %d", &h, &w) != 2) continue;
        if (h == 0 && w == 0) {
            break;
        }
        IntegralRect tmpRect = {h, w};
        int diag = diagonal(tmpRect);
        for (int i = 0; i < 40000; i++) {
            if (compare(&rects[i], &tmpRect) > 0) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    return 0;
}
// End of Code
