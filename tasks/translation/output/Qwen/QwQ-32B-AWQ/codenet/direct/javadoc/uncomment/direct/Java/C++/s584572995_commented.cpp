#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 +7;
vector<vector<int>> to;
vector<int> dp;

int rec(int v, int parent) {
    int res = 1;
    for (int next : to[v]) {
        if (next == parent) continue;
        res += rec(next, v);
    }
    dp[v] = res;
    return res;
}

long modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != .0) return (x * modpow(x, y-1)) % mod;
    long tmp = modpow(x, y/2);
    return (tmp * tmp) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    to.resize(N);
    dp.resize(N);
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < N-1; ++i) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        to[A].push_back(B);
        to[B].push_back(A);
        edges.emplace_back(B, A);
    }
    
    rec(0, -1);
    
    long mulsum = 0;
    for (auto e : edges) {
        int cand1 = e.first;
        int cand2 = e.second;
        int child = cand1;
        if (dp[cand1] > dp[cand2]) {
            child = cand2;
        }
        long a = dp[child];
        long b = N - a;
        long term1 = (modpow(2, a) - 1) % mod;
        long term2 = (modpow(2, b) - 1) % mod;
        long mul = (term1 * term2) % mod;
        mulsum = (mulsum + mul) % mod;
    }
    
    long cases = modpow(2, N);
    long PN = (mulsum + cases - 1 + mod) % mod;
    long BN = (long) N * modpow(2, N-1) % mod;
    long WN = (PN - BN + mod) % mod;
    
    long inv_cases = modpow(cases, mod-2);
    long ans = (WN * inv_cases) % mod;
    
    cout << ans << endl;
}

// End of Code
