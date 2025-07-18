#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;

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

long long modpow(long long x, long long y) {
    if (y == 0) return 1LL;
    if (y % 2 != 0) return (x * modpow(x, y-1)) % mod;
    long long tmp = modpow(x, y/2);
    return (tmp * tmp) % mod;
}

class FastScanner {
private:
    istream& in;
    queue<string> tokens;
public:
    FastScanner(istream& in) : in(in) {}
    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            istringstream iss(line);
            string token;
            while (iss >> token) tokens.push(token);
        }
        string result = tokens.front();
        tokens.pop();
        return result;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    to.resize(N);
    vector<pair<int, int>> edges(N-1);
    for (int i = 0; i < N-1; ++i) {
        int A = fs.nextInt()-1, B = fs.nextInt()-1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges[i] = {B, A};
    }
    dp.resize(N);
    rec(0, -1);

    long long mulsum = 0;
    for (const auto& e : edges) {
        int candidate1 = e.first;
        int candidate2 = e.second;
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) {
            child = candidate2;
        }
        long long a = dp[child];
        long long b = N - a;
        long long term1 = (modpow(2, a) - 1) % mod;
        long long term2 = (modpow(2, b) - 1) % mod;
        long long mul = (term1 * term2) % mod;
        mulsum = (mulsum + mul) % mod;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod) % mod) % mod;

    long long BN = (static_cast<long long>(N) * modpow(2, N-1)) % mod;
    long long WN = (PN - BN + mod) % mod;

    long long invCases = modpow(cases, mod - 2);
    long long ans = (WN * invCases) % mod;

    cout << ans << endl;
    return 0;
}
// End of Code
