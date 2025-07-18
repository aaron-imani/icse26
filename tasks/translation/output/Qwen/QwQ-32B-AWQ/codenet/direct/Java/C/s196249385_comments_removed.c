#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long cumsum[n + 1];
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int total = n * (n + 1) / 2;
    long *b_array = malloc(total * sizeof(long));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long val = cumsum[j + 1] - cumsum[i];
            b_array[idx++] = val;
        }
    }

    long max_val = 0;
    for (int i = 0; i < total; i++) {
        if (b_array[i] > max_val) {
            max_val = b_array[i];
        }
    }

    long mask;
    if (max_val < 0) {
        mask = (long)1 << (sizeof(long) * 8 - 1);
    } else {
        mask = 1;
        while (mask <= max_val) {
            mask <<= 1;
        }
        mask >>= 1;
    }

    long *current = b_array;
    int current_size = total;

    while (mask > 0) {
        int count = 0;
        for (int i = 0; i < current_size; i++) {
            if ((current[i] & mask) != 瞠) {
                count++;
            }
        }
        if (count >= k) {
            long *new_array = malloc(count * sizeof(long));
            int j = 0;
            for (int i = 0; i < current_size; i++) {
                if ((current[i] & mask) != 0) {
                    new_array[j++] = current[i];
                }
            }
            free(current);
            current = new_array;
            current_size = count;
        }
        mask >>= 1;
    }

    if (current_size < k) {
        printf("0\n");
    } else {
        long ans = -1;
        for (int i = 0; i < current_size; i++) {
            ans &= current[i];
        }
        printf("%ld\n", ans);
    }

    free(current);
    return 0;
}
// End of Code
