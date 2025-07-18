#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long *cumsum = (long long*)malloc((n + 1) * sizeof(long long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    int m = n * (n + 1) / 2;
    long long *elements = (long long*)malloc(m * sizeof(long long));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            elements[count] = cumsum[j + 1] - cumsum[i];
            count++;
        }
    }

    long long max = elements[0];
    for (int i = 1; i < m; i++) {
        if (elements[i] > max) {
            max = elements[i];
        }
    }

    long long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

    long long *current_arr = (long long*)malloc(m * sizeof(long long));
    long long *next_arr = (long long*)malloc(m * sizeof(long long));
    for (int i = 0; i < m; i++) {
        current_arr[i] = elements[i];
    }
    int current_count = m;

    while (mask > 0) {
        int next_count = 0;
        for (int i = 0; i < current_count; i++) {
            long long e = current_arr[i];
            if ((e & mask) != 0) {
                next_arr[next_count] = e;
                next_count++;
            }
        }
        if (next_count >= k) {
            for (int i = 0; i < next_count; i++) {
                current_arr[i] = next_arr[i];
            }
            current_count = next_count;
        }
        mask >>= 1;
    }

    if (current_count < k) {
        printf("0\n");
    } else {
        long long ans = -1;
        for (int i = 0; i < current_count; i++) {
            ans &= current_arr[i];
        }
        printf("%lld\n", ans);
    }

    free(a);
    free(cumsum);
    free(elements);
    free(current_arr);
    free(next_arr);

    return 0;
}
// End of Code
