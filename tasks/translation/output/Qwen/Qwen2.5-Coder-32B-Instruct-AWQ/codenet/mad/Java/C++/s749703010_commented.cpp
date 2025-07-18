// End of Code
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

const int MAX_N = 20;
const int INF = 1e9;
int n;
int memo[2][MAX_N + 1][1 << MAX_N];
vector<vector<int>> a(2, vector<int>(MAX_N));

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = INF;
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

    string next() {
        if (tokenIndex >= tokens.size()) {
            getline(in, buffer);
            tokens.clear();
            stringstream ss(buffer);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            tokenIndex = 0;
        }
        return tokens[tokenIndex++];
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    string nextLine() {
        string line;
        getline(in, line);
        return line;
    }

    double nextDouble() {
        return stod(next());
    }

    bool ready() {
        return in.peek() != EOF;
    }
};

int main() {
    Scanner sc(cin);
    n = sc.nextInt();
    for (int i = 0; i < n; i++) a[0][i] = sc.nextInt();
    for (int i = 0; i < n; i++) a[1][i] = sc.nextInt();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < (1 << n); k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    int ans = dp(0, n, 0);
    cout << (ans >= INF ? -1 : ans) << endl;
    return 0;
}
// End of Code
