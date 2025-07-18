#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int mod = 1e9 +7;

class FastScanner {
private:
    istream& in;
    string buffer;
    istringstream iss;
public:
    FastScanner(istream& is) : in(is) {}
    string next() {
        string token;
        while (true) {
            if (iss >> token) break;
            if (!getline(in, buffer)) return "";
            iss.str(buffer);
            iss.clear();
        }
        return token;
    }
    int nextInt() { return stoi(next()); }
};

void rec(int v, int parent, const vector<vector<int>>& to, vector<int>& dp) {
    dp[v] = 1;
    for (int next : to[v]) {
        if (next == parent) continue;
        rec(next, v, to, dp);
        dp[v] += dp[next];
    }
}

long long modpow(long long x, long long y) {
    if (y == 0) return 1LL;
    if (y % 2 != 0) return (x * modpow(x, y-1)) % mod;
    long long tmp = modpow(x, y/2);
    return (tmp * tmp) % mod;
}

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    vector<vector<int>> to(N);
    vector<pair<int, int>> edges;
    for (int i = 0; i < N-1; ++i) {
        int A = fs.nextInt()-1, B = fs.nextInt()-1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges.emplace_back(B, A);
    }
    vector<int> dp(N, 0);
    rec(0, -1, to, dp);
    
    long long mulsum = 0;
    for (const auto& e : edges) {
        int candidate1 = e.first, candidate2 = e.second;
        int child = (dp[candidate1] < dp[candidate2]) ? candidate1 : candidate2;
        long long a = dp[child];
        long long b = N - a;
        long long mul = ( (modpow(2, a) - 1) % mod ) * ( (modpow(2, b) - 1) % mod ) % mod;
        mulsum = (mulsum + mul) % mod;
    }
    
    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1)) % mod;
    PN = (PN + mod) % mod;
    
    long long BN = ( (long long)N * modpow(2, N-1) ) % mod;
    long long WN = ( (PN - BN) % mod + mod ) % mod;
    
    long long ans = WN * modpow(cases, mod-2) % mod;
    cout << ans << endl;
    return 0;
}
// End of Code
