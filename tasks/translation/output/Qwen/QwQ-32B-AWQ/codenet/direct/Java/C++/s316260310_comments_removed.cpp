#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdio>
using namespace std;

class Helper {
public:
    static const int BUFSIZE = 1 << 20;
    static char buf[BUFSIZE];
    static int index, total;
    long MOD;
    int MAXN;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn) {}

    void initIO() {
        index = 0;
        total = 0;
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
    }

    int nextInt() {
        int c;
        while ((c = scan()) <= 32 && c != -1);
        if (c == -1) throw runtime_error("EOF on nextInt");
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = scan();
        }
        int val = 0;
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    long long nextLong() {
        int c;
        while ((c = scan()) <= 32 && c != -1);
        if (c == -1) throw runtime_error("EOF on nextLong");
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = scan();
        }
        long long val = 0;
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    string next() {
        int c;
        while ((c = scan()) <= 32 && c != -1);
        if (c == -1) throw runtime_error("EOF on next");
        stringstream ss;
        do {
            ss << static_cast<char>(c);
            c = scan();
        } while (c > 32 && c != -1);
        return ss.str();
    }

    static int scan() {
        if (index >= total) {
            total = fread(buf, 1, BUFSIZE, stdin);
            index = 0;
            if (total <= 0) return -1;
        }
        int c = static_cast<unsigned char>(buf[index++]);
        return c;
    }

    void print(const string& s) { cout << s; }
    void printsp(const string& s) { cout << s << ' '; }
    void println() { cout << '\n'; }
    void println(const string& s) { cout << s << '\n'; }
    void flush() { cout << flush; }
};

char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;

class Solver {
public:
    const int MAXN = 1000006;
    const long long MOD = 1e9 + 7;
    Helper hp;
    Solver() : hp(MOD, MAXN) { hp.initIO(); }

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce)
            solve(tce);
        hp.flush();
    }

    bool TESTCASES = false;

    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = hp.nextInt() - 1;

        vector<int> straight, cycle;
        vector<bool> vis(N);
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr];
        }

        int st = 0;
        while (st != curr) {
            straight.push_back(st);
            st = A[st];
        }

        cycle.push_back(curr);
        curr = A[curr];
        while (curr != cycle[0]) {
            cycle.push_back(curr);
            curr = A[curr];
        }

        if (K < straight.size())
            hp.println(to_string(straight[K] + 1));
        else {
            K -= straight.size();
            hp.println(to_string(cycle[K % cycle.size()] + 1));
        }
    }
};

int main() {
    Solver().solve();
    return 0;
}
// End of Code
