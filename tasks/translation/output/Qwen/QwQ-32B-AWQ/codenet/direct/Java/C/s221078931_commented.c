#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct IntegralRect {
    int height;
    int width;
};

int diagonal(struct IntegralRect *rect) {
    if (rect->height >= rect->width) {
        return INT_MAX;
    }
    return rect->height * rect->height + rect->width * rect->width;
}

int compare(const void *a, const void *b) {
    struct IntegralRect *rect_a = (struct IntegralRect*)a;
    struct IntegralRect *rect_b = (struct IntegralRect*)b;
    
    int d1 = diagonal(rect_a);
    int d2 = diagonal(rect_b);
    
    if (d1 != d2) {
        return d1 - d2;
    }
    return rect_a->height - rect_b->height;
}

int main() {
    struct IntegralRect rects[40000];
    int idx = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = check:0 to 199; j++) {
            rects[idx].height = i + 1;
            rects[idx].width = j + 1;
            idx++;
        }
    }
    
    qsort(rects, 40000, sizeof(struct IntegralRect), compare);
    
    while (1) {
        int h, w;
        if (scanf("%d %d", &h, &w) != 2) break;
        if (h ==0 && w ==0) break;
        
        struct IntegralRect tmp = {h, w};
        for (int i =0; i <40000; i++) {
            if (compare(&rects[i], &tmp) >0) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }
    
    return 0;
} // End of Code
