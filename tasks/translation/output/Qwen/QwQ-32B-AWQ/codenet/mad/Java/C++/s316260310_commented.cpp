#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class Helper {
public:
    long MOD;
    int MAXN;
    mt19937 rnd; // Random number generator

    // Static members
    static vector<int> sieve;
    static vector<int> primes;
    static vector<long long> factorial;

    // I/O related static members
    static const int BUFSIZE = 1 << 20;
    static char buf[BUFSIZE];
    static int index;
    static int total;
    static istream* in;
    static ostream* out;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn), rnd(random_device{}()) {}

    void setSieve() {
        sieve.assign(MAXN, 0);
        primes.clear();
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
        factorial.assign(MAXN, 0);
        factorial[0] = 较早的版本1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = factorial[i - 1] * i % MOD;
        }
    }

    long getFactorial(int n) {
        if (factorial.empty()) setFactorial();
        return factorial[n];
    }

    long ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial.empty()) setFactorial();
        long numerator = factorial[n];
        long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * pow(denominator, MOD - 2, MOD) % MOD;
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

    string joinElements(const vector<long long>& ar) {
        stringstream ss;
        for (long long itr : ar) ss << itr << " ";
        return ss.str();
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void shuffle(vector<int>& ar) {
        for (int i = 0; i < ar.size(); ++i) {
            int r = rnd() % ar.size();
            if (r != i) swap(ar[i], ar[r]);
        }
    }

    long pow(long base, long exp, long mod) {
        base %= mod;
        long ret = 1;
        while (exp > 0) {
            if (exp & 1) ret = ret * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ret;
    }

    void initIO(istream& is, ostream& os) {
        in = &is;
        out = &os;
        index = total = 0;
    }

    void initIO(const string& inputFile, const string& outputFile) {
        in = new ifstream(inputFile);
        out = new ofstream(outputFile);
        index = total = 0;
    }

    int scan() {
        if (index >= total) {
            index = 0;
            total = in->read(buf, BUFSIZE);
            if (total == -1) total = 0;
        }
        return (index < total) ? static_cast<unsigned char>(buf[index++]) : -1;
    }

    string next() {
        int c;
        while ((c = scan()) <= 32) ;
        string s;
        while (c > 32) {
            s += c;
            c = scan();
        }
        return s;
    }

    int nextInt() {
        int c, val = 0;
        while ((c = scan()) <= 32) ;
        bool neg = c == '-';
        if (c == '-' || c == '+') c = scan();
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    long long nextLong() {
        int c;
        long long val = 0;
        while ((c = scan()) <= 32) ;
        bool neg = c == '-';
        if (c == '-' || c == '+') c = scan();
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = scan();
        }
        return neg ? -val : val;
    }

    void print(const string& s) {
        *out << s;
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

// Define static members
vector<int> Helper::sieve;
vector<int> Helper::primes;
vector<long long> Helper::factorial;
char Helper::buf[Helper::BUFSIZE];
int Helper::index = 0;
int Helper::total = 0;
istream* Helper::in = nullptr;
ostream* Helper::out = nullptr;

class Solver {
public:
    Helper hp;
    const int MAXN = 1000006;
    const long MOD = 1e9 + 7;

    bool TESTCASES = false;

    Solver() : hp(MOD, MAXN) {
        hp.initIO(cin, cout);
    }

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
        vector<int> vis(N, 0); // Changed from vector<bool> to vector<int>
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = 1;
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
            int cycleSize = cycle.size();
            hp.println(to_string(cycle[(int)(K % cycleSize)] + 1));
        }
    }
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
