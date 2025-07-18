#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int key;
    int val;
} PP;

typedef struct {
    int key;
    int val1;
    int val2;
} PPP;

typedef struct {
    long key;
    long val;
} PPL;

typedef struct {
    long key;
    long *val;
} PPDL;

typedef struct {
    int key;
    int val;
} PPKEY;

typedef struct {
    long key;
    long val;
} PPLKEY;

typedef struct {
    int *keys;
    int *values;
    int size;
    int capacity;
} MapCounter;

void MapCounter_init(MapCounter *mc, bool reverse) {
    mc->keys = (int *)malloc(100 * sizeof(int));
    mc->values = (int *)malloc(100 * sizeof(int));
    mc->size = 0;
    mc->capacity = 100;
}

void MapCounter_add(MapCounter *mc, int key, int cnt) {
    for (int i = 0; i < mc->size; i++) {
        if (mc->keys[i] == key) {
            mc->values[i] += cnt;
            return;
        }
    }
    if (mc->size == mc->capacity) {
        mc->capacity *= 2;
        mc->keys = (int *)realloc(mc->keys, mc->capacity * sizeof(int));
        mc->values = (int *)realloc(mc->values, mc->capacity * sizeof(int));
    }
    mc->keys[mc->size] = key;
    mc->values[mc->size] = cnt;
    mc->size++;
}

void MapCounter_remove(MapCounter *mc, int key) {
    for (int i = 0; i < mc->size; i++) {
        if (mc->keys[i] == key) {
            mc->values[i]--;
            if (mc->values[i] == 0) {
                mc->keys[i] = mc->keys[mc->size - 1];
                mc->values[i] = mc->values[mc->size - 1];
                mc->size--;
            }
            return;
        }
    }
}

void MapCounter_sub(MapCounter *mc, int key, int cnt, bool minus) {
    for (int i = 0; i < mc->size; i++) {
        if (mc->keys[i] == key) {
            mc->values[i] -= cnt;
            if (mc->values[i] <= 0) {
                mc->keys[i] = mc->keys[mc->size - 1];
                mc->values[i] = mc->values[mc->size - 1];
                mc->size--;
            }
            return;
        }
    }
    if (minus) {
        MapCounter_add(mc, key, -cnt);
    }
}

void MapCounter_set(MapCounter *mc, int key, int cnt) {
    for (int i = 0; i < mc->size; i++) {
        if (mc->keys[i] == key) {
            mc->values[i] = cnt;
            return;
        }
    }
    MapCounter_add(mc, key, cnt);
}

int MapCounter_getCount(MapCounter *mc, int key) {
    for (int i = 0; i < mc->size; i++) {
        if (mc->keys[i] == key) {
            return mc->values[i];
        }
    }
    return 0;
}

void MapCounter_clear(MapCounter *mc) {
    mc->size = 0;
}

bool isRightMin(int *a, bool f, int index, int key) {
    if (f && a[index] >= key) return true;
    else if (!f && a[index] > key) return true;
    else return false;
}

int binarySearchRightMin(int *a, int n, bool f, int key) {
    int ng = -1;
    int ok = n;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isRightMin(a, f, mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

bool isLeftMax(int *a, bool f, int index, int key) {
    if (f && a[index] <= key) return true;
    else if (!f && a[index] < key) return true;
    else return false;
}

int binarySearchLeftMax(int *a, int n, bool f, int key) {
    int ng = -1;
    int ok = n;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isLeftMax(a, f, mid, key)) ng = mid;
        else ok = mid;
    }
    return ng;
}

void solve() {
    int H, W;
    scanf("%d %d", &H, &W);
    char C[H + 2][W + 2];
    for (int i = 0; i < H; i++) {
        scanf("%s", C[i + 1] + 1);
    }
    if (H == 1 && W == 1) {
        printf("No\n");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' 
                && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main() {
    solve();
    return 0;
}
// End of Code
