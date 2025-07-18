#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Helper {
public:
    long MOD;
    int MAXN;
    vector<int> sieve;
    vector<int> primes;
    vector<long long> factorial;
    char buf[1 << 20];
    int index, total;
    istream* in;
    ostream* out;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn) {
        sieve.resize(MAXN);
        primes.clear();
        factorial.resize(0);
        index = total = 0;
        in = nullptr;
        out = nullptr;
    }

    void initIO(istream& is, ostream& os) {
        in = &is;
        out = &os;
        index = total = 0;
    }

    int scan() {
        if (index >= total) {
            if (in->eof()) return -1;
            total = in->read(buf, sizeof(buf)) ? in->gcount() : 0;
            index = 0;
        }
        return total <= 0 ? -1 : static_cast<unsigned char>(buf[index++]);
    }

    string next() {
        int c;
        while ((c = scan()) <= 32);
        string s;
        while (c > 32) {
            s += (char)c;
            c = scan();
        }
        return s;
    }

    int nextInt() {
        int c;
        while ((c = scan()) <= 32);
        bool neg = false;
        if (c == '-' || c == '+') {
            neg = (c == '-');
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
        while ((c = scan()) <= 32);
        bool neg = false;
        if (c == '-' || c == '+') {
            neg = (c == '-');
            c = scan();
        }
        long long val = 0;
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    void print(const string& s) { *out << s; }
    void print(int a) { *out << a; }
    void print(long long a) { *out << a; }
    void printsp(const string& s) { *out << s << ' '; }
    void printsp(int a) { *out << a << ' '; }
    void printsp(long long a) { *out << a << ' '; }
    void println() { *out << '\n'; }
    void println(const string& s) { *out << s << '\n'; }
    void println(int a) { *out << a << '\n'; }
    void println(long long a) { *out << a << '\n'; }
    void flush() { out->flush(); }
};

class Solver {
public:
    Helper hp;
    const int MAXN = 1000006;
    const long long MOD = 1e9 + 7;

    Solver() {
        hp = Helper(MOD, MAXN);
        hp.initIO(cin, cout);
    }

    void solve() {
        int tc = 1;
        for (int tce = 1; tce <= tc; ++tce)
            solve(tce);
        hp.flush();
    }

private:
    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = hp.nextInt() - 1;

        vector<int> straight, cycle;
        vector<bool> vis(N, false);
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

        if (K < static_cast<long long>(straight.size())) {
            hp.println(straight[K] + 1);
        } else {
            K -= straight.size();
            int cycle_size = cycle.size();
            hp.println(cycle[K % cycle_size] + 1);
        }
    }
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
} // End of Code
