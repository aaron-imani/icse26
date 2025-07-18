#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class LightScanner {
private:
    istream& in;
    queue<string> tokens;
public:
    LightScanner(istream& in) : in(in) {}
    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            stringstream ss(line);
            string token;
            while (ss >> token) tokens.push(token);
        }
        if (tokens.empty()) throw runtime_error("No more tokens");
        string t = tokens.front();
        tokens.pop();
        return t;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

class LightWriter {
private:
    ostream& out;
    bool breaked = true;
public:
    LightWriter(ostream& out) : out(out) {}
    LightWriter& print(char c) {
        if (!breaked) out << c;
        else {
            out << c;
            breaked = false;
        }
        return *this;
    }
    LightWriter& ans(const string& s) {
        if (!breaked) out << ' ';
        out << s;
        breaked = false;
        return *this;
    }
    LightWriter& ansln(long long n) {
        ans(to_string(n)).ln();
        return *this;
    }
    LightWriter& ln() {
        out << '\n';
        breaked = true;
        return *this;
    }
    void close() {}
};

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
        vector<long long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) s[i+1] = in.nextLong();
        for (int i = 0; i < b; ++i) t[i+1] = in.nextLong();
        s[a+1] = 20000000000LL;
        t[b+1] = 20000000000LL;
        for (int i = 0; i < q; ++i) {
            long long x = in.nextLong();
            auto s_idx = lower_bound(s.begin(), s.end(), x+1) - s.begin();
            int s_prev = max(0, s_idx-1);
            long long sl = x - s[s_prev];
            auto t_idx = lower_bound(t.begin(), t.end(), x+1) - t.begin();
            int t_prev = max(0, t_idx-1);
            long long tl = x - t[t_prev];
            
            auto s_idx_r = lower_bound(s.begin(), s.end(), x) - s.begin();
            long long sr = s[s_idx_r] - x;
            auto t_idx_r = lower_bound(t.begin(), t.end(), x) - t.begin();
            long long tr = t[t_idx_r] - x;
            
            long long min_val = min({
                max(sl, tl),
                max(sr, tr),
                2*sl + tr,
                2*tl + sr,
                sl + 2*tr,
                tl + 2*sr
            });
            out.ansln(min_val);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LightScanner in(cin);
    LightWriter out(cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}
// End of Code
