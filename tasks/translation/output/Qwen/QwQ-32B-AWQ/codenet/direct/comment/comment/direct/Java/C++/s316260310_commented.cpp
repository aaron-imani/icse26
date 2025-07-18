#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

struct Helper {
    long MOD;
    int MAXN;
    mt19937 rnd;

    static const int BUFSIZE = 1 << 20;
    static char buf[BUFSIZE];
    static int index;
    static int total;
    static istream* in;
    static ostream* out;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn) {
        random_device rd;
        rnd = mt19937(rd());
    }

    static void initIO(istream& is, ostream& os) {
        in = &is;
        out = &os;
        index = total = 0;
    }

    static int scan() {
        if (index >= total) {
            index = 0;
            total = in->read(buf, BUFSIZE);
            if (total <= 0) return -1;
        }
        return static_cast<unsigned char>(buf[index++]);
    }

    string next() {
        int c;
        for (c = scan(); c <= 32; c = scan());
        string s;
        for (; c > 32; c = scan())
            s += static_cast<char>(c);
        return s;
    }

    int nextInt() {
        int c = scan();
        while (c <= 32) c = scan();
        bool neg = (c == '-');
        int ret = 0;
        if (neg) c = scan();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + (c - '0');
            c = scan();
        }
        return neg ? -ret : ret;
    }

    long long nextLong() {
        int c = scan();
        while (c <= 32) c = scan();
        bool neg = (c == '-');
        long long ret = 0;
        if (neg) c = scan();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + (c - '0');
            c = scan();
        }
        return neg ? -ret : ret;
    }

    void print(const string& s) {
        *out << s;
    }

    void printsp(const string& s) {
        *out << s << ' ';
    }

    void println() {
        *out << '\n';
    }

    void println(const string& s) {
        *out << s << '\n';
    }

    void flush() {
        out->flush();
    }
};

char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;
istream* Helper::in = &cin;
ostream* Helper::out = &cout;

class Solver {
    Helper hp;
    const int MAXN;
    const long MOD;
    bool TESTCASES;

public:
    Solver() : MAXN(1000006), MOD(1000000007), hp(MOD, MAXN), TESTCASES(false) {
        hp.initIO(cin, cout);
    }

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) {
            solve(tce);
        }
        hp.flush();
    }

private:
    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            A[i] = hp.nextInt();
        }

        vector<bool> vis(N, false);
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr] - 1;
        }

        int st = 0;
        vector<int> straight;
        while (st != curr) {
            straight.push_back(st);
            st = A[st] - 1;
        }

        vector<int> cycle;
        cycle.push_back(curr);
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle.push_back(curr);
            curr = A[curr] - 1;
        }

        if (K < static_cast<long long>(straight.size())) {
            hp.println(to_string(straight[K] + 1));
        } else {
            K -= static_cast<long long>(straight.size());
            int pos = static_cast<int>(K % cycle.size());
            hp.println(to_string(cycle[pos] + 1));
        }
    }
};

int main() {
    Solver().solve();
    return 0;
}
// End of Code
