#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long long *a = malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long *cumsum = malloc((n + 1) * sizeof(long long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int size_b = n * (n + 1) / 2;
    long long *b = malloc(size_b * sizeof(long long));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[count++] = cumsum[j + 1] - cumsum[i];
        }
    }

    long long max = 0;
    for (int i = 0; i < size_b; i++) {
        if (b[i] > max) {
            max = b[i];
        }
    }

    long long mask;
    if (max == 0) {
        mask = 0;
    } else {
        mask = 1;
        while (mask <= max) {
            mask <<= 1;
        }
        mask >>= 1;
    }

    long long *current_b = b;
    int current_size = size_b;

    while (mask > 0) {
        int tmp_count = 0;
        long long *tmp = malloc(current_size * sizeof(long long));
        for (int i = 0; i < current_size; i++) {
            if ((current_b[i] & mask) != 0) {
                tmp[tmp_count++] = current_b[i];
            }
        }
        if (tmp_count >= k) {
            free(current_b);
            current_b = tmp;
            current_size = tmp_count;
        } else {
            free(tmp);
        }
        mask >>= 1;
    }

    if (current_size < k) {
        printf("0\n");
    } else {
        long long ans = -1;
        for (int i = 0; i < current_size; i++) {
            ans &= current_b[i];
        }
        printf("%lld\n", ans);
    }

    free(a);
    free(cumsum);
    free(current_b);

    return 0;
}
// End of Code
