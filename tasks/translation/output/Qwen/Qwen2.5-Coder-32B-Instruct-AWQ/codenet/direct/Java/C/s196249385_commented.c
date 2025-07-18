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
    int b_size = 0;
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[b_size++] = cumsum[j + 1] - cumsum[i];
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
        int tmp_size = 0;
        for (int i = 0; i < b_size; i++) {
            if (b[i] & mask) {
                b[tmp_size++] = b[i];
            }
        }

        if (tmp_size >= k) {
            b_size = tmp_size;
        }

        mask >>= 1;
    }

    if (b_size < k) {
        printf("0\n");
    } else {
        long ans = -1L;
        for (int i = 0; i < b_size; i++) {
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
