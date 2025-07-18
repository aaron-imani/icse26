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
    long *arr = (long *)malloc(total * sizeof(long));
    if (!arr) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long sum = cumsum[j + 1] - cumsum[i];
            arr[count++] = sum;
        }
    }

    // Compute max_val
    long max_val = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Compute mask using unsigned approach
    unsigned long u_max = (unsigned long)max_val;
    long mask = 1L;
    if (u_max == 0) {
        mask = 0;
    } else {
        while (mask <= u_max) {
            mask <<= 1;
        }
        mask >>= 1;
    }

    // Process the mask loop
    while (mask > 0) {
        long *temp = (long *)malloc(count * sizeof(long));
        if (!temp) {
            free(arr);
            return 1;
        }
        int temp_count = 0;
        for (int i = 0; i < count; i++) {
            if ((arr[i] & mask) != 0) {
                temp[temp_count++] = arr[i];
            }
        }
        if (temp_count >= k) {
            free(arr);
            arr = temp;
            count = temp_count;
        } else {
            free(temp);
        }
        mask >>= 1;
    }

    // Output result
    if (count < k) {
        printf("0\n");
    } else {
        long ans = -1;
        for (int i = 0; i < count; i++) {
            ans &= arr[i];
        }
        printf("%ld\n", ans);
    }

    free(arr);
    return 0;
}
// End of Code
