#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
using namespace std;

struct Node0n {
    vector<int> next_vs;
    void add(int val) { next_vs.push_back(val); }
    int get(int ad) { return next_vs[ad]; }
    vector<int> getAll() { return next_vs; }
    int size() { return next_vs.size(); }
    void clear() { next_vs.clear(); }
};

struct Graph0n {
    vector<Node0n> dt;
    Graph0n(int sz) : dt(sz) {
        for (int i = 0; i < sz; ++i) {
            dt[i] = Node0n();
        }
    }
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) {
        dt[vn].add(val);
        dt[val].add(vn);
    }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() {
        for (int i = 0; i < dt.size(); ++i) {
            dt[i].clear();
        }
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

struct Comparator_Edge {
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

int INF = 1e8;
long long INFL = 1e18;
long long e97 = 1e9 + 7;

bool is_printable(int c) {
    return 33 <= c && c <= 126;
}

int getDigit2(long num) {
    int d = 0;
    long cf = 1;
    while (num >= cf) {
        d++;
        cf <<= 1;
    }
    return d;
}

long modinv(long a, long p) {
    long b = p, u = 1, v = 0;
    while (b > 0) {
        long t = a / b;
        long pe = a % b;
        a = b;
        b = pe;
        pe = u - t * v;
        u = v;
        v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long val) {
    int cnt = 0;
    while (val) {
        cnt += val & 1;
        val >>= 1;
    }
    return cnt;
}

class FastScanner {
private:
    FILE* in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;

public:
    FastScanner() : in(stdin) {}

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, in);
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return static_cast<int>(buffer[ptr++]);
        else return -1;
    }

    bool hasNext() {
        while (hasNextByte() && !is_printable(buffer[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No token");
        string sb;
        int b = readByte();
        while (is_printable(b)) {
            sb += static_cast<char>(b);
            b = readByte();
        }
        return sb;
    }

    long long nexL() {
        if (!hasNext()) throw runtime_error("No number");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw invalid_argument("Not a number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !is_printable(b) || b == ':') {
                return minus ? -n : n;
            } else {
                throw invalid_argument("Invalid number");
            }
            b = readByte();
        }
    }

    int nexI() {
        long long nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw overflow_error("Integer overflow");
        return static_cast<int>(nl);
    }
};

int main() {
    FastScanner sc;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n);
    long long pop1st = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2LL;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1LL);
    }

    long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2LL;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1LL);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long dw = surp9;

            long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << "Error" << endl;
                    return 1;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long dw = surp1;

            long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << "Error" << endl;
                    return 1;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
// End of Code
