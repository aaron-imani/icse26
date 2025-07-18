#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MOD = 1e9 +7;

class FastScanner {
private:
    FILE *in;
public:
    FastScanner() : in(stdin) {}
    int nextInt() {
        int c = getchar();
        while (c != '-' && (c < '0' || c > '9')) c = getchar();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = getchar();
        }
        int res = 0;
        do {
            res = res * 10 + c - '0';
            c = getchar();
        } while (c >= '0' && c <= '9');
        return res * sign;
    }
};

void solve() {
    FastScanner in;
    int N = in.nextInt();
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = in.nextInt();
    }
    long long ans = 0;
    long long sum = A.back();
    for (int i = N - 2; i >= 0; --i) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
