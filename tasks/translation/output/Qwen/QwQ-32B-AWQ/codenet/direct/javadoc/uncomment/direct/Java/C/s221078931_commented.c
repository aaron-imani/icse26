#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
    int diag;
} Rectangle;

int compareRect(const void *a, const void *b) {
    Rectangle *ra = (Rectangle *)a;
    Rectangle *rb = (Rectangle *)b;
    if (ra->diag < rb->diag) return -1;
    if (ra->diag > rb->diag) return 1;
    return ra->height - rb->height;
}

int main() {
    Rectangle rectArr[200 * 200];
    int index = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            int h = i + 1;
            int w = j + 1;
            int diag;
            if (h < w) {
                diag = h * h + w * w;
            } else {
                diag = INT_MAX;
            }
            rectArr[index].height = h;
            rectArr[index].width = w;
            rectArr[index].diag = diag;
            index++;
        }
    }
    qsort(rectArr, 40000, sizeof(Rectangle), compareRect);
    int h, w;
    while (scanf("%d %d", &h, &w) == 2) {
        if (h == 0 && w == 0) break;
        int tmp_h = h;
        int tmp_w = w;
        int tmp_diag;
        if (tmp_h < tmp_w) {
            tmp_diag = tmp_h * tmp_h + tmp_w * tmp_w;
        } else {
            tmp_diag = INT_MAX;
        }
        for (int i = 0; i < 40000; i++) {
            Rectangle *r = &rectArr[i];
            if ((r->diag > tmp_diag) || 
                (r->diag == tmp_diag && r->height > tmp_h)) {
                printf("%d %d\n", r->height, r->width);
                break;
            }
        }
    }
    return 0;
}
// End of Code
