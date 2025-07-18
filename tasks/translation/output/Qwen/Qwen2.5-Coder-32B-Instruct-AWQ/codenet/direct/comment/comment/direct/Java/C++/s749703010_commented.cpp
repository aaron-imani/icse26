#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>

using namespace std;

class Pair {
public:
    int l, r;
    Pair(int a, int b) : l(a), r(b) {}
    
    string toString() {
        return to_string(l) + " " + to_string(r);
    }
};

int n;
int memo[2][105][1 << 10];
int a[2][105];

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)));
            }
            ff++;
        } else x--;
    }
    return memo[fliped][idx][msk] = ans;
}

class Scanner {
private:
    istream& in;
    string buffer;
    vector<string> tokens;
    size_t tokenIndex;

public:
    Scanner(istream& stream) : in(stream), tokenIndex(0) {}

    bool readNext() {
        if (tokenIndex < tokens.size()) return true;
        string line;
        if (!getline(in, line)) return false;
        tokens.clear();
        stringstream ss(line);
        string token;
        while (ss >> token) tokens.push_back(token);
        tokenIndex = 0;
        return !tokens.empty();
    }

    template<typename T>
    T next() {
        if (!readNext()) throw runtime_error("No more input");
        T result;
        stringstream ss(tokens[tokenIndex++]);
        ss >> result;
        return result;
    }

    int nextInt() { return next<int>(); }
    long long nextLong() { return next<long long>(); }
    string nextLine() {
        getline(in, buffer);
        return buffer;
    }
    double nextDouble() { return next<double>(); }
};

int main() {
    Scanner sc(cin);
    n = sc.nextInt();
    for (int i = 0; i < n; i++) a[0][i] = sc.nextInt();
    for (int i = 0; i < n; i++) a[1][i] = sc.nextInt();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            fill(memo[i][j], memo[i][j] + (1 << n), -1);
        }
    }
    int ans = dp(0, n, 0);
    cout << (ans >= 1e8 ? -1 : ans) << endl;
    return 0;
}
// End of Code
