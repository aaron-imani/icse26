#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Helper {
private:
    long long MOD;
    int MAXN;
public:
    Helper(long long mod, int maxn) : MOD(mod), MAXN(maxn) {}

    static const int BUFSIZE = 1 << 20;
    static char buf[BUFSIZE];
    static int index, total;

    static void initIO() {
        index = 0;
        total = 0;
    }

    static int scan() {
        if (index >= total) {
            index = 0;
            total = fread(buf, 1, BUFSIZE, stdin);
            if (total <= 0) return -1;
        }
        return buf[index++];
    }

    int nextInt() {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = false;
        if (c == '-' || c == '+') {
            neg = (c == '-');
            c = scan();
        }
        int val = 0;
        for (; c > 32; c = scan()) {
            val = val * 10 + (c - '0');
        }
        return neg ? -val : val;
    }

    long long nextLong() {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = false;
        if (c == '-' || c == '+') {
            neg = (c == '-');
            c = scan();
        }
        long long val = 0;
        for (; c > 32; c = scan()) {
            val = val * 10 + (c - '0');
        }
        return neg ? -val : val;
    }

    string next() {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        string s;
        for (; c > 32; c = scan()) {
            s += (char)c;
        }
        return s;
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    vector<long long> getLongArray(int size) {
        vector<long long> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    void print(int a) { cout << a; }
    void print(long long a) { cout << a; }
    void printsp(int a) { cout << a << " "; }
    void println() { cout << endl; }
    void println(int a) { cout << a << endl; }
    void println(long long a) { cout << a << endl; }
    void flush() { cout.flush(); }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;

class Solver {
private:
    Helper hp;
    const int MAXN = 1000006;
    const long long MOD = 1e9 + 7;

public:
    Solver() : hp(MOD, MAXN) {}

    void solve() {
        bool TESTCASES = false;
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

        if (K < static_cast<long long>(straight.size())) {
            hp.println(straight[K] + 1);
        } else {
            long long rem = K - static_cast<long long>(straight.size());
            int idx = static_cast<int>(rem % cycle.size());
            hp.println(cycle[idx] + 1);
        }
    }
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
