#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#include <cstddef>
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
            if (!getline(in, line)) throw runtime_error("Could not read line");
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        if (tokens.empty()) throw runtime_error("No token available");
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
    bool autoflush;
    bool breaked;
public:
    LightWriter(ostream& out) : out(out), autoflush(false), breaked(true) {}
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
        if (!breaked) print(' ');
        return print(s);
    }
    LightWriter& ans(long long n) {
        return ans(to_string(n));
    }
    LightWriter& ansln(long long n) {
        ans(n).ln();
        return *this;
    }
    LightWriter& ln() {
        out << endl;
        breaked = true;
        if (autoflush) out.flush();
        return *this;
    }
    void close() { out.flush(); }
};

int lowerBound(const vector<long long>& arr, long long target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.nextInt();
        int b = in.nextInt();
        int q = in.nextInt();
        vector<long long> s(a+2);
        vector<long long> t(b+2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; i++) {
            s[i+1] = in.nextLong();
        }
        s[a+1] = 20000000000LL;
        for (int i = 0; i < b; i++) {
            t[i+1] = in.nextLong();
        }
        t[b+1] = 20000000000LL;
        for (int i = 0; i < q; i++) {
            long long x = in.nextLong();
            int s_lb = lowerBound(s, x + 1);
            int s_pos = max(0, s_lb - 1);
            long sl = x - s[s_pos];
            int t_lb = lowerBound(t, x + 1);
            int t_pos = max(0, t_lb - 1);
            long tl = x - t[t_pos];
            int s_next = lowerBound(s, x);
            long sr = s[s_next] - x;
            int t_next = lowerBound(t, x);
            long tr = t[t_next] - x;
            long option1 = max(sl, tl);
            long option2 = max(sr, tr);
            long option3 = 2 * sl + tr;
            long option4 = 2 * tl + sr;
            long option5 = sl + 2 * tr;
            long option6 = tl + 2 * sr;
            long min_val = min({option1, option2, option3, option4, option5, option6});
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
