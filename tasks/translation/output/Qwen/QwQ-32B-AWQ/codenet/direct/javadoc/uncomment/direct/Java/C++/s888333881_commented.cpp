#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
using namespace std;

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
        if (a.weight > b.weight) return true;
        else if (a.weight < b.weight) return false;
        else return b.v2 < a.v2;
    }
};

struct V2Comp {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 > b.v2) return true;
        else if (a.v2 < b.v2) return false;
        else {
            if (a.weight > b.weight) return true;
            else return false;
        }
    }
};

struct antiV2 {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 < b.v2) return true;
        else if (a.v2 > b.v2) return false;
        else {
            if (a.weight > b.weight) return true;
            else return false;
        }
    }
};

struct Vector {
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
};

class Graph0n {
private:
    vector<Node0n> dt;
public:
    Graph0n(int sz) : dt(sz, Node0n()) {}
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) { dt[vn].add(val); dt[val].add(vn); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for (auto& node : dt) node.clear(); }
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

const int INF = 1e8;
const long long INFL = 1e17;
const long long e97 = y9 + 7;

class FastScanner {
private:
    istream& in;
    vector<char> buffer;
    size_t ptr = 0;
    size_t buflen = 0;
public:
    FastScanner() : in(cin), buffer(1024) {}
    bool hasNextByte() {
        if (ptr < buflen) return true;
        else {
            ptr = 0;
            buflen = in.readsome(buffer.data(), buffer.size());
            if (buflen <= 0) return false;
        }
        return true;
    }
    int readByte() {
        if (hasNextByte()) return static_cast<unsigned char>(buffer[ptr++]);
        else return -1;
    }
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += static_cast<char>(b);
            b = readByte();
        }
        return sb;
    }
    long long nexL() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b) || b == ':') {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }
    int nexI() {
        long long nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Integer overflow");
        return static_cast<int>(nl);
    }
};

int getDigit2(long num) {
    int d = 0;
    long cf = 1;
    while (num >= cf) {
        d++;
        cf <<= 1;
    }
    return d;
}

long long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1LL % p;
    if (soeji == 2) return (ob * ob) % p;
    int d = getDigit2(soeji);
    vector<long long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob % p;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p;
    }
    long long ans = 1;
    for (int i = d-1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long dw) {
    return __builtin_popcountll(dw);
}

long long modinv(long long a, long long p) {
    long long b = p, u = 1, v = 0;
    while (b > 0) {
        long long t = a / b;
        long long pe = a % b;
        a = b; b = pe;
        pe = u - t * v;
        u = v; v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

int main() {
    FastScanner sc;
    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n, false);
    long long pop1st = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2LL;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        surp9 = 0;
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
            long long dw = surp9;
            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << 1/0;
                    assert(false);
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << 1/0;
                    assert(false);
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
