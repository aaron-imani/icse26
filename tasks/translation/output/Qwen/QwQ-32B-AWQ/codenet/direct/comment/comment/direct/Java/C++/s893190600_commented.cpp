#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <string>
#include <set>
#include <utility>
#include <functional>
#include <limits>

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
        for (long long num : val) {
            out << "[" << num << "] ";
        }
        out << endl;
    }
};

struct PPKEY {
    int key, val;
    PPKEY(int k, int v) : key(k), val(v) {}
};

namespace std {
    template<>
    struct hash<PPKEY> {
        size_t operator()(const PPKEY& p) const {
            return hash<int>{}(p.key) ^ hash<int>{}(p.val);
        }
    };
}

struct PPLKEY {
    long long key, val;
    PPLKEY(long long k, long long v) : key(k), val(v) {}
};

namespace std {
    template<>
    struct hash<PPLKEY> {
        size_t operator()(const PPLKEY& p) const {
            return hash<long long>{}(p.key) ^ hash<long long>{}(p.val);
        }
    };
}

class MyInput {
private:
    istream& in;
    char buffer[1024 * 8];
    int pos = 0;
    int readLen = 0;
    char str[500 * 8 * 2];
    bool isDigit[256];
    bool isSpace[256];
    bool isLineSep[256];

public:
    MyInput(istream& is) : in(is) {
        for (int i = 0; i < 256; ++i) {
            isDigit[i] = false;
            isSpace[i] = false;
            isLineSep[i] = false;
        }
        for (int i = 0; i < 10; ++i) {
            isDigit['0' + i] = true;
        }
        isDigit['-'] = true;
        isSpace[' '] = true;
        isSpace['\r'] = true;
        isSpace['\n'] = true;
        isSpace['\t'] = true;
        isLineSep['\r'] = true;
        isLineSep['\n'] = true;
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            in.read(buffer, sizeof(buffer));
            readLen = static_cast<int>(in.gcount());
            if (readLen <= 0) {
                throw runtime_error("End of file");
            }
        }
        return buffer[pos++];
    }

    int nextInt() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        while (true) {
            c = static_cast<char>(read());
            if (isSpace[c]) {
                break;
            }
            str[len++] = c;
        }
        int i = 0;
        int ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; ++i) {
            ret = ret * 10 + (str[i] - '0');
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    long long nextLong() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        while (true) {
            c = static_cast<char>(read());
            if (isSpace[c]) {
                break;
            }
            str[len++] = c;
        }
        int i = 0;
        long long ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; ++i) {
            ret = ret * 10 + (str[i] - '0');
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    double nextDouble() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        while (true) {
            c = static_cast<char>(read());
            if (isSpace[c]) {
                break;
            }
            str[len++] = c;
        }
        int i = 0;
        double ret = 0;
        bool isNegative = (str[0] == '-');
        if (isNegative) i = 1;
        int cnt = 0;
        for (; i < len; ++i) {
            if (str[i] == '.') {
                cnt = 10;
                continue;
            }
            if (cnt == 0) {
                ret = ret * 10 + (str[i] - '0');
            } else {
                ret += static_cast<double>(str[i] - '0') / cnt;
                cnt *= 10;
            }
        }
        if (isNegative) ret = -ret;
        return ret;
    }

    string nextString() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        while (true) {
            c = static_cast<char>(read());
            if (isSpace[c]) {
                break;
            }
            str[len++] = c;
        }
        return string(str, len);
    }

    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) {
                return static_cast<char>(c);
            }
        }
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

    vector<int> get(int key) const {
        auto it = data.find(key);
        return it == data.end() ? vector<int>() : it->second;
    }

    bool isConnect(int key1, int key2) const {
        auto it = data.find(key1);
        if (it == data.end()) return false;
        const vector<int>& list = it->second;
        for (int v : list) {
            if (v == key2) return true;
        }
        return false;
    }
};

class MapCounter {
private:
    map<int, int> map;

public:
    void add(int key, int cnt = 1) {
        auto it = map.find(key);
        if (it == map.end()) {
            map[key] = cnt;
        } else {
            it->second += cnt;
        }
    }

    void sub(int key, int cnt = 1, bool minus = true) {
        auto it = map.find(key);
        if (it == map.end()) {
            if (minus) {
                map[key] = -cnt;
            }
        } else {
            int val = it->second - cnt;
            if (val < 0 && !minus) {
                map.erase(it);
            } else {
                it->second = val;
            }
        }
    }

    int getCount(int key) const {
        auto it = map.find(key);
        return it == map.end() ? 0 : it->second;
    }

    int getFirstKey() const {
        return map.begin()->first;
    }
};

class EulerTour {
private:
    Graph g;
    vector<int> euler_tour;
    vector<int> begin, end;
    int root;

public:
    void dfs(int v, int p) {
        euler_tour.push_back(v);
        if (!g.contains(v)) return;
        for (int i : g.get(v)) {
            if (i != p) {
                dfs(i, v);
                euler_tour.push_back(v);
            }
        }
    }

    void init(int r, const Graph& graph) {
        g = graph;
        root = r;
        dfs(root, -1);
    }

    vector<int> getPartTour(int v) {
        int start = begin[v];
        int end = this->end[v];
        return vector<int>(euler_tour.begin() + start, euler_tour.begin() + end);
    }
};

class Solver {
private:
    MyInput& in;
    ostream& out;

public:
    Solver(MyInput& in_, ostream& out_) : in(in_), out(out_) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2, ' '));
        for (int i = 1; i <= H; ++i) {
            string s = in.nextString();
            for (int j = 1; j <= W; ++j) {
                C[i][j] = s[j - 1];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#') {
                    if (C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                        C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                        out << "No" << endl;
                        return;
                    }
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MyInput in(cin);
    ostream& out = cout;
    Solver solver(in, out);
    solver.solve();
    return 0;
}
// End of Code
