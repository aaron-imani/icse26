#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int mod = 1e9 + 7;

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
            while (iss >> token) {
                tokens.push(token);
            }
        }
        string result = tokens.front();
        tokens.pop();
        return result;
    }

    string nextLine() {
        string line;
        getline(in, line);
        return line;
    }

    long long nextLong() {
        return stoll(next());
    }

    int nextInt() {
        return stoi(next());
    }

    double nextDouble() {
        return stod(next());
    }

    vector<int> nextIntArray(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        return a;
    }

    vector<long long> nextLongArray(int n) {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = nextLong();
        }
        return a;
    }
};

long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return (x * modpow(x, y - 1)) % mod;
    long long tmp = modpow(x, y / 2);
    return (tmp * tmp) % mod;
}

int rec(int v, int parent, const vector<vector<int>>& to, vector<int>& dp) {
    int res = 1;
    for (int next : to[v]) {
        if (next == parent) continue;
        res += rec(next, v, to, dp);
    }
    dp[v] = res;
    return res;
}

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    vector<vector<int>> to(N);
    vector<pair<int, int>> edges;
    for (int i = 0; i < N - 1; ++i) {
        int A = fs.nextInt() - 1, B = fs.nextInt() - 1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges.emplace_back(B, A);
    }
    vector<int> dp(N);
    rec(0, -1, to, dp);

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
        long long termA = (modpow(2, a) - 1) % mod;
        long long termB = (modpow(2, b) - 1) % mod;
        long long term = (termA * termB) % mod;
        mulsum = (mulsum + term) % mod;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod) % mod) % mod;

    long long BN = (static_cast<long long>(N) * modpow(2, N - 1)) % mod;
    long long WN = (PN - BN + mod) % mod;

    long long ans = WN * modpow(cases, mod - 2) % mod;

    cout << ans << endl;
    return 0;
}
// End of Code
