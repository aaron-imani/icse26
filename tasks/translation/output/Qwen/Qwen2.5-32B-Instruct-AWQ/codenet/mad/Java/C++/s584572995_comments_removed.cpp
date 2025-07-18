#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    return dp[v] = res;
}

long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return x * modpow(x, y - 1) % mod;
    long long tmp = modpow(x, y / 2);
    return tmp * tmp % mod;
}

class FastScanner {
private:
    stringstream tokenizer;
    string line;

public:
    FastScanner(istream& in) {
        getline(in, line);
        tokenizer = stringstream(line);
    }

    string next() {
        if (!tokenizer) {
            getline(cin, line);
            tokenizer = stringstream(line);
        }
        string token;
        tokenizer >> token;
        return token;
    }

    long long nextLong() {
        return stoll(next());
    }

    int nextInt() {
        return stoi(next());
    }
};

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    to.resize(N);
    vector<vector<int>> edges(N - 1, vector<int>(2));
    dp.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int A = fs.nextInt() - 1, B = fs.nextInt() - 1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges[i][0] = B;
        edges[i][1] = A;
    }

    rec(0, -1);
    long long mulsum = 0;
    for (auto& e : edges) {
        int candidate1 = e[0];
        int candidate2 = e[1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;

        long long a = dp[child];
        long long b = N - a;

        long long mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod;
        mulsum += mul;
        mulsum %= mod;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long long BN = N * modpow(2, N - 1) % mod;
    long long WN = (PN - BN + mod) % mod;
    long long ans = WN * modpow(cases, mod - 2) % mod;

    cout << ans << endl;
}
// End of Code
