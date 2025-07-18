#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

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
        else return b.v2 > a.v2;
    }
};

struct V2Comp {
    bool operator()(const Edge& a, const Edge& b) const {
        if (a.v2 > b.v2) return true;
        else if (a.v2 < b.v2) return false;
        else {
            if (a.weight > b.weight) return true;
            else if (a.weight < b.weight) return false;
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
            else if (a.weight < b.weight) return false;
            else return false;
        }
    }
};

struct Vector {
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
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

class Graph0n {
private:
    vector<Node0n> dt;
public:
    Graph0n(int sz) : dt(sz) {}
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) { dt[vn].add(val); dt[val].add(vn); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() {
        for (auto& node : dt) node.clear();
    }
};

const int INF = 1e8;
const long long INFL = 1e17;
const long long e97 = Documento::e9 + 7;

int abs(int a) { return a >= 0 ? a : -a; }
long long abs(long long a) { return a >= 0 ? a : -a; }

int min(int a, int b) { return (a > b) ? b : a; }
long long min(long long a, long long b) { return (a > b) ? b : a; }
int max(int a, int b) { return (a > b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }

int minN(const vector<int>& ins) {
    int min_val = ins[0];
    for (int i = 1; i < ins.size(); ++i) {
        if (ins[i] < min_val) min_val = ins[i];
    }
    return min_val;
}

int maxN(const vector<int>& ins) {
    int max_val = ins[0];
    for (int i = 1; i < ins.size(); ++i) {
        if (ins[i] > max_val) max_val = ins[i];
    }
    return max_val;
}

int minExAd(const vector<int>& dt, int ad) {
    int min_val = INF;
    for (int i = 0; i < dt.size(); ++i) {
        if (i != ad && dt[i] < min_val) min_val = dt[i];
    }
    return min_val;
}

long long minExAd(const vector<long long>& dt, int ad) {
    long long min_val = INFL;
    for (int i = 0; i < dt.size(); ++i) {
        if (i != ad && dt[i] < min_val) min_val = dt[i];
    }
    return min_val;
}

int minExVal(const vector<int>& dt, int ex_val) {
    int min_val = INF;
    for (int i = 0; i < dt.size(); ++i) {
        if (dt[i] != ex_val && dt[i] < min_val) min_val = dt[i];
    }
    return min_val;
}

long long minExVal(const vector<long long>& dt, long long ex_val) {
    long long min_val = INFL;
    for (int i = 0; i < dt.size(); ++i) {
        if (dt[i] != ex_val && dt[i] < min_val) min_val = dt[i];
    }
    return min_val;
}

int maxExAd(const vector<int>& dt, int ad) {
    int max_val = -INF;
    for (int i = 0; i < dt.size(); ++i) {
        if (i != ad && dt[i] > max_val) max_val = dt[i];
    }
    return max_val;
}

long long maxExAd(const vector<long long>& dt, int ad) {
    long long max_val = -INFL;
    for (int i = 0; i < dt.size(); ++i) {
        if (i != ad && dt[i] > max_val) max_val = dt[i];
    }
    return max_val;
}

int maxExVal(const vector<int>& dt, int ex_val) {
    int max_val = -INF;
    for (int i = 0; i < dt.size(); ++i) {
        if (dt[i] != ex_val && dt[i] > max_val) max_val = dt[i];
    }
    return max_val;
}

long long maxExVal(const vector<long long>& dt, long long ex_val) {
    long long max_val = -INFL;
    for (int i = 0; i < dt.size(); ++i) {
        if (dt[i] != ex_val && dt[i] > max_val) max_val = dt[i];
    }
    return max_val;
}

int sumA(const vector<int>& dt) {
    int sum = 0;
    for (int e : dt) sum += e;
    return sum;
}

long long sumA(const vector<long long>& dt) {
    long long sum = 0;
    for (long long e : dt) sum += e;
    return sum;
}

int sumA(const vector<int>& dt) {
    int sum = 0;
    for (int e : dt) sum += e;
    return sum;
}

bool same3(long long a, long long b, long long c) {
    return a == b && b == c && a == c;
}

bool dif3(long long a, long long b, long long c) {
    return a != b && b != c && a != c;
}

bool triangle_inequality(int a, int b, int c) {
    return (a + b >= c) && (b + c >= a) && (c + a >= b);
}

double hypod(double a, double b) {
    return sqrt(a*a + b*b);
}

long long factorial(int n) {
    long long ans = 1;
    for (long long i = n; i > 0; --i) ans *= i;
    return ans;
}

long long facP(int n, long long p) {
    long long ans = 1;
    for (long long i = n; i > 0; --i) {
        ans = (ans * i) % p;
    }
    return ans;
}

long long lcm(long long m, long long n) {
    return m / gcd(m, n) * n;
}

long long gcd(long long m, long long n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

bool is_prime(long long a) {
    if (a == 1) return false;
    for (long long i = 2; i*i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
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

int pow(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; ++i) ans *= n;
    return ans;
}

long long pow(long long n, int k) {
    long long ans = 1;
    for (int i = 0; i < k; ++i) ans *= n;
    return ans;
}

int pow2(int in) { return in * in; }
long long pow2(long long in) { return in * in; }

int getDigit2(long long num) {
    int d = 0;
    long long cf = 1;
    while (num >= cf) {
        d++;
        cf <<= 1;
    }
    return d;
}

int getDigit10(long long num) {
    int d = 0;
    long long cf = 1;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d;
}

bool isINF(int in) {
    return (static_cast<long long>(in) * 20LL) > INF;
}

bool isINFL(long long in) {
    return (in * 10000LL) > INFL;
}

long long pow10E97(long ob, long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1LL;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<long long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob % p;
    for (int i = 1; i < d; ++i) {
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p;
    }

    long long ans = 1;
    for (int i = d-1; i >= 0; --i) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

long long flag(long pos) { return (1LL << pos); }
bool isFlaged(int bit, int pos) { return (bit & (1 << pos)) != 0; }
bool isFlaged(long long bit, int pos) { return (bit & (1LL << pos)) != 0; }
int countFlaged(int bit) {
    return __builtin_popcount(bit);
}
int countFlaged(long long bit) {
    return __builtin_popcountll(bit);
}

class FastScanner {
private:
    FILE *stream;
    char buffer[1024];
    int ptr, buflen;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, stream);
        return buflen > 0;
    }

public:
    FastScanner() : stream(stdin), ptr(0), buflen(0) {}

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += (char)b;
            b = readByte();
        }
        return s;
    }

    long long nexL() {
        if (!hasNext()) throw runtime_error("No element");
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
            } else if (b == -1 || !isPrintableChar(b) || b == ':') {
                break;
            } else {
                throw invalid_argument("Invalid number format");
            }
            b = readByte();
        }
        return minus ? -n : n;
    }

    int nexI() {
        long long val = nexL();
        if (val < INT_MIN || val > INT_MAX) throw invalid_argument("Integer overflow");
        return static_cast<int>(val);
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
        surp1 *= 2LL;
        if (flaged[i]) surp1 += 1;
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 *= 2LL;
            if (flaged[i]) surp9 += 1;
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
            long long dif = pow10E97(2LL, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1/0;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2LL, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1/0;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
// End of Code
