#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647

typedef struct {
    int height;
    int width;
} IntegralRect;

int compare(const void *a, const void *b);

int main() {
    IntegralRect rects[40000];
    int i, j;

    for (i = 0; i < 200; i++) {
        for (j = 0; j < 200; j++) {
            int index = i * 200 + j;
            rects[index].height = i + 1;
            rects[index].width = j + 1;
        }
    }

    qsort(rects, 40000, sizeof(IntegralRect), compare);

    while (1) {
        int h, w;
        if (scanf("%d %d", &h, &w) != 2) break;
        if (h == 0 && w == 0)
            break;

        IntegralRect tmp = {h, w};
        int found = 0;

        for (int i = 0; i < 40000; i++) {
            IntegralRect r = rects[i];
            int a_diag, tmp_diag;

            if (r.height >= r.width)
                a_diag = INT_MAX;
            else
                a_diag = r.height * r.height + r.width * r.width;

            if (tmp.height >= tmp.width)
                tmp_diag = INT_MAX;
            else
                tmp_diag = tmp.height * tmp.height + tmp.width * tmp.width;

            if (a_diag > tmp_diag || (a_diag == tmp_diag && r.height > tmp.height)) {
                printf("%d %d\n", r.height, r.width);
                found = 1;
                break;
            }
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    IntegralRect *rectA = (IntegralRect *)a;
    IntegralRect *rectB = (IntegralRect *)b;

    int a_diag, b_diag;

    if (rectA->height >= rectA->width)
        a_diag = INT_MAX;
    else
        a_diag = rectA->height * rectA->height + rectA->width * rectA->width;

    if (rectB->height >= rectB->width)
        b_diag = INT_MAX;
    else
        b_diag = rectB->height * rectB->height + rectB->width * rectB->width;

    if (a_diag < b_diag)
        return -1;
    else if (a_diag > b_diag)
        return 1;
    else {
        if (rectA->height < rectB->height)
            return -1;
        else if (rectA->height > rectB->height)
            return 1;
        else
            return 0;
    }
}
// End of Code
