#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define BUFFER_SIZE 1048576 // 1MB buffer

static char buffer[BUFFER_SIZE];
static char *buffer_pos = buffer;
static char *buffer_end = buffer;

static int read_char() {
    if (buffer_pos == buffer_end) {
        size_t n = fread(buffer, 1, BUFFER_SIZE, stdin);
        if (n == 0) return -1;
        buffer_pos = buffer;
        buffer_end = buffer + n;
    }
    return *buffer_pos++;
}

long long read_long() {
    long long number = 0;
    int sign = 1;
    int c;

    do {
        c = read_char();
    } while (c != -1 && isspace(c));

    if (c == -1) return 0;

    if (c == '-') {
        sign = -1;
        c = read_char();
    } else if (c == '+') {
        c = read_char();
    }

    if (c == -1 || !isdigit(c)) {
        return 0;
    }

    do {
        number = number * 10 + (c - '0');
        c = read_char();
    } while (isdigit(c));

    return number * sign;
}

int read_int() {
    return (int)read_long();
}

int* read_int_array(int n) {
    int *arr = malloc(n * sizeof(int));
    if (!arr) exit(EXIT_FAILURE);
    for (int i = 0; i < n; i++) {
        arr[i] = read_int();
    }
    return arr;
}

void solve() {
    int N = read_int();
    int *A = read_int_array(N);
    long long ans = 0, sum = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        ans += (sum * (long long)A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    printf("%lld\n", ans % MOD);
    free(A);
}

int main() {
    solve();
    return 0;
}
// End of Code
