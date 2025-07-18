#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class LightScanner {
private:
    istream& in;
    string buffer;
    queue<string> tokens;

public:
    LightScanner(istream& in) : in(in) {}

    string next() {
        if (tokens.empty()) {
            getline(in, buffer);
            stringstream ss(buffer);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        if (tokens.empty()) {
            throw runtime_error("No more tokens");
        }
        string res = tokens.front();
        tokens.pop();
        return res;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }
};

class LightWriter {
private:
    ostream& out;
    bool breaked = true;

public:
    LightWriter(ostream& out) : out(out) {}

    LightWriter& print(const string& s) {
        if (!breaked) {
            out << ' ';
        }
        out << s;
        breaked = false;
        return *this;
    }

    LightWriter& print(char c) {
        if (!breaked) {
            out << ' ';
        }
        out << c;
        breaked = false;
        return *this;
    }

    LightWriter& print(long long n) {
        return print(to_string(n));
    }

    LightWriter& ans(const string& s) {
        if (!breaked) {
            out << ' ';
        }
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

    void close() {
        out.flush();
    }
};

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
        vector<long long> s(a + 2);
        s[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) {
            s[i + 1] = in.nextLong();
        }
        s[a + 1] = 20000000000LL;

        vector<long long> t(b + 2);
        t[0] = -10000000000LL;
        for (int i = 0; i < b; ++i) {
            t[i + 1] = in.nextLong();
        }
        t[b + 1] = 20000000000LL;

        for (int i = 0; i < q; ++i) {
            long long x = in.nextLong();
            auto it_s = lower_bound(s.begin(), s.end(), x + 1);
            int pos_s_plus1 = it_s - s.begin();
            int prev_s = max(0, pos_s_plus1 - 1);
            long long sl = x - s[prev_s];

            auto it_t = lower_bound(t.begin(), t.end(), x + 1);
            int pos_t_plus1 = it_t - t.begin();
            int prev_t = max(0, pos_t_plus1 - 1);
            long long tl = x - t[prev_t];

            auto it_s_x = lower_bound(s.begin(), s.end(), x);
            int pos_s_x = it_s_x - s.begin();
            long long sr = s[pos_s_x] - x;

            auto it_t_x = lower_bound(t.begin(), t.end(), x);
            int pos_t_x = it_t_x - t.begin();
            long long tr = t[pos_t_x] - x;

            long long terms[] = {
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            };

            long long min_val = LLONG_MAX;
            for (long long term : terms) {
                if (term < min_val) min_val = term;
            }

            out.ansln(min_val);
        }
    }
};

int main() {
    LightScanner in(cin);
    LightWriter out(cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}
// End of Code
