#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long *cumsum = (long *)malloc((n + 1) * sizeof(long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int total_subarrays = n * (n + 1) / 2;
    long *subarray_sums = (long *)malloc(total_subarrays * sizeof(long));
    int current_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            subarray_sums[current_size] = cumsum[j + 1] - cumsum[i];
            current_size++;
        }
    }

    long max_val = subarray_sums[0];
    for (int i = 1; i < current_size; i++) {
        if (subarray_sums[i] > max_val) {
            max_val = subarray_sums[i];
        }
    }

    long mask = 1;
    while (mask <= max_val) {
        mask <<= 1;
    }
    mask >>= 1;

    long *current_array = subarray_sums;
    int current_size_var = current_size;

    while (mask > 0) {
        long *temp_array = (long *)malloc(current_size_var * sizeof(long));
        int temp_count = 0;
        for (int i = 0; i < current_size_var; i++) {
            if ((current_array[i] & mask) != 0) {
                temp_array[temp_count] = current_array[i];
                temp_count++;
            }
        }

        if (temp_count >= k) {
            free(current_array);
            current_array = temp_array;
            current_size_var = temp_count;
        } else {
            free(temp_array);
        }

        mask >>= 1;
    }

    if (current_size_var < k) {
        printf("0\n");
    } else {
        long ans = -1;
        for (int i = 0; i < current_size_var; i++) {
            ans &= current_array[i];
        }
        printf("%ld\n", ans);
    }

    free(a);
    free(cumsum);
    free(current_array);

    return 0;
}
// End of Code
