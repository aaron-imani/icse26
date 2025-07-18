#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare(const void *a, const void *b) {
    IntegralRect *rect1 = (IntegralRect *)a;
    IntegralRect *rect2 = (IntegralRect *)b;
    int d1 = rect1->height * rect1->height + rect1->width * rect1->width;
    int d2 = rect2->height * rect2->height + rect2->width * rect2->width;
    if (d1 == d2) {
        return rect1->height - rect2->height;
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

    // debug
    // for (int i = 0; i < 100; i++) {
    //     printf("%d %d %d\n", rects[i].height, rects[i].width, rects[i].height * rects[i].height + rects[i].width * rects[i].width);
    // }

    int h, w;
    char input[10];
    while (1) {
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0) {
            break;
        }
        IntegralRect tmpRect = {h, w};
        int diag = tmpRect.height * tmpRect.height + tmpRect.width * tmpRect.width;
        for (int i = 0; i < 40000; i++) {
            if (rects[i].height * rects[i].height + rects[i].width * rects[i].width > diag) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    return 0;
}
// End of Code
