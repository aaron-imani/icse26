#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cmath>

using namespace std;

class LightScanner {
private:
    istream& in;
    queue<string> tokens;
    string currentLine;
    istringstream currentStream;
public:
    LightScanner(istream& in) : in(in) {}
    void loadNextLine() {
        if (tokens.empty()) {
            if (!getline(in, currentLine)) return;
            currentStream.str(currentLine);
            currentStream.clear();
            string token;
            while (currentStream >> token) {
                tokens.push(token);
            }
        }
    }
    string next() {
        loadNextLine();
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
    void print(char c) {
        out.put(c);
        breaked = false;
    }
    void ans(const string& s) {
        if (!breaked) out << ' ';
        out << s;
        breaked = false;
    }
    void ansln(long long n) {
        ans(to_string(n));
        ln();
    }
    void ln() {
        out << endl;
        breaked =.utils = true;
    }
    void close() { out.flush(); }
};

struct DLazyFaith {
    void solve(istream& in, ostream& out) {
        LightScanner scan(in);
        LightWriter writer(out);
        int a = scan.nextInt(), b = scan.nextInt(), q = scan.nextInt();
        vector<long long> s(a + 2);
        vector<long long> t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) {
            s[i+1] = scan.nextLong();
        }
        for (int i = 0; i < b; ++i) {
            t[i+1] = scan.nextLong();
        }
        s[a+1] = 20000000000LL;
        t[b+1] = 20000000000LL;
        for (int i = 0; i < q; ++i) {
            long long x = scan.nextLong();
            auto it_s = lower_bound(s.begin(), s.end(), x + 1);
            int idx_s = it_s - s.begin();
            int prev_s_idx = max(0, idx_s - 1);
            long long sl = x - s[prev_s_idx];
            auto it_t = lower_bound(t.begin(), t.end(), x + 1);
            int idx_t = it_t - t.begin();
            int prev_t_idx = max(0, idx_t - 1);
            long long tl = x - t[prev_t_idx];
            auto it_s2 = lower_bound(s.begin(), s.end(), x);
            int idx_s2 = it_s2 - s.begin();
            long long sr = s[idx_s2] - x;
            auto it_t2 = lower_bound(t.begin(), t.end(), x);
            int idx_t2 = it_t2 - t.begin();
            long long tr = t[idx_t2] - x;
            long long cand1 = max(sl, tl);
            long long cand2 = max(sr, tr);
            long long cand3 = 2 * sl + tr;
            long long cand4 = 2 * tl + sr;
            long long cand5 = sl + 2 * tr;
            long long cand6 = tl + 2 * sr;
            long long min_val = min({cand1, cand2, cand3, cand4, cand5, cand6});
            writer.ansln(min_val);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    DLazyFaith solver;
    solver.solve(cin, cout);
    return 0;
}

// End of Code
