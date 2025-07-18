#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1000006;

class Helper {
public:
    Helper(long long mod, int maxn) : MOD(mod), MAXN(maxn) {
        setSieve();
        setFactorial();
    }

    void setSieve() {
        primes.clear();
        sieve.assign(MAXN, 0);
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
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = factorial[i - 1] * i % MOD;
        }
    }

    long long getFactorial(int n) {
        return factorial[n];
    }

    long long ncr(int n, int r) {
        if (r > n) return 0;
        long long numerator = factorial[n];
        long long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * pow(denominator, MOD - 2, MOD) % MOD;
    }

    vector<long long> getLongArray(int size) {
        vector<long long> ar(size);
        for (int i = 0; i < size; ++i) {
            ar[i] = nextLong();
        }
        return ar;
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) {
            ar[i] = nextInt();
        }
        return ar;
    }

    vector<string> getStringArray(int size) {
        vector<string> ar(size);
        for (int i = 0; i < size; ++i) {
            ar[i] = next();
        }
        return ar;
    }

    string joinElements(const vector<long long>& ar) {
        stringstream ss;
        for (long long itr : ar) {
            ss << itr << " ";
        }
        return ss.str();
    }

    string joinElements(const vector<int>& ar) {
        stringstream ss;
        for (int itr : ar) {
            ss << itr << " ";
        }
        return ss.str();
    }

    string joinElements(const vector<string>& ar) {
        stringstream ss;
        for (const string& itr : ar) {
            ss << itr << " ";
        }
        return ss.str();
    }

    string joinElements(const vector<void*>& ar) {
        stringstream ss;
        for (const void* itr : ar) {
            ss << itr << " ";
        }
        return ss.str();
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long max(const vector<long long>& ar) {
        long long ret = ar[0];
        for (long long itr : ar) {
            ret = max(ret, itr);
        }
        return ret;
    }

    int max(const vector<int>& ar) {
        int ret = ar[0];
        for (int itr : ar) {
            ret = max(ret, itr);
        }
        return ret;
    }

    long long min(const vector<long long>& ar) {
        long long ret = ar[0];
        for (long long itr : ar) {
            ret = min(ret, itr);
        }
        return ret;
    }

    int min(const vector<int>& ar) {
        int ret = ar[0];
        for (int itr : ar) {
            ret = min(ret, itr);
        }
        return ret;
    }

    long long sum(const vector<long long>& ar) {
        long long sum = 0;
        for (long long itr : ar) {
            sum += itr;
        }
        return sum;
    }

    long long sum(const vector<int>& ar) {
        long long sum = 0;
        for (int itr : ar) {
            sum += itr;
        }
        return sum;
    }

    void shuffle(vector<int>& ar) {
        random_device rd;
        mt19937 g(rd());
        shuffle(ar.begin(), ar.end(), g);
    }

    void shuffle(vector<long long>& ar) {
        random_device rd;
        mt19937 g(rd());
        shuffle(ar.begin(), ar.end(), g);
    }

    void reverse(vector<int>& ar) {
        reverse(ar.begin(), ar.end());
    }

    void reverse(vector<long long>& ar) {
        reverse(ar.begin(), ar.end());
    }

    long long pow(long long base, long long exp, long long MOD) {
        base %= MOD;
        long long ret = 1;
        while (exp > 0) {
            if (exp & 1) {
                ret = ret * base % MOD;
            }
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }

    void initIO(istream& is, ostream& os) {
        in = &is;
        out = &os;
    }

    void initIO(const string& inputFile, const string& outputFile) {
        ifstream ifs(inputFile);
        ofstream ofs(outputFile);
        in = &ifs;
        out = &ofs;
    }

    int scan() {
        if (index >= total) {
            index = 0;
            total = in->read(buf, BUFSIZE);
            if (total <= 0) {
                return -1;
            }
        }
        return buf[index++];
    }

    string next() {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        stringstream ss;
        for (; c > 32; c = scan()) {
            ss << (char)c;
        }
        return ss.str();
    }

    int nextInt() {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }

    long long nextLong() {
        int c;
        long long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }

    void print(const string& a) {
        *out << a;
    }

    void printsp(const string& a) {
        print(a);
        print(" ");
    }

    void println() {
        *out << "\n";
    }

    void println(const string& a) {
        print(a);
        println();
    }

    void flush() {
        out->flush();
    }

private:
    long long MOD;
    int MAXN;
    vector<int> primes;
    vector<int> sieve;
    vector<long long> factorial;
    istream* in;
    ostream* out;
    static const int BUFSIZE = 1 << 20;
    char buf[BUFSIZE];
    int index = 0;
    int total = 0;
};

class Solver {
public:
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
            hp.println(straight[K] + 1);
        } else {
            K -= straight.size();
            hp.println(cycle[K % cycle.size()] + 1);
        }
    }

private:
    Helper hp;
    const int MAXN = 1000006;
    const long long MOD = 1e9 + 7;
    const bool TESTCASES = false;
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
