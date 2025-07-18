#include <iostream>
#include <vector>
#include <string>
#include <utility> // for pair
using namespace std;

const int mod = 1e9 +7;

vector<vector<int>> to; // adjacency list
vector<int> dp; // dp array for subtree sizes

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
    if (y % 2 != .0) return (x * modpow(x, y-1)) % mod;
    long long tmp = modpow(x, y/2);
    return (tmp * tmp) % mod;
}

class FastScanner {
private:
    istream& in;
    string buffer;
    istringstream stream;
public:
    FastScanner(istream& i) : in(i) {}
    string next() {
        if (!stream) {
            getline(in, buffer);
            stream = istringstream(buffer);
        }
        string token;
        stream >> token;
        return token;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    to.resize(N);
    vector<pair<int, int>> edges;
    for (int i = 0; i < N-1; ++i) {
        int A = fs.nextInt()-1, B = fs.nextInt()-1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges.push_back({B, A});
    }
    dp.resize(N);
    rec(0, -1);

    long long mulsum = 0;
    for (auto& e : edges) {
        int candidate1 = e.first, candidate2 = e.second;
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;
        long long a = dp[child];
        long long b = N - a;
        long long term = (modpow(2, a) - 1) % mod;
        term = (term * (modpow(2, b) - 1) % mod) % mod;
        mulsum = (mulsum + term) % mod;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long long BN = (static_cast<long long>(N) * modpow(2, N-1)) % mod;
    long long WN = (PN - BN + mod) % mod;
    long long ans = WN * modpow(cases, mod - 2) % mod;
    cout << ans << endl;
}

// End of Code
