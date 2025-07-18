#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class FastInput {
private:
    FILE *stream;
    char buffer[1 << 17];
    int pos, len;

public:
    FastInput() : stream(stdin), pos(0), len(0) {}

    inline char read() {
        if (pos >= len) {
            len = fread(buffer, 1, sizeof(buffer), stream);
            pos = 0;
            if (len == 0) return EOF;
        }
        return buffer[pos++];
    }

    int nextInt() {
        int sign = 1;
        char c = read();
        while (c == ' ' || c == '\n' || c == '\r') c = read();
        if (c == '-') {
            sign = -1;
            c = read();
        }
        int ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 1瞠 + (c - '0');
            c = read();
        }
        return ret * sign;
    }

    long long nextLong() {
        long long sign = 1;
        char c = read();
        while (c == ' ' || c == '\n' || c == '\r') c = read();
        if (c == '-') {
            sign = -1;
            c = read();
        }
        long long ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + (c - '0');
            c = read();
        }
        return ret * sign;
    }

    string nextString() {
        char c = read();
        while (c == ' ' || c == '\n' || c == '\r') c = read();
        string ret;
        while (c != ' ' && c != '\n' && c != '\r' && c != EOF) {
            ret += c;
            c = read();
        }
        return ret;
    }
};

struct PP {
    int key, val;
    PP(int k, int v) : key(k), val(v) {}
};

struct PPL {
    long key, val;
    PPL(long k, long v) : key(k), val(v) {}
};

class MapCounter {
public:
    map<int, int> map;

    MapCounter(bool reverse) {}

    void add(int key) {
        add(key, 1);
    }

    void add(int key, int cnt) {
        auto it = map.find(key);
        if (it == map.end()) {
            map[key] = cnt;
        } else {
            it->second += cnt;
        }
    }
};

class Graph {
public:
    map<int, vector<int>> data;

    void add(int from, int to) {
        data[from].push_back(to);
    }

    void del(int from, int to) {
        auto it = data.find(from);
        if (it != data.end()) {
            auto& list = it->second;
            auto iter = find(list.begin(), list.end(), to);
            if (iter != list.end()) {
                list.erase(iter);
            }
        }
    }

    vector<int> get(int key) {
        auto it = data.find(key);
        if (it != data.end()) return it->second;
        else return vector<int>();
    }

    bool contains(int key) const {
        return data.count(key) > 0;
    }
};

class EulerTour {
public:
    Graph g;
    vector<int> euler_tour;
    vector<int> begin, end;
    int k = 0, root = 0;

    void dfs(int v, int p, ostream& out) {
        out << "v = " << v << "  p = " << p << endl;
        begin[v] = k;
        euler_tour.push_back(v);
        k++;
        if (!g.contains(v)) return;
        auto list = g.get(v);
        for (int i : list) {
            if (i != p) {
                dfs(i, v, out);
                euler_tour.push_back(v);
                k++;
            }
        }
        end[v] = k;
    }

    void init(int p_cnt, int r, Graph& g, ostream& out) {
        root = r;
        this->g = g;
        begin.resize(p_cnt + 1);
        end.resize(p_cnt + 1);
        dfs(root, -1, out);
    }
};

class Solver {
    FastInput& in;
    ostream& out;

public:
    Solver(FastInput& in, ostream& out) : in(in), out(out) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2, ' '));
        for (int i = 0; i < H; ++i) {
            string s = in.nextString();
            for (int j = 0; j < W; ++j) {
                C[i + 1][j + 1] = s[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No\n";
            return;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#' &&
                    C[i - 1][j] != '#' &&
                    C[i + 1][j] != '#' &&
                    C[i][j - 1] != '#' &&
                    C[i][j + 1] != '#') {
                    out << "No\n";
                    return;
                }
            }
        }
        out << "Yes\n";
    }
};

int main() {
    FastInput in;
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
