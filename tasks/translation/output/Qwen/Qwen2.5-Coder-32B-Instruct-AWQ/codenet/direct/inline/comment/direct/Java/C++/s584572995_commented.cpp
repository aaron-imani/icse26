#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> to;
int dp[100005];

int rec(int v, int parent) {
    int res = 1;
    for (int next : to[v]) {
        if (next == parent) continue;
        res += rec(next, v);
    }
    return dp[v] = res;
}

long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return x * modpow(x, y - 1) % MOD;
    long long tmp = modpow(x, y / 2);
    return tmp * tmp % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    to.resize(N);
    vector<pair<int, int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        to[A].push_back(B);
        to[B].push_back(A);
        edges[i] = {B, A};
    }
    
    memset(dp, 0, sizeof(dp));
    rec(0, -1);
    
    long long mulsum = 0;
    for (auto e : edges) {
        int candidate1 = e.first;
        int candidate2 = e.second;
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;
        
        long long a = dp[child];
        long long b = N - a;
        
        long long mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % MOD;
        mulsum += mul;
        mulsum %= MOD;
    }
    
    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long long BN = N * modpow(2, N - 1) % MOD;
    long long WN = (PN - BN + MOD) % MOD;
    long long ans = WN * modpow(cases, MOD - 2) % MOD;
    
    cout << ans << endl;
    
    return 0;
}
// End of Code
