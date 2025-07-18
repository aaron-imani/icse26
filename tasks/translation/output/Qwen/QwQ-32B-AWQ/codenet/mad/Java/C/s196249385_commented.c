#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long cumsum[n + 1];
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int size_b_max = n * (n + 1) / 2;
    long long *b = malloc(size_b_max * sizeof(long long));
    int b_size = 0;
    long long max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long val = cumsum[j + 1] - cumsum[i];
            b[b_size++] = val;
            if (val > max) {
                max = val;
            }
        }
    }

    long long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

    while (mask > 0) {
        int tmp_size = 0;
        long long *tmp = malloc(b_size * sizeof(long long));
        for (int i = 0; i < b_size; i++) {
            if ((b[i] & mask) != 0) {
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
        long long ans = -1;
        for (int i = 0; i < b_size; i++) {
            ans &= b[i];
        }
        printf("%lld\n", ans);
    }

    free(b);
    return 0;
}
// End of Code
