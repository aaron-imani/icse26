#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

struct PP {
    int key, val;
};

class MyInput {
private:
    istream& in;
    char buffer[1024 * 8];
    int pos = 0;
    int readLen = 0;

    char nextChar() {
        if (pos >= readLen) {
            pos = 0;
            readLen = in.read(buffer, sizeof(buffer)).gcount();
            if (readLen <= 0) throw runtime_error("EOF");
        }
        return buffer[pos++];
    }

    bool isSpace(char c) {
        return c == ' ' || c == '\r' || c == '\n' || c == '\t';
    }

public:
    MyInput(istream& is) : in(is) {}

    int nextInt() {
        char c = nextChar();
        while (isSpace(c)) c = nextChar();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = nextChar();
        }
        int num = 0;
        while (!isSpace(c) && c != EOF) {
            num = num * 10 + (c - '0');
            c = nextChar();
        }
        return num * sign;
    }

    string nextString() {
        char c = nextChar();
        while (isSpace(c)) c = nextChar();
        string ret;
        while (!isSpace(c) && c != EOF) {
            ret.push_back(c);
            c = nextChar();
        }
        return ret;
    }
};

class MapCounter {
private:
    map<int, int> map_;
    bool reverseOrder;
public:
    MapCounter(bool reverse = false) : reverseOrder(reverse) {}

    void add(int key, int cnt = 1) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            it->second += cnt;
        } else {
            map_[key] = cnt;
        }
    }

    void remove(int key) {
        sub(key, 1);
    }

    void sub(int key, int cnt = 1) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            int val = it->second;
            if (val > cnt) {
                it->second -= cnt;
            } else {
                map_.erase(it);
            }
        }
    }

    int getCount(int key) const {
        auto it = map_.find(key);
        return it != map_.end() ? it->second : 0;
    }
};

class Graph {
private:
    unordered_map<int, vector<int>> data_;
public:
    void add(int from, int to) {
        data_[from].push_back(to);
    }

    vector<int> get(int key) const {
        auto it = data_.find(key);
        return it != data_.end() ? it->second : vector<int>();
    }

    bool contains(int key) const {
        return data_.find(key) != data_.end();
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
        vector<vector<char>> C(H + 2, vector<char>(W + 2, ' '));
        for (int i = 0; i < H; ++i) {
            string s = in.nextString();
            for (int j = 0; j < W; ++j) {
                C[i + 1][j + 1] = s[j];
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

    void prn(const string& s) {
        out << s << endl;
    }

    int ni() { return in.nextInt(); }
    string ns() { return in.nextString(); }
};

int main() {
    MyInput in(cin);
    ostream& out = cout;
    Solver solver(in, out);
    solver.solve();
    return 0;
}

// End of Code
