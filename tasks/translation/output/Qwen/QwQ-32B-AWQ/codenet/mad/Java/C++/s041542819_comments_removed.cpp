#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

struct LightScanner {
    istream& in;
    string line;
    deque<string> tokens;

    LightScanner(istream& in) : in(in) {}

    string next() {
        while (tokens.empty()) {
            if (!getline(in, line)) break;
            stringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
        }
        if (tokens.empty()) throw runtime_error("No more tokens");
        string res = tokens.front();
        tokens.pop_front();
        return res;
    }

    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

class LightWriter {
    ostream& out;
    bool breaked = true;

public:
    LightWriter(ostream& out) : out(out) {}

    LightWriter& print(char c) {
        out.put(c);
        breaked = false;
        return *this;
    }

    LightWriter& print(const string& s) {
        out << s;
        breaked = false;
        return *this;
    }

    LightWriter& ans(const string& s) {
        if (!breaked) out << ' ';
        out << s;
        breaked = false;
        return *this;
    }

    LightWriter& ans(long long n) {
        return ans(to_string(n));
    }

    LightWriter& ansln(long long n) {
        ans(n).ln();
        return *this;
    }

    LightWriter& ln() {
        out << '\n';
        breaked = true;
        return *this;
    }

    void close() { out.flush(); }
};

int lower_bound(const vector<long long>& arr, long long target, int start = 0) {
    int low = start, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (target <= arr[mid]) high = mid;
        else low = mid + 1;
    }
    return low;
}

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
        vector<long long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) {
            s[i+1] = in.nextLong();
        }
        for (int i = 0; i < b; ++i) {
            t[i+1] = in.nextLong();
        }
        s[a+1] = 20000000000LL;
        t[b+1] = 20000000000LL;

        for (int i = 0; i < q; ++i) {
            long long x = in.nextLong();
            int s_idx = lower_bound(s, x + 1);
            int prev_s = max(0, s_idx - 1);
            long long sl = x - s[prev_s];

            int t_idx = lower_bound(t, x + 1);
            int prev_t = max(0, t_idx - 1);
            long long tl = x - t[prev_t];

            int s_r_idx = lower_bound(s, x);
            long long sr = s[s_r_idx] - x;

            int t_r_idx = lower_bound(t, x);
            long long tr = t[t_r_idx] - x;

            long long option1 = max(sl, tl);
            long long option2 = max(sr, tr);
            long long option3 = 2 * sl + tr;
            long long option4 = 2 * tl + sr;
            long long option5 = sl + 2 * tr;
            long long option6 = tl + 2 * sr;

            vector<long long> options = {option1, option2, option3, option4, option5, option6};
            long long min_val = *min_element(options.begin(), options.end());
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
