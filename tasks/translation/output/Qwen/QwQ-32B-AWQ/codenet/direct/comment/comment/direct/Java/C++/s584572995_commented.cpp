#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<vector<int>> to;
vector<int> dp;

long modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) {
        return (x * modpow(x, y - 1)) % mod;
    }
    long tmp = modpow(x, y / 2);
    return (tmp * tmp) % mod;
}

int rec(int v, int parent) {
    int res = 1;
    for (int next : to[v]) {
        if (next == parent) continue;
        res += rec(next, v);
    }
    dp[v] = res;
    return res;
}

class FastScanner {
private:
    istream& in;
    string currLine;
    vector<string> tokens;
    int ptr;

public:
    FastScanner(istream& _in) : in(_in), currLine(""), tokens(), ptr(0) {}

    string next() {
        if (ptr >= tokens.size()) {
            if (!getline(in, currLine)) return "";
            stringstream ss(currLine);
            tokens.clear();
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            ptr = 0;
        }
        if (ptr >= tokens.size()) return "";
        return tokens[ptr++];
    }

    int nextInt() {
        string s = next();
        return stoi(s);
    }

    long long nextLong() {
        string s = next();
        return stoll(s);
    }
};

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    to.resize(N);
    vector<pair<int, int>> edges;
    for (int i = 0; i < N - 1; i++) {
        int A = fs.nextInt() - 1;
        int B = fs.nextInt() - 1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges.push_back(make_pair(B, A));
    }
    dp.resize(N);
    rec(0, -1);
    long mulsum = 0;
    for (auto& e : edges) {
        int c1 = e.first;
        int c2 = e.second;
        int child = c1;
        if (dp[c1] > dp[c2]) {
            child = c2;
        }
        long a = dp[child];
        long b = N - a;
        long partA = (modpow(2, a) - 1) % mod;
        long partB = (modpow(2, b) - 1) % mod;
        long mul = (partA * partB) % mod;
        mulsum = (mulsum + mul) % mod;
    }
    long cases = modpow(,
    long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long BN = static_cast<long>(N) * modpow(2, N - 1) % mod;
    long WN = (PN - BN + mod) % mod;
    long invCases = modpow(cases, mod - 2);
    long ans = WN * invCases % mod;
    cout << ans << endl;
    return 0;
}
// End of Code
