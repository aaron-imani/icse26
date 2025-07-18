#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

class PP {
public:
    int key, val;
    PP(int key, int val) : key(key), val(val) {}
};

class PPP {
public:
    int key, val1, val2;
    PPP(int key, int val1, int val2) : key(key), val1(val1), val2(val2) {}
};

class PPL {
public:
    long key, val;
    PPL(long key, long val) : key(key), val(val) {}
};

class PPDL {
public:
    long key;
    long val[2];
    PPDL(long key, long val[]) : key(key) {
        memcpy(this->val, val, sizeof(val));
    }
    void dump() {
        cout << "key = " << key << "  val ";
        for(int i = 0; i < 2; i++) {
            cout << "[" << val[i] << "] ";
        }
        cout << endl;
    }
};

class PPKEY {
private:
    int key, val;
public:
    PPKEY(int key, int val) : key(key), val(val) {}
    int getKey() const { return key; }
    int getVal() const { return val; }
    bool operator==(const PPKEY& other) const {
        return key == other.key && val == other.val;
    }
    bool operator<(const PPKEY& other) const {
        return key < other.key || (key == other.key && val < other.val);
    }
};

class PPLKEY {
private:
    long key, val;
public:
    PPLKEY(long key, long val) : key(key), val(val) {}
    long getKey() const { return key; }
    long getVal() const { return val; }
    bool operator==(const PPLKEY& other) const {
        return key == other.key && val == other.val;
    }
    bool operator<(const PPLKEY& other) const {
        return key < other.key || (key == other.key && val < other.val);
    }
};

class Pair {
public:
    int key, val;
    Pair(int key, int val) : key(key), val(val) {}
};

class MyInput {
private:
    FILE* in;
    int pos, readLen;
    char buffer[1024 * 8];
    char str[500 * 8 * 2];
    bool isDigit[256], isSpace[256], isLineSep[256];
public:
    MyInput(FILE* is) : in(is) {
        for (int i = 0; i < 10; i++) {
            isDigit['0' + i] = true;
        }
        isDigit['-'] = true;
        isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
        isLineSep['\r'] = isLineSep['\n'] = true;
    }
    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = fread(buffer, 1, sizeof(buffer), in);
            if (readLen <= 0) {
                throw runtime_error("End of file");
            }
        }
        return buffer[pos++];
    }
    int nextInt() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        int ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }
    long nextLong() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        long ret = 0L;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }
    double nextDouble() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        double ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        int cnt = 0;
        for (; i < len; i++) {
            if(str[i] == '.') {
                cnt = 10;
                continue;
            }
            if(cnt == 0) {
                ret = ret * 10 + str[i] - '0';
            } else {
                ret = ret + ((double)(str[i] - '0') / cnt);
                cnt *= 10;
            }
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }
    string nextString() {
        string ret = string(nextDChar()).trim();
        return ret;
    }
    char* nextDChar() {
        int len = 0;
        len = reads(len, isSpace);
        char* ret = new char[len + 1];
        for (int i = 0; i < len; i++) ret[i] = str[i];
        ret[len] = 0x00;
        return ret;
    }
    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) {
                return (char) c;
            }
        }
    }
    int reads(int len, bool* accept) {
        try {
            while (true) {
                int c = read();
                if (accept[c]) {
                    break;
                }
                if (str.length == len) {
                    char* rep = new char[str.length * 3 / 2];
                    memcpy(rep, str, str.length);
                    str = rep;
                }
                str[len++] = (char) c;
            }
        } catch (runtime_error& e) {
        }
        return len;
    }
};

