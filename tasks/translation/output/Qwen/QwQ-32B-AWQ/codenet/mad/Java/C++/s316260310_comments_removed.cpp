#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int BUFSIZE = 1 << 20;

class Helper {
public:
    long MOD;
    static const int MAXN = 1000006;
    mt19937 rnd;

    static char buf[BUFSIZE];
    static int index;
    static int total;
    static vector<int> primes;
    static int sieve[MAXN];
    static vector<long> factorial;

    Helper(long mod, int /*maxn*/) : MOD(mod) {
        random_device rd;
        rnd.seed(rd());
    }

    void setSieve() {
        primes.clear();
        for (int i = 0; i < MAXN; ++i) sieve[i] = 0;
        for (int i = 2; i < MAXN; ++i) {
            if (sieve[i] == 0) {
                primes.push_back(i);
                for (int j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
        }
    }

    void setFactorial() {
        factorial.resize(MAXN);
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
        }
    }

    int scan() {
        if (index >= total) {
            index = 0;
            total = fread(buf, 1, BUFSIZE, stdin);
            if (total <= 0) return -1;
        }
        return buf[index++];
    }

    string next() {
        int c;
        while ((c = scan()) <= 32);
        string ret;
        while (c > 32) {
            ret += (char)c;
            c = scan();
        }
        return ret;
    }

    int nextInt() {
        int c, val = 0;
        while ((c = scan()) <= 32);
        bool neg = (c == '-');
        if (c == '-' || c == '+') c = scan();
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    long nextLong() {
        int c;
        long val = 0;
        while ((c = scan()) <= 32);
        bool neg = (c == '-');
        if (c == '-' || c == '+') c = scan();
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    void print(const string& s) { cout << s; }
    void printsp(const string& s) { cout << s << ' '; }
    void println() { cout << '
'; }
    void println(const string& s) { cout << s << '
'; }
    void flush() { cout.flush(); }
};

char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;
vector<int> Helper::primes;
int Helper::sieve[Helper::MAXN];
vector<long> Helper::factorial;

class Solver {
    Helper hp;
    const bool TESTCASES = false;

public:
    Solver() : hp(1e9 + 7, Helper::MAXN) {}

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
        hp.flush();
    }

    void solve(int tc) {
        int N = hp.nextInt();
        long K = hp.nextLong();
        vector<int> A = hp.getIntArray(N);

        vector<int> straight, cycle;
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
            hp.println(to_string(cycle[K % cycle.size()] + 1));
        }
    }
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
