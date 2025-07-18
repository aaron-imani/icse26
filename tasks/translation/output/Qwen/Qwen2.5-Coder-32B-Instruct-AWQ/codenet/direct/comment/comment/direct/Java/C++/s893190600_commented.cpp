#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class MyInput {
private:
    istream& in;
    string buffer;
    size_t pos;

public:
    MyInput(istream& is) : in(is), pos(0) {}

    int read() {
        if (pos >= buffer.size()) {
            getline(in, buffer);
            pos = 0;
        }
        return pos < buffer.size() ? buffer[pos++] : -1;
    }

    int nextInt() {
        int c = read();
        while (c != -1 && !isdigit(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        while (isdigit(c)) {
            res = res * 10 + c - '0';
            c = read();
        }
        return sgn * res;
    }

    long long nextLong() {
        int c = read();
        while (c != -1 && !isdigit(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long long res = 0;
        while (isdigit(c)) {
            res = res * 10 + c - '0';
            c = read();
        }
        return sgn * res;
    }

    double nextDouble() {
        int c = read();
        while (c != -1 && !isdigit(c) && c != '-') c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (isdigit(c)) {
            res = res * 10 + c - '0';
            c = read();
        }
        if (c == '.') {
            double div = 1;
            c = read();
            while (isdigit(c)) {
                div *= 10;
                res += (c - '0') / div;
                c = read();
            }
        }
        return sgn * res;
    }

    string nextString() {
        int c = read();
        while (c != -1 && isspace(c)) c = read();
        string res;
        while (c != -1 && !isspace(c)) {
            res += c;
            c = read();
        }
        return res;
    }
};

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
    PPDL(long long k, vector<long long> v) : key(k), val(v) {}
    void dump(ostream& out) {
        out << "key = " << key << "  val ";
        for (long long v : val) {
            out << "[" << v << "] ";
        }
        out << endl;
    }
};

struct PPKEY {
    int key, val;
    PPKEY(int k, int v) : key(k), val(v) {}
    bool operator==(const PPKEY& other) const {
        return key == other.key && val == other.val;
    }
};

struct PPLKEY {
    long long key, val;
    PPLKEY(long long k, long long v) : key(k), val(v) {}
    bool operator==(const PPLKEY& other) const {
        return key == other.key && val == other.val;
    }
};

namespace std {
    template <>
    struct hash<PPKEY> {
        size_t operator()(const PPKEY& p) const {
            return hash<int>()(p.key) ^ hash<int>()(p.val);
        }
    };

    template <>
    struct hash<PPLKEY> {
        size_t operator()(const PPLKEY& p) const {
            return hash<long long>()(p.key) ^ hash<long long>()(p.val);
        }
    };
}

class Graph {
private:
    map<int, vector<int>> data;

public:
    void add(int from, int to) {
        data[from].push_back(to);
    }

    void del(int from, int to) {
        auto it = data.find(from);
        if (it != data.end()) {
            it->second.erase(remove(it->second.begin(), it->second.end(), to), it->second.end());
        }
    }

    vector<int> get(int key) {
        return data[key];
    }

    bool contains(int key) {
        return data.find(key) != data.end();
    }

    set<int> keySet() {
        set<int> keys;
        for (auto& pair : data) {
            keys.insert(pair.first);
        }
        return keys;
    }

    bool isConnect(int key_1, int key_2) {
        auto it = data.find(key_1);
        if (it == data.end()) return false;
        return find(it->second.begin(), it->second.end(), key_2) != it->second.end();
    }

    vector<PP> distList(int key) {
        vector<PP> dist;
        set<int> mark;
        stack<PP> stack;
        stack.push({key, 0});
        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int pp = wk.key;
            int dd = wk.val;
            if (mark.find(pp) != mark.end()) continue;
            mark.insert(pp);
            dist.push_back({pp, dd});
            for (int next : get(pp)) {
                if (mark.find(next) != mark.end()) continue;
                stack.push({next, dd + 1});
            }
        }
        return dist;
    }

    vector<int> distV(int key) {
        vector<int> dist(data.size() + 1, -1);
        set<int> mark;
        stack<PP> stack;
        stack.push({key, 0});
        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int pp = wk.key;
            int dd = wk.val;
            if (mark.find(pp) != mark.end()) continue;
            mark.insert(pp);
            dist[pp] = dd;
            for (int next : get(pp)) {
                if (mark.find(next) != mark.end()) continue;
                stack.push({next, dd + 1});
            }
        }
        return dist;
    }

    map<int, int> mapCnt, mapLow;
    set<int> mark;
    int number;

    int bridgeDfs(int now, int pre) {
        mark.insert(now);
        mapCnt[now] = number;
        mapLow[now] = number;
        int low;
        for (int next : get(now)) {
            if (next == pre) continue;
            if (mark.find(next) != mark.end()) {
                if (mapLow[now] > mapLow[next]) {
                    mapLow[now] = mapLow[next];
                }
                continue;
            }
            number++;
            low = bridgeDfs(next, now);
            if (mapLow[now] > low) {
                mapLow[now] = low;
            }
        }
        return mapLow[now];
    }

    int bridgeCnt(int start) {
        mapCnt.clear();
        mapLow.clear();
        mark.clear();
        number = 0;
        bridgeDfs(start, start);
        int ans = 0;
        for (auto& pair : mapCnt) {
            if (pair.second == mapLow[pair.first]) {
                ans++;
            }
        }
        return ans - 1;
    }

    void dump(ostream& out) {
        for (auto& pair : data) {
            out << pair.first << " : ";
            for (int val : pair.second) {
                out << val << " ";
            }
            out << endl;
        }
    }
};

