#include <iostream>
#include <vector>
#include <climits>
#include <cstddef>
#include <algorithm>
using namespace std;

const long MOD1 = 1000000007;
const long MOD2 = 998244353;
long inv9;

struct S {
    long sum;
    int l, r;
    static S E;
    static S op(const S& s1, const S& s2) {
        long sum = s1.sum + s2.sum;
        if (sum >= MOD2) sum -= MOD2;
        return { sum, min(s1.l, s2.l), max(s1.r, s2.r) };
    }
    static S map(const F& f, const S& s) {
        long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        return { ((f.D * c % MOD2) * inv9) % MOD2, s.l, s.r };
    }
};

S S::E = {0, INT_MAX/2, INT_MIN/2};

struct F {
    long D;
    int N;
    static F I;
    static F composite(const F& f, const F& g) {
        return F{f.D, f.N};
    }
};

F F::I = {0, 0};

vector<long> tenmod;

long modInv(long x) {
    return modPow(x, MOD2 - 2);
}

long modPow(long x, long y) {
    long z = 1;
    while (y > 0) {
        if (y % 2 == 0) {
            x = x * x % MOD2;
            y /= 2;
        } else {
            z = z * x % MOD2;
            y--;
        }
    }
    return z;
}

class InputReader {
private:
    istream& in;
    vector<char> buffer;
    size_t curbuf, lenbuf;
public:
    InputReader(istream& in) : in(in), buffer(1024), curbuf(0), lenbuf(0) {}
    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            lenbuf = in.readsome(buffer.data(), buffer.size());
            if (lenbuf <= 0) return false;
        }
        return true;
    }
    int readByte() {
        if (hasNextByte()) return buffer[curbuf++];
        else return -1;
    }
    bool isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }
    void skip() {
        while (hasNextByte() && isSpaceChar(buffer[curbuf])) curbuf++;
    }
    bool hasNext() {
        skip();
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string s;
        int b = readByte();
        while (!isSpaceChar(b)) {
            s += (char)b;
            b = readByte();
        }
        return s;
    }
    int nextInt() {
        if (!hasNext()) throw runtime_error("No more input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        int res = 0;
        while (!isSpaceChar(c)) {
            if (c < '0' || c > '9') throw runtime_error("Invalid number");
            res = res * 10 + (c - '0');
            c = readByte();
        }
        return minus ? -res : res;
    }
    long nextLong() {
        if (!hasNext()) throw runtime_error("No more input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        long res = 0;
        while (!isSpaceChar(c)) {
            if (c < '0' || c > '9') throw runtime_error("Invalid number");
            res = res * 10 + (c - '0');
            c = readByte();
        }
        return minus ? -res : res;
    }
};

template<typename S, typename F>
class LazySegTree {
private:
    int MAX;
    int N;
    int Log;
    S E;
    F Id;
    vector<S> Dat;
    vector<F> Laz;
public:
    LazySegTree(int n) 
        : E(S::E), Id(F::I) {
        int k =1;
        while (k < n) k <<=1;
        N = k;
        Log = 31 - __builtin_clz(N);
        MAX = n;
        Dat.resize(2*N, E);
        Laz.resize(N, Id);
    }
    
    LazySegTree(const vector<S>& dat)
        : LazySegTree(dat.size()) {
        int l = dat.size();
        for (int i=0; i<l; ++i) Dat[N +i] = dat[i];
        for (int i=N-1; i>0; --i) {
            Dat[i] = S::op(Dat[2*i], Dat[2*i+1]);
        }
    }
    
    void push(int k) {
        if (Laz[k] == Id) return;
        int lk = 2*k;
        int rk = 2*k +1;
        Dat[lk] = S::map(Laz[k], Dat[lk]);
        Dat[rk] = S::map(Laz[k], Dat[rk]);
        if (lk < N) {
            Laz[lk] = F::composite(Laz[k], Laz[lk]);
        }
        if (rk < N) {
            Laz[rk] = F::composite(Laz[k], Laz[rk]);
        }
        Laz[k] = Id;
    }
    
    void pushTo(int k) {
        for (int i=Log; i>0; --i) {
            push(k >> i);
        }
    }
    
    void pushTo(int l, int r) {
        for (int i=Log; i>0; --i) {
            if (((l >>i) <<i) != l) push(l >>i);
            if (((r >>i) <<i) != r) push(r >>i);
        }
    }
    
    S allProd() {
        return Dat[1];
    }
    
    void apply(int p, const F& f) {
        p += N;
        pushTo(p);
        Dat[p] = S::map(f, Dat[p]);
        updateFrom(p);
    }
    
    void apply(int l, int r, const F& f) {
        if (l > r) return;
        l += N;
        r += N;
        pushTo(l, r);
        for (int a=l, b=r; a < b; ) {
            if (a &1) {
                Dat[a] = S::map(f, Dat[a]);
                if (a < N) Laz[a] = F::composite(f, Laz[a]);
                a++;
            }
            if (b &1) {
                b--;
                Dat[b] = S::map(f, Dat[b]);
                if (b < N) Laz[b] = F::composite(f, Laz[b]);
            }
            a >>=1;
            b >>=1;
        }
        updateFrom(l, r);
    }
    
    void updateFrom(int k) {
        k >>=1;
        while (k>0) {
            Dat[k] = S::op(Dat[2*k], Dat[2*k+1]);
            k >>=1;
        }
    }
    
    void updateFrom(int l, int r) {
        for (int i=1; i<=Log; ++i) {
            if (((l >>i) <<i) != l) {
                int pos = l >>i;
                Dat[pos] = S::op(Dat[2*pos], Dat[2*pos+1]);
            }
            if (((r >>i) <<i) != r) {
                int pos = (r-1) >>i;
                Dat[pos] = S::op(Dat[2*pos], Dat[2*pos+1]);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    InputReader sc(cin);
    int N = sc.nextInt();
    int Q = sc.nextInt();
    
    tenmod.resize(N+1);
    tenmod[0] = 1;
    for (int j=1; j<=N; ++j) {
        tenmod[j] = (tenmod[j-1] * 10) % MOD2;
    }
    
    inv9 = modInv(9);
    
    vector<S> dat(N);
    for (int i=0; i<N; ++i) {
        dat[i] = {tenmod[N-i-1], i, i};
    }
    
    LazySegTree<S,F> segTree(dat);
    
    for (int q=0; q<Q; ++q) {
        int l = sc.nextInt()-1;
        int r = sc.nextInt()-1;
        long D = sc.nextLong();
        segTree.apply(l, r+1, F{D, N});
        cout << segTree.allProd().sum << '\n';
    }
    return 0;
}
// End of Code
