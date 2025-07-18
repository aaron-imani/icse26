#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long cumsum[MAX_N + 1] = {0};
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    long long b[MAX_N * (MAX_N + 1) / 2];
    int b_size = 0;
    long long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[b_size++] = cumsum[j + 1] - cumsum[i];
            if (b[b_size - 1] > max) {
                max = b[b_size - 1];
            }
        }
    }

    long long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

    while (mask > 0) {
        long long tmp[MAX_N * (MAX_N + 1) / 2];
        int tmp_size = 0;
        for (int i = 0; i < b_size; i++) {
            if (b[i] & mask) {
                tmp[tmp_size++] = b[i];
            }
        }
        if (tmp_size >= k) {
            b_size = tmp_size;
            for (int i = 0; i < b_size; i++) {
                b[i] = tmp[i];
            }
        }
        mask >>= 1;
    }

    if (b_size < k) {
        printf("0\n");
    } else {
        long long ans = -1;
        for (int i = 0; i < b_size; i++) {
            ans &= b[i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}
// End of Code
