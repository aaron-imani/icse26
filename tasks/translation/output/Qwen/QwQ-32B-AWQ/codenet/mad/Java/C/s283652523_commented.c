#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MOD 1000000007

typedef long long ll;

int readInt() {
    int c;
    while ((c = getchar()) != EOF && isspace(c));
    if (c == EOF) return 0;
    int sign = 1;
    if (c == '-') {
        sign = -1;
        c = getchar();
    }
    ll num = 0;
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    return (int)(num * sign);
}

int main() {
    int N = readInt();
    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        A[i] = readInt();
    }
    ll ans = 0;
    ll sum = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        ans = (ans + (sum * A[i]) % MOD) % MOD;
        sum = (sum + A[i]) % MOD;
    }
    printf("%lld\n", ans % MOD);
    free(A);
    return 0;
}
// End of Code
