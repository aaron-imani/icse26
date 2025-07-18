#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <fstream>
#include <iomanip>

using namespace std;

const int INF = 1e8;
const long long INFL = 1e17;
const long long e97 = 1e9 + 7;

class Graph0n {
private:
    vector<vector<int>> dt;
public:
    Graph0n(int sz) : dt(sz, vector<int>()) {}
    void add(int vn, int val) { dt[vn].push_back(val); }
    void add2(int vn, int val) { dt[vn].push_back(val); dt[val].push_back(vn); }
    int get(int vn, int index) { return dt[vn][index]; }
    vector<int> get(int vn) { return dt[vn]; }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for (auto& v : dt) v.clear(); }
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
    int compare(const Edge& a, const Edge& b) {
        if (a.weight > b.weight) return -1;
        else if (a.weight < b.weight) return 1;
        else return b.v2 - a.v2;
    }
};

class V2Comp {
public:
    int compare(const Edge& a, const Edge& b) {
        if (a.v2 > b.v2) return -1;
        else if (a.v2 < b.v2) return 1;
        else if (a.weight > b.weight) return -1;
        else if (a.weight < b.weight) return 1;
        else return 0;
    }
};

class antiV2 {
public:
    int compare(const Edge& a, const Edge& b) {
        if (a.v2 > b.v2) return 1;
        else if (a.v2 < b.v2) return -1;
        else if (a.weight > b.weight) return -1;
        else if (a.weight < b.weight) return 1;
        else return  0;
    }
};

class Vector {
public:
    int x, y;
    Vector(int sx, int sy) : x(sx), y(sy) {}
};

class FastScanner {
private:
    ifstream in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            in.read(buffer, 1024);
            buflen = in.gcount();
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1; }
    static bool isPrintableChar(int c) { return 33 <= c && c <= 126; }
public:
    FastScanner() : in(cin.rdbuf()) {}
    bool hasNext() { while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte(); }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += b;
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
        if (b < '0' || '9' < b) {
            throw runtime_error("Invalid number format");
        }
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
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of range");
        return nl;
    }
    double nexD() { return stod(next()); }
    void ni(vector<long long>& array2) {
        for (int i = 0; i < array2.size(); i++) {
            array2[i] = nexL();
        }
    }
    void ni(vector<int>& array2) {
        for (int i = 0; i < array2.size(); i++) {
            array2[i] = nexI();
        }
    }
    void ni(vector<int>& as, vector<int>& bs) {
        for (int i = 0; i < as.size(); i++) {
            as[i] = nexI();
            bs[i] = nexI();
        }
    }
    void ni(vector<long long>& as, vector<long long>& bs) {
        for (int i = 0; i < as.size(); i++) {
            as[i] = nexL();
            bs[i] = nexL();
        }
    }
    void ni(vector<int>& as, vector<int>& bs, vector<int>& cs) {
        for (int i = 0; i < as.size(); i++) {
            as[i] = nexI();
            bs[i] = nexI();
            cs[i] = nexI();
        }
    }
    void nisan(vector<vector<int>>& as) {
        for (int i = 0; i < as.size(); i++) {
            for (int j = 0; j < as[0].size(); j++) {
                as[i][j] = nexI();
            }
        }
    }
};

long long pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
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
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long dif = pow(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1 / 0 << endl;
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long dif = pow(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1 / 0 << endl;
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

// End of Code
