#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

class PP {
public:
    int key, val;
    PP(int key, int val) : key(key), val(val) {}
    int getKey() const { return key; }
    void setKey(int key) { this->key = key; }
    int getVal() const { return val; }
    void setVal(int val) { this->val = val; }
};

class PPP {
public:
    int key, val1, val2;
    PPP(int key, int val1, int val2) : key(key), val1(val1), val2(val2) {}
    int getKey() const { return key; }
    void setKey(int key) { this->key = key; }
    int getVal1() const { return val1; }
    void setVal1(int val1) { this->val1 = val1; }
    int getVal2() const { return val2; }
    void setVal2(int val2) { this->val2 = val2; }
};

class PPL {
public:
    long key, val;
    PPL(long key, long val) : key(key), val(val) {}
    long getKey() const { return key; }
    void setKey(long key) { this->key = key; }
    long getVal() const { return val; }
    void setVal(long val) { this->val = val; }
};

class PPDL {
public:
    long key;
    long val[2];
    PPDL(long key, long val1, long val2) : key(key) {
        val[0] = val1;
        val[1] = val2;
    }
    long getKey() const { return key; }
    void setKey(long key) { this->key = key; }
    long* getVal() { return val; }
    void setVal(long val1, long val2) {
        val[0] = val1;
        val[1] = val2;
    }
    void dump(ostream& out) {
        out << "key = " << key << "  val ";
        for (int i = 0; i < 2; i++) {
            out << "[" << val[i] << "] ";
        }
        out << endl;
    }
};

class PPKEY {
public:
    int key, val;
    PPKEY(int key, int val) : key(key), val(val) {}
    int getKey() const { return key; }
    int getVal() const { return val; }
    bool operator==(const PPKEY& other) const {
        return key == other.key && val == other.val;
    }
    bool operator!=(const PPKEY& other) const {
        return !(*this == other);
    }
};

class PPLKEY {
public:
    long key, val;
    PPLKEY(long key, long val) : key(key), val(val) {}
    long getKey() const { return key; }
    long getVal() const { return val; }
    bool operator==(const PPLKEY& other) const {
        return key == other.key && val == other.val;
    }
    bool operator!=(const PPLKEY& other) const {
        return !(*this == other);
    }
};

class Pair {
public:
    int key, val;
    Pair(int key, int val) : key(key), val(val) {}
};

class MyInput {
public:
    istream& in;
    MyInput(istream& is) : in(is) {}
    int nextInt() {
        int ret;
        in >> ret;
        return ret;
    }
    long nextLong() {
        long ret;
        in >> ret;
        return ret;
    }
    double nextDouble() {
        double ret;
        in >> ret;
        return ret;
    }
    string nextString() {
        string ret;
        in >> ret;
        return ret;
    }
};

class Solver {
public:
    MyInput& in;
    ostream& out;
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}
    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2));
        for (int i = 0; i < H; i++) {
            string s = in.nextString();
            for (int j = 0; j < W; j++) {
                C[i + 1][j + 1] = s[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    MyInput in(cin);
    ostream& out = cout;
    Solver solver(in, out);
    solver.solve();
    return 0;
}
// End of Code
