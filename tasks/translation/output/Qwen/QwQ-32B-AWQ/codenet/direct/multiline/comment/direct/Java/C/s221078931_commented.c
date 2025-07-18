#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct IntegralRect {
    int height;
    int width;
};

int compare(const void *a, const void *b) {
    const struct IntegralRect *rectA = (const struct IntegralRect *)a;
    const struct IntegralRect *rectB = (const struct IntegralRect *)b;

    int diagA, diagB;

    if (rectA->height >= rectA->width) {
        diagA = INT_MAX;
    } else {
        diagA = rectA->height * rectA->height + rectA->width * rectA->width;
    }

    if (rectB->height >= rectB->width) {
        diagB = INT_MAX;
    } else {
        diagB = rectB->height * rectB->height + rectB->width * rectB->width;
    }

    if (diagA < diagB) {
        return -1;
    } else if (diagA > diagB) {
        return 1;
    } else {
        if (rectA->height < rectB->height) {
            return -1;
        } else if (rectA->height > rectB->height) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    struct IntegralRect rects[40000];

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            int h = i + 1;
            int w = j + 1;
            int index = i * 200 + j;
            rects[index].height = h;
            rects[index].width = w;
        }
    }

    qsort(rects, 40000, sizeof(struct IntegralRect), compare);

    int h, w;
    while (scanf("%d %d", &h, &w) == 2) {
        if (h == 0 && w == 0) {
            break;
        }

        struct IntegralRect tmp = {h, w};
        int found = 0;

        for (int i = 0; i < 40000; i++) {
            struct IntegralRect *current = &rects[i];
            int cmp = compare(current, &tmp);
            if (cmp > 0) {
                printf("%d %d\n", current->height, current->width);
                found = 1;
                break;
            }
        }

        if (!found) {
        }
    }

    return 0;
}
// End of Code
