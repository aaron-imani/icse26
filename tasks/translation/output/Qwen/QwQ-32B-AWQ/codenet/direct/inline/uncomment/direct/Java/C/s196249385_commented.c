#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    long cumsum[n + 1];
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int max_size = n * (n + 1) / 2;
    long *b = malloc(max_size * sizeof(long));
    int b_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long sum = cumsum[j + 1] - cumsum[i];
            b[b_count++] = sum;
        }
    }

    long max = b[0];
    for (int i = 1; i < b_count; i++) {
        if (b[i] > max) {
            max = b[i];
        }
    }

    long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

    long *current = malloc(max_size * sizeof(long));
    long *tmp = malloc(max_size * sizeof(long));
    for (int i = 0; i < b_count; i++) {
        current[i] = b[i];
    }
    int current_size = b_count;
    free(b);

    while (mask > 0) {
        int tmp_count = 0;
        for (int i = 0; i < current_size; i++) {
            if ((current[i] & mask) != 0) {
                tmp[tmp_count++] = current[i];
            }
        }
        if (tmp_count >= k) {
            long *temp_ptr = current;
            current = tmp;
            tmp = temp_ptr;
            current_size = tmp_count;
        }
        mask >>= 1;
    }

    if (current_size >= k) {
        long ans = current[0];
        for (int i = 1; i < current_size; i++) {
            ans &= current[i];
        }
        printf("%ld\n", ans);
    } else {
        printf("0\n");
    }

    free(current);
    free(tmp);

    return 0;
}
// End of Code
