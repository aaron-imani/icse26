#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

class FastScanner {
private:
    istream& in;
public:
    FastScanner(istream& is = cin) : in(is) {}
    int nextInt();
    long long nextLong();
    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = nextInt();
        return res;
    }
};

int FastScanner::nextInt() {
    int sign = 1;
    int c = in.get();
    while (isspace(c)) c = in.get();
    if (c == '-') {
        sign = -1;
        c = in.get();
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
        c = in.get();
    }
    return ret * sign;
}

long long FastScanner::nextLong() {
    long long sign = 1;
    int c = in.get();
    while (isspace(c)) c = in.get();
    if (c == '-') {
        sign = -1;
        c = in.get();
    }
    long long ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
        c = in.get();
    }
    return ret * sign;
}

void solve() {
    FastScanner in;
    int N = in.nextInt();
    vector<int> A = in.nextIntArray(N);
    long long ans = 0, sum = A.back();
    for (int i = N - 2; i >= 0; --i) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
// End of Code
