#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD2 = 998244353;
vector<long long> tenmod;
long long inv9;

struct S {
    static S E;
    long long sum;
    int l, r;
    S(long long s, int a, int b) : sum(s), l(a), r(b) {}
    static S op(const S& s1, const S& s2) {
        long long sum = (s1.sum + s2.sum) % MOD2;
        return { sum, min(s1.l, s2.l), max(s1.r, s2.r) };
    }
    static S map(const F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        long long new_sum = (f.D * c % MOD2) * inv9 % MOD2;
        return { new_sum, s.l, s.r };
    }
};
S S::E = S(0, INT_MAX/2, INT_MIN/2);

struct F {
    long long D;
    int N;
    F(long long d, int n) : D(d), N(n) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
    static F I() {
        return F(0, 0);
    }
};

long long modInv(long long x) {
    return modPow(x, MOD2-2);
}

long long modPow(long long x, long long y) {
    long long res = 1;
    x %= MOD2;
    while (y > 0) {
        if (y % 2 == .5) {
            res = res * x % MOD2;
        }
        x = x * x % MOD2;
        y /= 2;
    }
    return res;
}

struct InputReader {
    istream& in;
    char buffer[1024];
    int curbuf, lenbuf;
public:
    InputReader(istream& _in) : in(_in), curbuf(0), lenbuf(0) {}
    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            in.read(buffer, 1024);
            lenbuf = in.gcount();
            if (lenbuf <= 0) return false;
        }
        return true;
    }
    int readByte() {
        if (hasNextByte()) return buffer[curbuf++];
        else return -1;
    }
    void skip() {
        while (hasNextByte() && isSpaceChar(buffer[curbuf])) curbuf++;
    }
    bool isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }
    bool hasNext() {
        skip();
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int c = readByte();
        while (!isSpaceChar(c)) {
            s.push_back(c);
            c = readByte();
        }
        return s;
    }
    int nextInt() {
        if (!hasNext()) throw runtime_error("No element");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') { minus = true; c = readByte(); }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw runtime_error("Invalid");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No element");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') { minus = true; c = readByte(); }
        long long res = 0;
        do {
            if (c < '0' || c > '9') throw runtime_error("Invalid");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
};

template <typename S, typename F>
class LazySegTree {
private:
    int MAX;
    int N;
    int Log;
    vector<S> Dat;
    vector<F> Laz;
    void push(int k) {
        if (Laz[k] == F::I()) return;
        int l = 2*k, r_node = 2*k +1;
        Dat[l] = S::map(Laz[k], Dat[l]);
        Dat[r_node] = S::map(Laz[k], Dat[r_node]);
        if (l < N) {
            Laz[l] = F::composite(Laz[k], Laz[l]);
        }
        if (r_node < N) {
            Laz[r_node] = F::composite(Laz[k], Laz[r_node]);
        }
        Laz[k] = F::I();
    }
    void pushTo(int l, int r) {
        for (int i = Log; i > 0; --i) {
            if ( ((l >> i) << i) != l ) push(l >> i);
            if ( ((r >> i) << i) != r ) push(r >> i);
        }
    }
public:
    LazySegTree(const vector<S>& initial) {
        MAX = initial.size();
        N = 1;
        while (N < MAX) N <<= 1;
        Log = 31 - __builtin_clz(N);
        Dat.resize(2*N, S::E);
        Laz.resize(N, F::I());
        for (int i = 0; i < MAX; ++i) Dat[N + i] = initial[i];
        for (int i = N-1; i >=1; --i) {
            Dat[i] = S::op(Dat[2*i], Dat[2*i+1]);
        }
    }
    void apply(int l, int r, const F& f) {
        if (l > r) return;
        l += N; r += N;
        pushTo(l, r);
        for (int a = l, b = r; a < b; ) {
            if (a % 2 ==1) {
                Dat[a] = S::map(f, Dat[a]);
                if (a < N) Laz[a] = F::composite(f, Laz[a]);
                a++;
            }
            if (b %2 ==1) {
                b--;
                Dat[b] = S::map(f, Dat[b]);
                if (b < N) Laz[b] = F::composite(f, Laz[b]);
            }
            a >>=1;
            b >>=1;
        }
    }
    S allProd() {
        return Dat[1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader sc(cin);
    int N = sc.nextInt();
    int Q = sc.nextInt();
    tenmod.resize(N+1);
    tenmod[0] = 1;
    for (int j =1; j <=N; j++) {
        tenmod[j] = (tenmod[j-1] *10LL) % MOD2;
    }
    inv9 = modInv(9);
    vector<S> dat(N);
    for (int i=0; i<N; i++) {
        dat[i] = S(tenmod[N -i-1], i, i);
    }
    LazySegTree<S,F> seg(dat);
    for (int q=0; q<Q; q++) {
        int l = sc.nextInt()-1;
        int r = sc.nextInt()-1;
        long long D = sc.nextLong();
        seg.apply(l, r+1, F(D, N));
        cout << seg.allProd().sum << '\n';
    }
    return 0;
} // End of Code
