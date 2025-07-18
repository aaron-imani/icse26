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
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long val = cumsum[j + 1] - cumsum[i];
            b[count++] = val;
        }
    }
    
    long long max_val = 0;
    for (int i = 0; i < count; i++) {
        if (b[i] > max_val) {
            max_val = b[i];
        }
    }
    
    long long mask = 1;
    if (max_val == 0) {
        mask = 0;
    } else {
        while (mask <= max_val) {
            mask <<= 1;
        }
        mask >>= 1;
    }
    
    while (mask > 0) {
        long long *tmp = malloc(count * sizeof(long long));
        int tmp_count = 0;
        for (int i = 0; i < count; i++) {
            if ((b[i] & mask) != 0) {
                tmp[tmp_count++] = b[i];
            }
        }
        if (tmp_count >= k) {
            free(b);
            b = tmp;
            count = tmp_count;
        } else {
            free(tmp);
        }
        mask >>= 1;
    }
    
    if (count < k) {
        printf("0\n");
    } else {
        long long ans = -1;
        for (int i = 0; i < count; i++) {
            ans &= b[i];
        }
        printf("%lld\n", ans);
    }
    
    free(a);
    free(cumsum);
    free(b);
    return 0;
}
// End of Code
