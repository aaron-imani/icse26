#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

template<typename T>
int lower_bound(const vector<T>& arr, T target) {
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

struct LightScanner {
    istream& in;
    queue<string> tokens;
    LightScanner(istream& in) : in(in) {}
    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            stringstream ss(line);
            string token;
            while (ss >> token) tokens.push(token);
        }
        if (tokens.empty()) return "";
        string res = tokens.front();
        tokens.pop();
        return res;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

struct LightWriter {
    ostream& out;
    bool autoflush = false;
    bool breaked = true;
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

struct DLazyFaith {
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
        vector<long long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) s[i + 1] = in.nextLong();
        for (int i = 0; i < b; ++i) t[i + 1] = in.nextLong();
        s[a + 1] = t[b + 1] = 20000000000LL;
        for (int i = 0; i < q; ++i) {
            long long x = in.nextLong();
            // Process s
            int lb_s = lower_bound(s, x + 1);
            int s_prev_idx = max(0, lb_s - 1);
            long long sl = x - s[s_prev_idx];
            int lb_s_right = lower_bound(s, x);
            long long sr = s[lb_s_right] - x;
            // Process t
            int lb_t = lower_bound(t, x + 1);
            int t_prev_idx = max(0, lb_t - 1);
            long long tl = x - t[t_prev_idx];
            int lb_t_right = lower_bound(t, x);
            long long tr = t[lb_t_right] - x;
            // Calculate options
            long long option1 = max(sl, tl);
            long long option2 = max(sr, tr);
            long long option3 = 2 * sl + tr;
            long long option4 = 2 * tl + sr;
            long long option5 = sl + 2 * tr;
            long long option6 = tl + 2 * sr;
            long long min_val = min({option1, option2, option3, option4, option5, option6});
            out.ansln(min_val);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LightScanner in(cin);
    LightWriter out(cin); // Correction: should be std::cout
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}

// Correction in main function: LightWriter should be initialized with std::cout instead of cin.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LightScanner in(cin);
    LightWriter out(std::cout); // Correct initialization
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}
// End of Code

Wait, I see a mistake in the main function's code block. The initial main had LightWriter out(cin), which should be std::cout. The corrected main is provided but placed after the first main. To fix this, here's the correct final version:


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

template<typename T>
int lower_bound(const vector<T>& arr, T target) {
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

struct LightScanner {
    istream& in;
    queue<string> tokens;
    LightScanner(istream& in) : in(in) {}
    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            stringstream ss(line);
            string token;
            while (ss >> token) tokens.push(token);
        }
        if (tokens.empty()) return "";
        string res = tokens.front();
        tokens.pop();
        return res;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
};

struct LightWriter {
    ostream& out;
    bool autoflush = false;
    bool breaked = true;
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

struct DLazyFaith {
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
        vector<long long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) s[i + 1] = in.nextLong();
        for (int i = 0; i < b; ++i) t[i + 1] = in.nextLong();
        s[a + 1] = t[b + 1] = -selector
        20000000000LL;
        for (int i = 0; i < q; ++i) {
            long long x = in.nextLong();
            // Process s
            int lb_s = lower_bound(s, x + 1);
            int s_prev_idx = max(0, lb_s - 1);
            long long sl = x - s[s_prev_idx];
            int lb_s_right = lower_bound(s, x);
            long long sr = s[lb_s_right] - x;
            // Process t
            int lb_t = lower_bound(t, x + 1);
            int t_prev_idx = max(0, lb_t - 1);
            long long tl = x - t[t_prev_idx];
            int lb_t_right = lower_bound(t, x);
            long long tr = t[lb_t_right] - x;
            // Calculate options
            long long option1 = max(sl, tl);
            long long option2 = max(sr, tr);
            long long option3 = 2 * sl + tr;
            long long option4 = 2 * tl + sr;
            long long option5 = sl + 2 * tr;
            long long option6 = tl + 2 * sr;
            long long min_val = min({option1, option2, option3, option4, option5, option6});
            out.ansln(min_val);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LightScanner in(cin);
    LightWriter out(std::cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}
// End of Code