class GraphWith {
private:
    map<int, vector<PP>> data;

public:
    void add(int key, PP p) {
        data[key].push_back(p);
    }

    vector<PP> get(int key) {
        return data[key];
    }

    bool contains(int key) {
        return data.find(key) != data.end();
    }

    set<int> keySet() {
        set<int> keys;
        for (auto& pair : data) {
            keys.insert(pair.first);
        }
        return keys;
    }

    bool isConnect(int key_1, int key_2) {
        auto it = data.find(key_1);
        if (it == data.end()) return false;
        for (PP p : it->second) {
            if (p.key == key_2) return true;
        }
        return false;
    }

    int distance(int key_1, int key_2) {
        set<int> mark;
        stack<PP> stack;
        stack.push({key_1, 0});
        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int key = wk.key;
            int val = wk.val;
            if (mark.find(key) != mark.end()) continue;
            mark.insert(key);
            if (key == key_2) return val;
            for (PP p : get(key)) {
                if (mark.find(p.key) != mark.end()) continue;
                stack.push({p.key, val + p.val});
            }
        }
        return INT_MAX;
    }
};

class GraphLong {
private:
    map<long long, vector<long long>> G;

public:
    void add(long long key, long long value) {
        G[key].push_back(value);
    }

    vector<long long> get(long long key) {
        return G[key];
    }
};

class GraphLongWith {
private:
    map<long long, vector<PPL>> G;

public:
    void add(long long key, PPL p) {
        G[key].push_back(p);
    }

    vector<PPL> get(long long key) {
        return G[key];
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
        vector<vector<char>> C(H + 2, vector<char>(W + 2));
        for (int i = 0; i < H; i++) {
            string line = in.nextString();
            for (int j = 0; j < W; j++) {
                C[i + 1][j + 1] = line[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                    C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }

    void prn(const string& s) {
        out << s << endl;
    }

    void prn(int i) {
        out << i << endl;
    }

    void prn(long long i) {
        out << i << endl;
    }

    void prr(const string& s) {
        out << s;
    }

    int ni() {
        return in.nextInt();
    }

    long long nl() {
        return in.nextLong();
    }

    double nd() {
        return in.nextDouble();
    }

    string ns() {
        return in.nextString();
    }

    vector<int> ndi(int n) {
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = ni();
        }
        return ans;
    }

    vector<long long> ndl(int n) {
        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nl();
        }
        return ans;
    }

    vector<double> ndd(int n) {
        vector<double> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nd();
        }
        return ans;
    }

    vector<string> nds(int n) {
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = ns();
        }
        return ans;
    }

    vector<vector<int>> nddi(int n, int m) {
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = ni();
            }
        }
        return ans;
    }

    vector<vector<long long>> nddl(int n, int m) {
        vector<vector<long long>> ans(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = nl();
            }
        }
        return ans;
    }
};

int main() {
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
