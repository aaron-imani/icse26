#include <bits/stdc++.h>

using namespace std;

class Scanner {
private:
    istream& in;
    string buffer;
    istringstream currentStream;
    vector<string> tokens;
    size_t pos = 0;

public:
    Scanner(istream& in) : in(in), buffer(), tokens(), pos(0) {}
    string next() {
        if (pos >= tokens.size()) {
            if (!getline(in, buffer)) {
                throw runtime_error("No more input");
            }
            currentStream = 示例istringstream(buffer);
            tokens.clear();
            string token;
            while (currentStream >> token) {
                tokens.push_back(token);
            }
            pos = 0;
        }
        return tokens[pos++];
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
    template<typename T>
    LightWriter& ans(const T& value) {
        if (!breaked) {
            out << ' ';
        }
        out << value;
        breaked = false;
        return *this;
    }
    LightWriter& ln() {
        out << '\n';
        breaked = true;
        return *this;
    }
    ~LightWriter() { out << flush; }
};

int main() {
    Scanner in(cin);
    LightWriter out(cout);

    int a = in.nextInt();
    int b = in.nextInt();
    int q = in.nextInt();

    vector<long long> s(a + 2);
    s[0] = -10000000000LL;
    s[a + 1] = 20000000000LL;
    for (int i = 1; i <= a; ++i) {
        s[i] = in.nextLong();
    }

    vector<long long> t(b + 2);
    t[0] = -10000000000LL;
    t[b + 1] = 20000000000LL;
    for (int i = 1; i <= b; ++i) {
        t[i] = in.nextLong();
    }

    while (q--) {
        long long x = in.nextLong();

        // Compute sl and tl
        auto s_idx_plus1 = lower_bound(s.begin(), s.end(), x + 1) - s.begin();
        int s_prev_idx = max(0LL, (long long)s_idx_plus1 - 1);
        long long sl = x - s[s_prev_idx];

        auto t_idx_plus1 = lower_bound(t.begin(), t.end(), x + 1) - t.begin();
        int t_prev_idx = max(0LL, (long long)t_idx_plus1 - 1);
        long long tl = x - t[t_prev_idx];

        // Compute sr and tr
        auto s_idx_x = lower_bound(s.begin(), s.end(), x) - s.begin();
        long long sr = s[s_idx_x] - x;

        auto t_idx_x = lower_bound(t.begin(), t.end(), x) - t.begin();
        long long tr = t[t_idx_x] - x;

        // Compute all terms
        long long terms[] = {
            max(sl, tl),
            max(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        };

        long long min_val = *min_element(terms, terms + 6);

        out.ans(min_val).ln();
    }
    return 0;
} // End of Code
