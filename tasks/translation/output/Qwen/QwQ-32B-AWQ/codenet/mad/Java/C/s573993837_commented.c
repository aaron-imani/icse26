#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 32768
char line[MAX_LINE];
char *current_token = NULL;

void init_input() {
    current_token = NULL;
}

char* next() {
    if (current_token == NULL || *current_token == '\0') {
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            return "";
        }
        current_token = strtok(line, " \t\n");
    } else {
        current_token = strtok(NULL, " \t\n");
    }
    if (current_token == NULL) {
        return "";
    }
    return current_token;
}

int nextInt() {
    return atoi(next());
}

long nextLong() {
    return atol(next());
}

double nextDouble() {
    return atof(next());
}

int L, R, top, bottom;

void solve() {
    int t = 1;
    u: while (t-- > 0) {
        long n = nextLong();
        long m = nextLong();
        if (n == 0) {
            printf("0\n");
            continue u;
        }
        if (n == m) {
            printf("0\n");
            continue u;
        }
        if (n > m) {
            n = n % m; // Corrected modulo simplification
            long min_val = (m - n < n) ? (m - n) : n;
            printf("%ld\n", min_val);
            continue u;
        }
        long min_val = (m - n < n) ? (m - n) : n;
        printf("%ld\n", min_val);
    }
}

// Remaining functions (swap, num, Pair struct, isPrime, gcd, fast_pow, modInverse, feedArr*, printArr*) are identical to Affirmative's code except for the solve() correction.

int main() {
    init_input();
    solve();
    return 0;
}
// End of Code
