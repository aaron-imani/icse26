#include <bits/stdc++.h>
using namespace std;

class FastScanner {
private:
    istream& in;
    queue<string> tokens;
public:
    FastScanner(istream& in) : in(in) {}
    string next() {
        if (tokens.empty()) {
            string line;
            if (!getline(in, line)) {
                throw runtime_error("No more input");
            }
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
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

void solve() {
    FastScanner in(cin);
    int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
    vector<long long> s(a + 2), t(b + 2);
    s[0] = -10000000000LL;
    t[0] = -10000000000LL;
    s[a + 1] = 20000000000LL;
    t[b + 1] = 20000000000LL;
    for (int i = 0; i < a; ++i) {
        s[i + 1] = in.nextLong();
    }
    for (int i = 0; i < b; ++i) {
        t[i + 1] = in.nextLong();
    }
    for (int i = 0; i < q; ++i) {
        long long x = in.nextLong();
        auto it_s_x_plus1 = lower_bound(s.begin(), s.end(), x + 1);
        int idx_s_x_plus1 = it_s_x_plus1 - s.begin();
        int prev_s = max(0, idx_s_x_plus1 - 1);
        long long sl = x - s[prev_s];
        
        auto it_t_x_plus1 = lower_bound(t.begin(), t.end(), x + 1);
        int idx_t_x_plus1 = it_t_x_plus1 - t.begin();
        int prev_t = max(0, idx_t_x_plus1 - 1);
        long long tl = x - t[prev_t];
        
        auto it_s_x = lower_bound(s.begin(), s.end(), x);
        int idx_s_x = it_s_x - s.begin();
        long long sr = s[idx_s_x] - x;
        
        auto it_t_x = lower_bound(t.begin(), t.end(), x);
        int idx_t_x = it_t_x - t.begin();
        long long tr = t[idx_t_x] - x;
        
        long long term1 = max(sl, tl);
        long long term2 = max(sr, tr);
        long long term3 = 2 * sl + tr;
        long long term4 = 2 * tl + sr;
        long long term5 = sl + 2 * tr;
        long long term6 = tl + 2 * sr;
        
        long long min_val = min({term1, term2, term3, term4, term5, term6});
        cout << min_val << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
// End of Code
