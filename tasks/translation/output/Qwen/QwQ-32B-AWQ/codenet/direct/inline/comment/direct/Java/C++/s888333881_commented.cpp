#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

struct Node0n {
    vector<int> next_vs;
    void add(int val) { next_vs.push_back(val); }
    int get(int ad) const { return next_vs[ad]; }
    vector<int> getAll() const { return next_vs; }
    int size() const { return next_vs.size(); }
    void clear() { next_vs.clear(); }
};

struct Graph0n {
    vector<Node0n> dt;
    Graph0n(int sz) : dt(sz) {}
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) {
        dt[vn].add(val);
        dt[val].add(vn);
    }
    int get(int vn, int index) const { return dt[vn].get(index); }
    vector<int> get(int vn) const { return dt[vn].getAll(); }
    int sizeOf(int vn) const { return dt[vn].size(); }
    void clear() {
        for (auto& node : dt) node.clear();
    }
};

struct Edge {
    int from = -1, v2 = -1;
    long long weight;
    Edge(int vn, long long w) : v2(vn), weight(w) {}
    Edge(int cm, int vn, long long w) : from(cm), v2(vn), weight(w) {}
};

struct Edge2 {
    int v2;
    long long cost1, cost2;
    Edge2(int vn, long long w1, long long w2) : v2(vn), cost1(w1), cost2(w2) {}
};

class FastScanner {
public:
    FastScanner(istream& in = cin) : in_(in) {}
    int nextInt() {
        int c = in_.get();
        while (c != '-' && !isdigit(c) && c != EOF) c = in_.get();
        if (c == EOF) throw runtime_error("EOF");
        bool negative = false;
        if (c == '-') {
            negative = true;
            c = in_.get();
        }
        int num = 0;
        while (isdigit(c)) {
            num = num * 10 + (c - '0');
            c = in_.get();
        }
        return negative ? -num : num;
    }
    string nextString() {
        int c = in_.get();
        while (!isprint(c) || isspace(c)) c = in_.get();
        string ret;
        while (isprint(c) && !isspace(c)) {
            ret.push_back(c);
            c = in_.get();
        }
        return ret;
    }
private:
    istream& in_;
};

long long pow_mod(long long base, long long exp, long long mod) {
    if (mod == 1) return 0;
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    FastScanner sc;
    int n = sc.nextInt();
    string s = sc.nextString();
    vector<bool> flaged(n);
    long long pop1st = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; ++i) {
        surp1 = (surp1 * 2) % (pop1st + 1);
        if (flaged[i]) surp1 = (surp1 + 1) % (pop1st + 1);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 = (surp9 * 2) % (pop1st - 1);
            if (flaged[i]) surp9 = (surp9 + 1) % (pop1st - 1);
        }
    }

    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long mod = pop1st - 1;
            long long exp = n - p - 1;
            long long pow_val = pow_mod(2, exp, mod);
            dw = (dw - pow_val) % mod;
            if (dw < 0) dw += mod;

            int ans = 1;
            while (dw != 0) {
                int cnt = __builtin_popcountll(dw);
                dw %= cnt;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long mod = pop1st + 1;
            long long exp = n - p - 1;
            long long pow_val = pow_mod(2, exp, mod);
            dw = (dw + pow_val) % mod;

            int ans = 1;
            while (dw != 0) {
                int cnt = __builtin_popcountll(dw);
                dw %= cnt;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
// End of Code
