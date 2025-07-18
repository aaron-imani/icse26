#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <functional>
#include <unordered_map>
using namespace std;

struct PP {
    int key, val;
    PP(int k, int v) : key(k), val(v) {}
};

struct PPP {
    int key, val1, val2;
    PPP(int k, int v1, int v2) : key(k), val1(v1), val2(v2) {}
};

struct PPL {
    long long key, val;
    PPL(long long k, long long v) : key(k), val(v) {}
};

struct PPDL {
    long long key;
    vector<long long> val;
    PPDL(long long k, const vector<long long>& v) : key(k), val(v) {}
    void dump(ostream& out) {
        out << "key = " << key << "  val ";
        for (auto v : val) {
            out << "[" << v << "] ";
        }
        out << endl;
    }
};

struct PPKEY {
    int key, val;
    PPKEY(int k, int v) : key(k), val(v) {}
};

struct PPLKEY {
    long long key, val;
    PPLKEY(long long k, long long v) : key(k), val(v) {}
};

namespace std {
    template<>
    struct hash<PPKEY> {
        size_t operator()(const PPKEY& p) const {
            return hash<int>()(p.key) ^ hash<int>()(p.val);
        }
    };
    
    template<>
    struct hash<PPLKEY> {
        size_t operator()(const PPLKEY& p) const {
            return hash<long long>()(p.key) ^ hash<long long>()(p.val);
        }
    };
}

class MapCounter {
private:
    map<int, int> map;
    bool reverse;

public:
    MapCounter(bool rev = false) : reverse(rev) {}

    void add(int key, int cnt = 1) {
        auto it = map.find(key);
        if (it != map.end()) {
            it->second += cnt;
        } else {
            map[key] = cnt;
        }
    }

    void set(int key, int cnt) {
        map[key] = cnt;
    }

    int getCount(int key) const {
        auto it = map.find(key);
        return it != map.end() ? it->second : 0;
    }

    int getKeyCount() const {
        return map.size();
    }
};

class Graph {
private:
    map<int, vector<int>> data;

public:
    void add(int from, int to) {
        data[from].push_back(to);
    }

    bool contains(int key) const {
        return data.find(key) != data.end();
    }

    const vector<int>& get(int key) const {
        auto it = data.find(key);
        return it != data.end() ? it->second : vector<int>();
    }

    bool isConnect(int key1, int key2) const {
        auto it = data.find(key1);
        if (it == data.end()) return false;
        for (int v : it->second) {
            if (v == key2) return true;
        }
        return false;
    }
};

class MyInput {
private:
    static const int bufferSize = 1024 * 8;
    char buffer[bufferSize];
    int pos = 0;
    int readLen = 0;
    FILE* in;

public:
    MyInput() : in(stdin) {
        readLen = fread(buffer, 1, bufferSize, in);
        pos = 0;
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = fread(buffer, 1, bufferSize, in);
            if (readLen <= 0) {
                throw runtime_error("EOF reached");
            }
        }
        return buffer[pos++];
    }

    int nextInt() {
        int c = read();
        while (isspace(c)) c = read();
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = read();
        }
        int res = 0;
        while (isdigit(c)) {
            res = res * 10 + (c - '0');
            c = read();
        }
        return neg ? -res : res;
    }

    long long nextLong() {
        int c = read();
        while (isspace(c)) c = read();
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = read();
        }
        long long res = 0;
        while (isdigit(c)) {
            res = res * 10 + (c - '0');
            c = read();
        }
        return neg ? -res : res;
    }

    double nextDouble() {
        int c = read();
        while (isspace(c)) c = read();
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = read();
        }
        double res = 0;
        bool decimal = false;
        int scale = 1;
        while (true) {
            if (isdigit(c)) {
                res = res * 10 + (c - '0');
                if (decimal) scale *= 10;
                c = read();
            } else if (c == '.') {
                decimal = true;
                c = read();
            } else {
                break;
            }
        }
        if (decimal) res /= scale;
        return neg ? -res : res;
    }

    string nextString() {
        int c = read();
        while (isspace(c)) c = read();
        string res;
        while (!isspace(c) && c != EOF) {
            res += c;
            c = read();
        }
        return res;
    }
};

class Solver {
private:
    MyInput& in;
    ostream& out;

public:
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H+2, vector<char>(W+2));
        for (int i = 1; i <= H; ++i) {
            string s = in.nextString();
            for (int j = 1; j <= W; ++j) {
                C[i][j] = s[j-1];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#' &&
                    C[i-1][j] != '#' &&
                    C[i+1][j] != '#' &&
                    C[i][j-1] != '#' &&
                    C[i][j+1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    MyInput in;
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
