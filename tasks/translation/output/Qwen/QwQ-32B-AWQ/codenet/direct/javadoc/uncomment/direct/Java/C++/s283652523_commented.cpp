#include <iostream>
#include <vector>
using namespace std;

class FastScanner {
public:
    int nextInt() {
        int sign = 1;
        int c;
        while ((c = getchar()) && (c < '0' || c > '9') && c != '-' && c != '+') {
            if (c == EOF) return 0;
        }
        if (c == '-') {
            sign = -1;
            c = getchar();
        }
        else if (c == '+') {
            c = getchar();
        }
        int ret = , c;
        do {
            ret = ret * 10 + (c - '0');
            c = getchar();
        } while (c >= '0' && c <= '9');
        return ret * sign;
    }

    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = nextInt();
        return res;
    }
};

const int MOD = 1e9 + 7;

void solve(FastScanner& in) {
    int N = in.nextInt();
    vector<int> A = in.nextIntArray(N);
    long long ans = 0, sum = A.back();
    for (int i = N - 2; i >= 0; --i) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    cout << ans << endl;
}

int main() {
    FastScanner in;
    solve(in);
    return 0;
}
// End of Code
