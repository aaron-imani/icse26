#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int compare(const void *a, const void *b) {
    return (*(long *)b - *(long *)a);
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long cumsum[MAX_N + 1];
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    long b[MAX_N * (MAX_N + 1) / 2];
    int size_b = 0;
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[size_b++] = cumsum[j + 1] - cumsum[i];
            if (cumsum[j + 1] - cumsum[i] > max) {
                max = cumsum[j + 1] - cumsum[i];
            }
        }
    }

    long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

    while (mask > 0) {
        long tmp[MAX_N * (MAX_N + 1) / 2];
        int size_tmp = 0;
        for (int i = 0; i < size_b; i++) {
            if (b[i] & mask) {
                tmp[size_tmp++] = b[i];
            }
        }

        if (size_tmp >= k) {
            size_b = size_tmp;
            for (int i = 0; i < size_b; i++) {
                b[i] = tmp[i];
            }
        }

        mask >>= 1;
    }

    if (size_b < k) {
        printf("0\n");
    } else {
        long ans = -1L;
        for (int i = 0; i < size_b; i++) {
            ans &= b[i];
        }

        printf("%ld\n", ans);
    }
}

int main() {
    solve();
    return 0;
}
// End of Code
