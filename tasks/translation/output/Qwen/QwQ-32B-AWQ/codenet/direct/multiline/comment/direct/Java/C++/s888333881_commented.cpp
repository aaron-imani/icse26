#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node0n {
    vector<int> next_vs;
    void add(int val) { next_vs.push_back(val); }
    int get(int idx) { return next_vs[idx]; }
    vector<int> getAll() { return next_vs; }
    int size() { return next_vs.size(); }
    void clear() { next_vs.clear(); }
};

struct Graph0n {
    vector<Node0n> dt;
    Graph0n(int sz) : dt(sz) {}
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) { dt[vn].add(val); dt[val].add(vn); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for (auto& node : dt) node.clear(); }
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

struct CompareEdge {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.weight != b.weight) return a.weight < b.weight;
        return a.v2 < b.v2;
    }
};

struct V2Comp {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 != b.v2) return a.v2 > b.v2;
        return a.weight < b.weight;
    }
};

struct antiV2 {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 != b.v2) return a.v2 < b.v2;
        return a.weight > b.weight;
    }
};

struct Vector {
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
};

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 夙1;
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

int countFlaged(long long bit) {
    return __builtin_popcountll(bit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> flaged(n, false);
    long long pop1st = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flaged[i] = true;
            ++pop1st;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; ++i) {
        surp1 *= 2LL;
        if (flaged[i]) {
            surp1 += 1LL;
        }
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 *= 2LL;
            if (flaged[i]) {
                surp9 += 1LL;
            }
            surp9 %= (pop1st - 1LL);
        }
    }

    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << '\n';
                continue;
            }
            long long dw = surp9;
            long long dif = mod_pow(2LL, (n - p - 1), (pop1st - 1LL));
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);
            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << "1/0\n";
                    return 1;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        } else {
            long long dw = surp1;
            long long dif = mod_pow(2LL, (n - p - 1), (pop1st + 1LL));
            dw += dif;
            dw %= (pop1st + 1LL);
            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << "1/0\n";
                    return 1;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
} // End of Code
