#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

struct Vector {
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
};

const int INF = 1e8;
const long long INFL = 1e17;
const long long e97 = categoria::1e9 + 7;

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
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p;
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

struct FastScanner {
private:
    istream& in;
    vector<char> buffer;
    streamsize pos;
    void loadBuffer() {
        if (pos < buffer.size()) return;
        buffer.clear();
        buffer.resize(1024);
        in.read(buffer.data(), buffer.size());
        streamsize count = in.gcount();
        buffer.resize(count);
        pos = 0;
    }
public:
    FastScanner() : in(cin), pos(0) {}
    
    bool hasNextByte() {
        if (pos < buffer.size()) return true;
        else {
            buffer.clear();
            buffer.resize(1024);
            in.read(buffer.data(), buffer.size());
            streamsize count = in.gcount();
            buffer.resize(count);
            pos = 0;
            return !buffer.empty();
        }
    }
    
    int readByte() {
        if (hasNextByte()) {
            int c = static_cast<unsigned char>(buffer[pos++]);
            return c;
        } else {
            return -1;
        }
    }
    
    bool hasNext() {
        while (hasNextByte()) {
            int c = static_cast<unsigned char>(buffer[pos]);
            if (!isprint(c)) pos++;
            else break;
        }
        return hasNextByte();
    }
    
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string s;
        int b = readByte();
        while (isprint(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
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
        if (b < '0' || b > '9') throw invalid_argument("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else {
                break;
            }
            b = readByte();
        }
        return minus ? -n : n;
    }
    
    int nexI() {
        long long val = nexL();
        if (val < INT_MIN || val > INT_MAX) throw invalid_argument("Overflow");
        return static_cast<int>(val);
    }
    
    double nexD() { return stod(next()); }
};

int main() {
    FastScanner sc;
    cout << fixed << setprecision(0);
    
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
        if (flaged[i]) surp1 += 1;
        surp1 %= (pop1st + 1);
    }
    
    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 *= 2;
            if (flaged[i]) surp9 += 1;
            surp9 %= (pop1st - 1);
        }
    }
    
    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << '\n';
                continue;
            }
            long long dw = surp9;
            
            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);
            
            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << 1/0 << '\n';
                    return 0;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        } else {
            long long dw = surp1;
            
            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);
            
            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << 1/0 << '\n';
                    return 0;
                }
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
