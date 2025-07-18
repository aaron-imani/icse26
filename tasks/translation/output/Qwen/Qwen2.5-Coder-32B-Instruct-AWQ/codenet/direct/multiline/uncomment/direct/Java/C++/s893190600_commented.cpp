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
        int c = skipSpaces();
        bool negative = c == '-';
        if (negative) c = read();
        int result = 0;
        while (isdigit(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    long long nextLong() {
        int c = skipSpaces();
        bool negative = c == '-';
        if (negative) c = read();
        long long result = 0;
        while (isdigit(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    double nextDouble() {
        int c = skipSpaces();
        bool negative = c == '-';
        if (negative) c = read();
        double result = 0;
        while (isdigit(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        if (c == '.') {
            c = read();
            double fraction = 0.1;
            while (isdigit(c)) {
                result += fraction * (c - '0');
                fraction *= 0.1;
                c = read();
            }
        }
        return negative ? -result : result;
    }

    string nextString() {
        int c = skipSpaces();
        string result;
        while (!isspace(c) && c != -1) {
            result += (char)c;
            c = read();
        }
        return result;
    }

private:
    int skipSpaces() {
        int c;
        do {
            c = read();
        } while (isspace(c) && c != -1);
        return c;
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

class MapCounter {
private:
    map<int, int> map;

public:
    MapCounter() {}

    void add(int key) {
        add(key, 1);
    }

    void add(int key, int cnt) {
        map[key] += cnt;
    }

    void remove(int key) {
        sub(key, 1, false);
    }

    void sub(int key) {
        sub(key, 1);
    }

    void sub(int key, int cnt) {
        sub(key, cnt, true);
    }

    void sub(int key, int cnt, bool minus) {
        if (map.find(key) != map.end()) {
            if (map[key] > cnt || minus) {
                map[key] -= cnt;
                if (map[key] == 0) {
                    map.erase(key);
                }
            }
        } else if (minus) {
            map[key] = -cnt;
        }
    }

    void set(int key, int cnt) {
        map[key] = cnt;
    }

    int getCount(int key) {
        return map.count(key) ? map[key] : 0;
    }

    set<int> getKey() {
        set<int> keys;
        for (const auto& pair : map) {
            keys.insert(pair.first);
        }
        return keys;
    }

    int getKeyCount() {
        return map.size();
    }

    int getFirstKey() {
        return map.begin()->first;
    }

    int getLastKey() {
        return map.rbegin()->first;
    }

    void clear() {
        map.clear();
    }
};

class Graph {
private:
    map<int, vector<int>> data;

public:
    void add(int from, int to) {
        data[from].push_back(to);
    }

    void del(int from, int to) {
        if (data.find(from) != data.end()) {
            data[from].erase(remove(data[from].begin(), data[from].end(), to), data[from].end());
        }
    }

    vector<int> get(int key) {
        return data.count(key) ? data[key] : vector<int>();
    }

    bool contains(int key) {
        return data.count(key);
    }

    set<int> keySet() {
        set<int> keys;
        for (const auto& pair : data) {
            keys.insert(pair.first);
        }
        return keys;
    }

    bool isConnect(int key_1, int key_2) {
        if (data.find(key_1) != data.end()) {
            return find(data[key_1].begin(), data[key_1].end(), key_2) != data[key_1].end();
        }
        return false;
    }

    vector<PP> distList(int key) {
        vector<PP> dist;
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key, 0));
        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int pp = wk.key;
            int dd = wk.val;
            if (mark.count(pp)) continue;
            mark.insert(pp);
            dist.push_back(wk);
            for (int next : get(pp)) {
                if (mark.count(next)) continue;
                stack.push(PP(next, dd + 1));
            }
        }
        return dist;
    }

    int* distV(int key) {
        int* dist = new int[data.size() + 1];
        fill(dist, dist + data.size() + 1, -1);
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key, 0));
        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int pp = wk.key;
            int dd = wk.val;
            if (mark.count(pp)) continue;
            mark.insert(pp);
            dist[pp] = dd;
            for (int next : get(pp)) {
                if (mark.count(next)) continue;
                stack.push(PP(next, dd + 1));
            }
        }
        return dist;
    }

    map<int, int> mapCnt;
    map<int, int> mapLow;
    set<int> mark;
    int number;

    int bridgeDfs(int now, int pre) {
        mark.insert(now);
        mapCnt[now] = number;
        mapLow[now] = number;
        int low;
        for (int next : get(now)) {
            if (next == pre) continue;
            if (mark.count(next)) {
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
        for (const auto& pair : mapCnt) {
            if (mapCnt[pair.first] == mapLow[pair.first]) {
                ans++;
            }
        }
        return ans - 1;
    }

    void dump(ostream& out) {
        for (const auto& pair : data) {
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
        return data.count(key) ? data[key] : vector<PP>();
    }

    bool contains(int key) {
        return data.count(key);
    }

    set<int> keySet() {
        set<int> keys;
        for (const auto& pair : data) {
            keys.insert(pair.first);
        }
        return keys;
    }

    bool isConnect(int key_1, int key_2) {
        if (data.find(key_1) != data.end()) {
            for (const PP& p : data[key_1]) {
                if (p.key == key_2) return true;
            }
        }
        return false;
    }

    int distance(int key_1, int key_2) {
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key_1, 0));
        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int key = wk.key;
            int val = wk.val;
            if (mark.count(key)) continue;
            mark.insert(key);
            if (key == key_2) return val;
            for (const PP& pp : get(key)) {
                if (mark.count(pp.key)) continue;
                stack.push(PP(pp.key, val + pp.val));
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
        return G.count(key) ? G[key] : vector<long long>();
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
        return G.count(key) ? G[key] : vector<PPL>();
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
};

int main() {
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
