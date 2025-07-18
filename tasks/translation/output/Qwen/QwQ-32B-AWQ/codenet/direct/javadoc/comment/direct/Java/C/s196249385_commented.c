#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long *cumsum = malloc((n + 1) * sizeof(long long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int max_size = n * (n + 1) / 2;
    long long *b = malloc(max_size * sizeof(long long));
    int count = 0;
    long long max_val = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = cumsum[j + 1] - cumsum[i];
            b[count++] = sum;
            if (sum > max_val) {
                max_val = sum;
            }
        }
    }

    long long mask = 1;
    while (mask <= max_val) {
        mask <<= 1;
    }
    mask >>= 1;

    long long *current_b = b;
    int current_size = count;

    while (mask > 0) {
        long long *tmp = malloc(current_size * sizeof(long long));
        int tmp_count = 0;
        for (int i = 0; i < current_size; i++) {
            long long e = current_b[i];
            if ((e & mask) != 0) {
                tmp[tmp_count++] = e;
            }
        }

        if (tmp_count >= k) {
            long long *old_current_b = current_b;
            current_b = tmp;
            current_size = tmp_count;
            free(old_current_b);
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
