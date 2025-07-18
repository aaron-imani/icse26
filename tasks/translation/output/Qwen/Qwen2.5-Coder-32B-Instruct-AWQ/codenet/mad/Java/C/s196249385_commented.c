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

    long long cumsum[MAX_N + 1];
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    long long *b = (long long *)malloc((n * (n + 1) / 2) * sizeof(long long));
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
        long long *tmp = (long long *)malloc((n * (n + 1) / 2) * sizeof(long long));
        int tmp_size = 0;
        for (int i = 0; i < b_size; i++) {
            if (b[i] & mask) {
                tmp[tmp_size++] = b[i];
            }
        }

        if (tmp_size >= k) {
            free(b);
            b = tmp;
            b_size = tmp_size;
        } else {
            free(tmp);
        }

        mask >>= 1;
    }

    if (b_size < k) {
        printf("0\n");
    } else {
        long long ans = -1LL;
        for (int i = 0; i < b_size; i++) {
            ans &= b[i];
        }

        printf("%lld\n", ans);
    }

    free(b);
    return 0;
}
// End of Code
