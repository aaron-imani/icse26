#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>

using namespace std;

struct Graph0n {
    vector<Node0n> dt;
    Graph0n(int sz) : dt(sz) {}
    void add(int vn, int val) { dt[vn].add(val); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for (int i = 0; i < dt.size(); i++) dt[i].clear(); }
};

struct Node0n {
    vector<int> next_vs;
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

inline int abs(int a) { return a >=0 ? a : -a; }
inline long long abs(long long a) { return a >=0 ? a : -a; }

const int INF = 1e8;
const long long INFL = 1e17;
const long long e97 = 1e9 +7;

int getDigit2(long long num) {
    int d = 0;
    long long cf = 1;
    while (num >= cf) {
        d++;
        cf <<= 1;
    }
    return d;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0LL;
    if (soeji == 0) return 1LL;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<long long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p;
    }

    long long ans = 1;
    for (int i = d-1; i >=0; --i) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long long bit) {
    return __builtin_popcountll(bit);
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
        if (hasNextByte()) {
            return buffer[ptr++];
        }
        else {
            return -1;
        }
    }

    bool hasNext() {
        while (hasNextByte()) {
            char c = buffer[ptr];
            if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
                ptr++;
            }
            else {
                return true;
            }
        }
        return false;
    }

    string next() {
        if (!hasNext()) throw runtime_error("No token available");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += (char)b;
            b = readByte();
        }
        return sb;
    }

    long long nexL() {
        if (!hasNext()) throw runtime_error("No token available");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw runtime_error("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + (b - '0');
            }
            else if (b == -1 || !isPrintableChar(b) || b == ':') {
                return minus ? -n : n;
            }
            else {
                throw runtime_error("Invalid number");
            }
            b = readByte();
        }
    }

    int nexI() {
        long long nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Out of int range");
        return (int)nl;
    }

private:
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
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
        surp1 = (surp1 * 2 + (flaged[i] ? 1LL : 0LL)) % (pop1st + 1);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 = (surp9 * 2 + (flaged[i] ? 1LL : 0LL)) % (pop1st - 1);
        }
    }

    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long exp = static_cast<long long>(n - p - 1);
            long long mod_val = pop1st - 1;
            long long dif = pow10E97(2, exp, mod_val);
            dw -= dif;
            dw += mod_val; // to handle negative values
            dw %= mod_val;
            int ans = 1;
            while (dw != 0) {
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long exp = static_cast<long long>(n - p - 1);
            long long mod_val = pop1st + 1;
            long long dif = pow10E97(2, exp, mod_val);
            dw += dif;
            dw %= mod_val;
            int ans = 1;
            while (dw != 0) {
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
