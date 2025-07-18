#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

class Graph0n {
private:
    vector<Node0n> dt;
public:
    Graph0n(int sz) : dt(sz) {}
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
        if (a.weight < b.weight) return false;
        return a.v2 > b.v2;
    }
};

struct V2Comp {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 > b.v2) return true;
        if (a.v2 < b.v2) return false;
        return a.weight > b.weight;
    }
};

struct antiV2 {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 < b.v2) return true;
        if (a.v2 > b.v2) return false;
        return a.weight > b.weight;
    }
};

struct Vector {
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
};

const int INF = 1e8;
const long long INFL = 1e18;
const long long e97 = 1e9 + 7;

int abs(int a) { return a >= 0 ? a : -a; }
long long abs(long long a) { return a >= 0 ? a : -a; }

int min(int a, int b) { return a > b ? b : a; }
long long min(long long a, long long b) { return a > b ? b : a; }

int max(int a, int b) { return a > b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }

int minN(int... ins) {
    int min = ins[0];
    for (int i = 1; i < sizeof...(ins); ++i) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

// Other minN, maxN, etc. can be similarly implemented, but omitted for brevity.

int getDigit2(long long num) {
    long long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf <<= 1;
    }
    return d;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<long long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; ++i) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long long ans = 1;
    for (int i = d - 1; i >= 0; --i) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long long bit) {
    int ans = 0;
    for (long long i = 0; i < getDigit2(bit); ++i) {
        if ((bit & (1LL << i)) != 0) ans++;
    }
    return ans;
}

class FastScanner {
private:
    ifstream in;
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0, buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(buffer, BUFFER_SIZE);
        buflen = in.gcount();
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return static_cast<unsigned char>(buffer[ptr++]);
        else return -1;
    }

    bool isPrintableChar(int c) {
        return c >= 33 && c <= 126;
    }

public:
    FastScanner() : in(cin.rdbuf()) {}

    bool hasNext() {
        int b;
        while ((b = readByte()) != -1 && !isPrintableChar(b));
        if (b == -1) return false;
        ptr--;
        return true;
    }

    string next() {
        if (!hasNext()) throw runtime_error("No token");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        if (b != -1) ptr--;
        return s;
    }

    long long nexL() {
        if (!hasNext()) throw runtime_error("No token");
        bool minus = false;
        long long n = 0;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (b >= '0' && b <= '9') {
            n = n * 10 + (b - '0');
            b = readByte();
        }
        if (minus) n = -n;
        if (b != -1) ptr--;
        return n;
    }

    int nexI() {
        long long l = nexL();
        if (l < INT_MIN || l > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(l);
    }
};

int main() {
    FastScanner sc;
    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n, false);
    long long pop1st = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; ++i) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 *= 2;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long dif = pow10E97(2LL, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                assert(dw >= 0);
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2LL, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                assert(dw >= 0);
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
} // End of Code
