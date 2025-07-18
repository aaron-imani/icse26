#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
    int diag;
} IntegralRect;

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;
    if (rectA->diag < rectB->diag) return -1;
    if (rectA->diag > rectB->diag) return 1;
    if (rectA->height < rectB->height) return -1;
    if (rectA->height > rectB->height) return 1;
    return 0;
}

int main() {
    IntegralRect rects[40000];
    int idx = 0;
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            IntegralRect rect;
            rect.height = i;
            rect.width = j;
            if (i < j) {
                rect.diag = i * i + j * j;
            } else {
                rect.diag = INT_MAX;
            }
            rects[idx++] = rect;
        }
    }
    qsort(rects, 40000, sizeof(IntegralRect), compare);

    int h, w;
    while (scanf("%d %d", &h, &w) == 2) {
        if (h == 0 && w == 0) break;
        IntegralRect tmp;
        tmp.height = h;
        tmp.width = w;
        if (h < w) {
            tmp.diag = h * h + w * w;
        } else {
            tmp.diag = INT_MAX;
        }
        int found = 0;
        for (int i = 0; i < 40000; i++) {
            IntegralRect *current = &rects[i];
            if (current->diag > tmp.diag) {
                printf("%d %d\n", current->height, current->width);
                found = 1;
                break;
            } else if (current->diag == tmp.diag && current->height > tmp.height) {
                printf("%d %d\n", current->height, current->width);
                found = 1;
                break;
            }
        }
    }
    return 0;
}
// End of Code
