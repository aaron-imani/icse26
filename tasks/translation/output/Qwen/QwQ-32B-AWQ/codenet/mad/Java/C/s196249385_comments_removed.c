#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Compute cumulative sums
    long long *cumsum = malloc((n + 1) * sizeof(long long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    // Compute subarray sums and track max
    size_t max_size = (n * (n + 1)) / 2;
    long long *b = malloc(max_size * sizeof(long long));
    if (!b) {
        // handle error (assuming not needed for problem constraints)
    }
    size_t b_size = 0;
    long long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = cumsum[j + 1] - cumsum[i];
            b[b_size++] = sum;
            if (sum > max) {
                max = sum;
            }
        }
    }

    // Determine the highest set bit in max
    long long mask = 0;
    if (max != 0) {
        mask = 1LL;
        while (mask <= max) {
            mask <<= 1;
        }
        mask >>= 1;
    }

    // Process each bit from highest to lowest
    while (mask > 0) {
        int write = 0;
        for (size_t i = 0; i < b_size; i++) {
            if ((b[i] & mask) != 0) {
                b[write] = b[i];
                write++;
            }
        }
        if (write >= k) {
            b_size = write;
        }
        mask >>= 1;
    }

    // Output the result
    if (b_size < k) {
        printf("0\n");
    } else {
        long long ans = -1;
        for (size_t i = 0; i < b_size; i++) {
            ans &= b[i];
        }
        printf("%lld\n", ans);
    }

    // Free allocated memory
    free(a);
    free(cumsum);
    free(b);

    return 0;
} // End of Code
