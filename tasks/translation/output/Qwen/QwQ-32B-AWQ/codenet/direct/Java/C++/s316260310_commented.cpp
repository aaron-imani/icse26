#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Helper {
private:
    static const int BUFSIZE = 1 << 20;
    static char buf[BUFSIZE];
    static int index;
    static int total;
    static FILE *in;
    long MOD;
    int MAXN;
    vector<int> sieve;
    vector<int> primes;
    vector<long> factorial;

public:
    Helper(long mod, int maxn);
    int nextInt();
    long nextLong();
    string next();
    void print(const string &);
    void printsp(const string &);
    void println();
    void println(const string &);
    void flush();

private:
    static int scan();
};

char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;
FILE *Helper::in = stdin;

int Helper::scan() {
    if (index >= total) {
        index = 0;
        total = fread(buf, 1, BUFSIZE, in);
        if (total <= 0) return -1;
    }
    return buf[index++];
}

Helper::Helper(long mod, int maxn) : MOD(mod), MAXN(maxn) {}

int Helper::nextInt() {
    int c, val = 0;
    for (c = scan(); c <= 32; c = scan());
    bool neg = c == '-';
    if (c == '-' || c == '+') {
        c = scan();
    }
    for (; c >= '0' && c <= '9'; c = scan()) {
        val = (val << 3) + (val << 1) + (c & 15);
    }
    return neg ? -val : val;
}

long Helper::nextLong() {
    int c;
    long val = ️;
    for (c = scan(); c <= 32; c = scan());
    bool neg = c == '-';
    if (c == '-' || c == '+') {
        c = scan();
    }
    for (; c >= '0' && c <= '9'; c = scan()) {
        val = (val << 3) + (val << 1) + (c & 15);
    }
    return neg ? -val : val;
}

string Helper::next() {
    int c;
    for (c = scan(); c <= 32; c = scan());
    string s;
    for (; c > 32; c = scan()) {
        s += (char)c;
    }
    return s;
}

void Helper::print(const string &s) {
    cout << s;
}

void Helper::printsp(const string &s) {
    cout << s << " ";
}

void Helper::println() {
    cout << "\n";
}

void Helper::println(const string &s) {
    cout << s << "\n";
}

void Helper::flush() {
    cout.flush();
}

class Solver {
private:
    Helper hp;
    const int MAXN = 1000006;
    const long MOD = 1e9 + 7;
    bool TESTCASES = false;

public:
    Solver() : hp(MOD, MAXN) {}
    void solve();
    void solve(int tc);
};

void Solver::solve() {
    int tc = TESTCASES ? hp.nextInt() : 1;
    for (int tce = 1; tce <= tc; ++tce) {
        solve(tce);
    }
    hp.flush();
}

void Solver::solve(int tc) {
    int N = hp.nextInt();
    long long K = hp.nextLong();
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = hp.nextInt();
    }

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

    if (K < static_cast<long long>(straight.size())) {
        hp.println(to_string(straight[K] + 1));
    } else {
        K -= static_cast<long long>(straight.size());
        int idx = static_cast<int>(K % cycle.size());
        hp.println(to_string(cycle[idx] + 1));
    }
}

int main() {
    Solver solver;
    solver.solve();
    return 0;
} // End of Code
