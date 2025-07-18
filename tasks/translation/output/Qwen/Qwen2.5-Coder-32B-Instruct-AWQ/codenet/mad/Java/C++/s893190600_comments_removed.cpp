// End of Code
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

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
    long long key, val;
    PPL(long long key, long long val) : key(key), val(val) {}
};

class PPDL {
public:
    long long key;
    vector<long long> val;
    PPDL(long long key, vector<long long> val) : key(key), val(val) {}
    void dump() {
        cout << "key = " << key << "  val ";
        for (int i = 0; i < val.size(); i++) {
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
    int getKey() { return key; }
    int getVal() { return val; }
    bool operator==(const PPKEY& other) const {
        return key == other.key && val == other.val;
    }
};

class PPLKEY {
private:
    long long key, val;
public:
    PPLKEY(long long key, long long val) : key(key), val(val) {}
    long long getKey() { return key; }
    long long getVal() { return val; }
    bool operator==(const PPLKEY& other) const {
        return key == other.key && val == other.val;
    }
};

namespace std {
    template <>
    struct hash<PPKEY> {
        size_t operator()(const PPKEY& k) const {
            return hash<int>()(k.getKey()) ^ hash<int>()(k.getVal());
        }
    };

    template <>
    struct hash<PPLKEY> {
        size_t operator()(const PPLKEY& k) const {
            return hash<long long>()(k.getKey()) ^ hash<long long>()(k.getVal());
        }
    };
}

class MyInput {
private:
    istream& in;
    int pos;
    int readLen;
    char buffer[1024 * 8];
    char str[500 * 8 * 2];
    bool isDigit[256];
    bool isSpace[256];
    bool isLineSep[256];

public:
    MyInput(istream& is) : in(is), pos(0), readLen(0) {
        for (int i = 0; i < 10; i++) {
            isDigit['0' + i] = true;
        }
        isDigit['-'] = true;
        isSpace[' '] = isSpace[''] = isSpace['
'] = isSpace['	'] = true;
        isLineSep[''] = isLineSep['
'] = true;
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = in.readsome(buffer, sizeof(buffer));
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

    long long nextLong() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        long long ret = 0L;
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
            if (str[i] == '.') {
                cnt = 10;
                continue;
            }
            if (cnt == 0) {
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
        string ret(nextDChar());
        ret.erase(remove_if(ret.begin(), ret.end(), [](unsigned char c) { return isspace(c); }), ret.end());
        return ret;
    }

    vector<char> nextDChar() {
        int len = 0;
        len = reads(len, isSpace);
        vector<char> ret(len + 1);
        for (int i = 0; i < len; i++) ret[i] = str[i];
        ret[len] = 0x00;
        return ret;
    }

    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) {
                return (char)c;
            }
        }
    }

    int reads(int len, bool accept[]) {
        try {
            while (true) {
                int c = read();
                if (accept[c]) {
                    break;
                }
                if (sizeof(str) == len) {
                    vector<char> rep(sizeof(str) * 3 / 2);
                    copy(str, str + sizeof(str), rep.begin());
                    str = rep.data();
                }
                str[len++] = (char)c;
            }
        } catch (const runtime_error& e) {
        }
        return len;
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
        for (const auto& pair : data) {
            keys.insert(pair.first);
        }
        return keys;
    }

    bool isConnect(int key_1, int key_2) {
        auto it = data.find(key_1);
        if (it != data.end()) {
            return find(it->second.begin(), it->second.end(), key_2) != it->second.end();
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
            mark.insert(pp);

            dist.push_back(PP(pp, dd));

            vector<int> list = get(pp);

            for (int next : list) {
                if (mark.find(next) != mark.end()) continue;
                stack.push(PP(next, dd + 1));
            }
        }
        return dist;
    }

    vector<int> distV(int key) {
        vector<int> dist(data.size() + 1, -1);
        set<int> mark;
        stack<PP> stack;
        stack.push(PP(key, 0));

        while (!stack.empty()) {
            PP wk = stack.top();
            stack.pop();

            int pp = wk.key;
            int dd = wk.val;
            mark.insert(pp);

            dist[pp] = dd;

            vector<int> list = get(pp);

            for (int next : list) {
                if (mark.find(next) != mark.end()) continue;
                stack.push(PP(next, dd + 1));
            }
        }
        return dist;
    }

    int bridgeDfs(int now, int pre, map<int, int>& mapCnt, map<int, int>& mapLow, set<int>& mark, int& number) {
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
            low = bridgeDfs(next, now, mapCnt, mapLow, mark, number);
            if (mapLow[now] > low) {
                mapLow[now] = low;
            }
        }
        return mapLow[now];
    }

    int bridgeCnt(int start) {
        map<int, int> mapCnt;
        map<int, int> mapLow;
        set<int> mark;
        int number = 0;
        bridgeDfs(start, start, mapCnt, mapLow, mark, number);
        int ans = 0;
        for (const auto& pair : mapCnt) {
            if (pair.second == mapLow[pair.first]) {
                ans++;
            }
        }
        return ans - 1;
    }

    void dump() {
        for (const auto& pair : data) {
            cout << pair.first << " : ";
            for (int val : pair.second) {
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

    bool isConnect(int key_1, int key_2) {
        auto it = data.find(key_1);
        if (it != data.end()) {
            for (const PP& p : it->second) {
                if (p.key == key_2) {
                    return true;
                }
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
