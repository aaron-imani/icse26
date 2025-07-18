#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstring>

using namespace std;

class Graph0n {
private:
    vector<vector<int>> dt;
public:
    Graph0n(int sz) : dt(sz) {}
    void add(int vn, int val) { dt[vn].push_back(val); }
    void add2(int vn, int val) { dt[vn].push_back(val); dt[val].push_back(vn); }
    int get(int vn, int index) { return dt[vn][index]; }
    vector<int> get(int vn) { return dt[vn]; }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for (auto &node : dt) node.clear(); }
};

class Node0n {
private:
    vector<int> next_vs;
public:
    void add(int val) { next_vs.push_back(val); }
    int get(int ad) { return next_vs[ad]; }
    vector<int> getAll() { return next_vs; }
    int size() { return next_vs.size(); }
    void clear() { next_vs.clear(); }
};

class Edge {
public:
    int from = -1, v2 = -1;
    long long weight;
    Edge(int vn, long long w) : v2(vn), weight(w) {}
    Edge(int cm, int vn, long long w) : from(cm), v2(vn), weight(w) {}
};

class Edge2 {
public:
    int v2;
    long long cost1, cost2;
    Edge2(int vn, long long w1, long long w2) : v2(vn), cost1(w1), cost2(w2) {}
};

class Comparator_Edge {
public:
    bool operator()(const Edge &a, const Edge &b) {
        if (a.weight > b.weight) return true;
        else if (a.weight < b.weight) return false;
        else return b.v2 < a.v2;
    }
};

class V2Comp {
public:
    bool operator()(const Edge &a, const Edge &b) {
        if (a.v2 > b.v2) return true;
        else if (a.v2 < b.v2) return false;
        else if (a.weight > b.weight) return true;
        else if (a.weight < b.weight) return false;
        else return false;
    }
};

class antiV2 {
public:
    bool operator()(const Edge &a, const Edge &b) {
        if (a.v2 > b.v2) return false;
        else if (a.v2 < b.v2) return true;
        else if (a.weight > b.weight) return true;
        else if (a.weight < b.weight) return false;
        else return false;
    }
};

class Vector {
public:
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
};

void fill(bool *ob, bool res, int size) {
    for (int i = 0; i < size; i++) ob[i] = res;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = 0;
    long long cf = 1;
    while (soeji >= cf) {
        d++;
        cf <<= 1;
    }

    vector<long long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;

    long long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long long bit) {
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        if (bit & (1LL << i)) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    bool flaged[n];
    fill(flaged, false, n);

    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << "\n";
                continue;
            }
            long long dw = surp9;

            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1 / 0;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << "\n";
        } else {
            long long dw = surp1;

            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1 / 0;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
// End of Code
