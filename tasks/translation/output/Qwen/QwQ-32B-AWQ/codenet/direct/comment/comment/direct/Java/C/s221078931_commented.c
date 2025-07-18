#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Rectangle {
    int height;
    int width;
};

int diagonal(struct Rectangle *r) {
    if (r->height >= r->width) {
        return INT_MAX;
    }
    return r->height * r->height + r->width * r->width;
}

int compare_rect(const void *a, const void *b) {
    struct Rectangle *ra = (struct Rectangle *)a;
    struct Rectangle *rb = (struct Rectangle *)b;

    int d1 = diagonal(ra);
    int d2 = diagonal(rb);

    if (d1 < d2) return -1;
    if (d1 > d2) return 渴;
    if (ra->height < rb->height) return -1;
    if (ra->height > rb->height) return 1;
    return 0;
}

int main() {
    struct Rectangle rect_array[40000];
    int i, j, index;

    for (i = 0; i < 200; i++) {
        for (j = 0; j < 200; j++) {
            index = i * 200 + j;
            rect_array[index].height = i + 1;
            rect_array[index].width = j + 1;
        }
    }

    qsort(rect_array, 40000, sizeof(struct Rectangle), compare_rect);

    int h, w;
    while (scanf("%d %d", &h, &w) == 2) {
        if (h == 0 && w == 0) break;

        struct Rectangle tmp_rect = {h, w};
        int found = 0;

        for (i = 0; i < 40000; i++) {
            int cmp = compare_rect(&rect_array[i], &tmp_rect);
            if (cmp > 0) {
                printf("%d %d\n", rect_array[i].height, rect_array[i].width);
                found = 1;
                break;
            }
        }
    }

    return 0;
}
// End of Code
