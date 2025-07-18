#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Helper {
private:
    static const int BUFSIZE = 1 << 20;
    static char buf[BUFSIZE];
    static int index, total;

    static int scan() {
        if (index >= total) {
            index = 0;
            total = fread(buf, 1, BUFSIZE, stdin);
            if (total <= 0) return -1;
        }
        return buf[index++];
    }

public:
    long long MOD;
    int MAXN;

    Helper(long long mod, int maxn) : MOD(mod), MAXN(maxn) {}

    string next() {
        int c;
        for (c = scan(); c <= 32; c = scan());
        string s;
        for (; c > 32; c = scan())
            s.push_back((char)c);
        return s;
    }

    int nextInt() {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan());
        bool neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan())
            val = val * 10 + (c - '0');
        return neg ? -val : val;
    }

    long long nextLong() {
        int c;
        long long val = 0;
        for (c = scan(); c <= 32; c = scan());
        bool neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan())
            val = val * 10 + (c - '0');
        return neg ? -val : val;
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    void print(const string& a) { cout << a; }
    void printsp(const string& a) { cout << a << ' '; }
    void println() { cout << '\n'; }
    void println(const string& a) { cout << a << '\n'; }
    void flush() { cout << flush; }
};

char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;

class Solver {
private:
    Helper hp;
    const int MAXN = 1000006;
    const long long MOD = 1e9 +7;
    bool TESTCASES = false;

public:
    Solver() : hp(MOD, MAXN) {}

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) {
            solve(tce);
        }
        hp.flush();
    }

    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A = hp.getIntArray(N);

        vector<int> straight;
        vector<int> cycle;
        vector<bool> vis(N, false);
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr] - 1;
        }

        int st = 0;
        while (st != curr) {
            straight.push_back(st);
            st = A[st] - 1;
        }

        cycle.push_back(curr);
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle.push_back(curr);
            curr = A[curr] - 1;
        }

        if (K < straight.size()) {
            hp.println(to_string(straight[K] + 1));
        } else {
            K -= straight.size();
            int idx = K % cycle.size();
            hp.println(to_string(cycle[idx] + 1));
        }
    }
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
