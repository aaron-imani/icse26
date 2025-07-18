#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int readInt() {
    int sign = 1;
    int c;
    while( (c = getchar()) == ' ' || c == '\n' || c == '\t' ) { }
    if(c == '-') {
        sign = -1;
        c = getchar();
    }
    int num = 0;
    do {
        num = num * 10 + (c - '0');
        c = getchar();
    } while(c >= '0' && c <= '9');
    return num * sign;
}

int* readIntArray(int n) {
    int *arr = malloc(n * sizeof(int));
    for(int i=0; i < n; i++) {
        arr[i] = readInt();
    }
    return arr;
}

void solve() {
    int N = readInt();
    int *A = readIntArray(N);
    
    long long ans = 0;
    long long sum = A[N-1];
    for(int i = N-2; i >=0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    if(ans < 0) ans += MOD;
    printf("%lld\n", ans);
    free(A);
}

int main() {
    solve();
    return 0;
}
// End of Code