class MapCounter {
private:
    map<int, int> map;
public:
    MapCounter() {}
    MapCounter(bool reverse) {
        if(reverse) {
            map = map<int, int>(greater<int>());
        }
    }
    void add(int key) {
        add(key, 1);
    }
    void add(int key, int cnt) {
        int val = map[key];
        if(val == 0) {
            map[key] = cnt;
        } else {
            map[key] = val + cnt;
        }
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
        int val = map[key];
        if(val == 0) {
            if(minus) {
                map[key] = -cnt;
            }
        } else if(val > cnt || minus) {
            map[key] = val - cnt;
        } else {
            map.erase(key);
        }
    }
    void set(int key, int cnt) {
        map[key] = cnt;
    }
    int getCount(int key) {
        int val = map[key];
        if(val == 0) return 0;
        else return val;
    }
    set<int> getKey() {
        return map.keys();
    }
    int getKeyCount() {
        return map.keys().size();
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
        data[from].erase(remove(data[from].begin(), data[from].end(), to), data[from].end());
    }
    vector<int> get(int key) {
        return data[key];
    }
    bool contains(int key) {
        return data.find(key) != data.end();
    }
    set<int> keySet() {
        set<int> keys;
        for(auto& kv : data) {
            keys.insert(kv.first);
        }
        return keys;
    }
    bool isConnect(int key_1, int key_2) {
        auto it = data.find(key_1);
        if(it == data.end()) return false;
        else return find(it->second.begin(), it->second.end(), key_2) != it->second.end();
    }
    vector<PP> distList(int key) {
        vector<PP> dist;
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key, 0));
        while(!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int pp = wk.key;
            int dd = wk.val;
            mark.insert(pp);
            dist.push_back(wk);
            for(int next : data[pp]) {
                if(mark.find(next) != mark.end()) continue;
                stack.push(PP(next, dd + 1));
            }
        }
        return dist;
    }
    int* distV(int key) {
        int* dist = new int[data.size() + 1];
        memset(dist, -1, sizeof(int) * (data.size() + 1));
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key, 0));
        while(!stack.empty()) {
            PP wk = stack.top();
            stack.pop();
            int pp = wk.key;
            int dd = wk.val;
            mark.insert(pp);
            dist[pp] = dd;
            for(int next : data[pp]) {
                if(mark.find(next) != mark.end()) continue;
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
        for(int next : data[now]) {
            if(next == pre) continue;
            if(mark.find(next) != mark.end()) {
                if(mapLow[now] > mapLow[next]) {
                    mapLow[now] = mapLow[next];
                }
                continue;
            }
            number++;
            low = bridgeDfs(next, now);
            if(mapLow[now] > low) {
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
        for(auto& kv : mapCnt) {
            if(kv.second == mapLow[kv.first]) {
                ans++;
            }
        }
        return ans - 1;
    }
    void dump() {
        for(auto& kv : data) {
            cout << kv.first << " : ";
            for(int val : kv.second) {
                cout << val << " ";
            }
            cout << endl;
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
        for(auto& kv : data) {
            keys.insert(kv.first);
        }
        return keys;
    }
    bool isConnect(int key_1, int key_2) {
        auto it = data.find(key_1);
        if(it == data.end()) return false;
        for(PP p : it->second) {
            if(p.key == key_2) return true;
        }
        return false;
    }
    int distance(int key_1, int key_2) {
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key_1, 0));
        PP wk;
        int key, val;
        vector<PP> list;
        while(!stack.empty()) {
            wk = stack.top();
            stack.pop();
            key = wk.key;
            val = wk.val;
            mark.insert(key);
            if(key == key_2) return val;
            list = data[key];
            for(PP pp : list) {
                if(mark.find(pp.key) != mark.end()) continue;
                stack.push(PP(pp.key, val + pp.val));
            }
        }
        return INT_MAX;
    }
};

class GraphLong {
private:
    map<long, vector<long>> G;
public:
    void add(long key, long value) {
        G[key].push_back(value);
    }
    vector<long> get(long key) {
        return G[key];
    }
};

class GraphLongWith {
private:
    map<long, vector<PPL>> G;
public:
    void add(long key, PPL p) {
        G[key].push_back(p);
    }
    vector<PPL> get(long key) {
        return G[key];
    }
};

class Solver {
private:
    MyInput in;
    ostream& out;
public:
    Solver(MyInput in, ostream& out) : in(in), out(out) {}
    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        char C[H+2][W+2];
        char c[1000];
        for (int i = 0; i < H; i++) {
            strcpy(c, in.nextDChar());
            for (int j = 0; j < W; j++) {
                C[i+1][j+1] = c[j];
            }
        }
        if(H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if(C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' 
                        && C[i][j-1] != '#' && C[i][j+1] != '#' ) {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    MyInput in(stdin);
    ostream& out = cout;
    Solver solver(in, out);
    solver.solve();
    return 0;
}
// End of Code
