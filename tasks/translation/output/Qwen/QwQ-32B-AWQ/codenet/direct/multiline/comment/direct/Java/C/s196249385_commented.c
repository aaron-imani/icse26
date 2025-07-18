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

    int m = n * (n + 1) / 2;
    long long *b = malloc(m * sizeof(long long));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[idx++] = cumsum[j + 1] - cumsum[i];
        }
    }

    long max = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] > max) {
            max = b[i];
        }
    }

    long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

    int current_size = m;
    long long *current = b;
    while (mask > 0) {
        long long *tmp = malloc(current_size * sizeof(long long));
        int tmp_size = 0;
        for (int i = 0; i < current_size; i++) {
            if ((current[i] & mask) != 0) {
                tmp[tmp_size++] = current[i];
            }
        }
        if (tmp_size >= k) {
            free(current);
            current = tmp;
            current_size = tmp_size;
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
            ans &= current[i];
        }
        printf("%lld\n", ans);
    }

    free(current);
    return 0;
}
// End of Code
