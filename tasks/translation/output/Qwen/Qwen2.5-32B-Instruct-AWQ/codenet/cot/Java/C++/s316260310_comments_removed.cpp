#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

class Helper {
public:
    long MOD;
    int MAXN;
    mt19937 rnd;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn), rnd(time(nullptr)) {}

    vector<int> sieve;
    vector<int> primes;

    void setSieve() {
        primes.clear();
        sieve.assign(MAXN, 0);
        for (int i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.push_back(i);
                for (int j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
    }

    vector<long> factorial;

    void setFactorial() {
        factorial.assign(MAXN, 0);
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) factorial[i] = factorial[i - 1] * i % MOD;
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

    vector<long> getLongArray(int size) {
        vector<long> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    vector<string> getStringArray(int size) {
        vector<string> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = next();
        return ar;
    }

    string joinElements(vector<long> ar) {
        string ret;
        for (long itr : ar) ret += to_string(itr) + " ";
        return ret.substr(0, ret.size() - 1);
    }

    string joinElements(vector<int> ar) {
        string ret;
        for (int itr : ar) ret += to_string(itr) + " ";
        return ret.substr(0, ret.size() - 1);
    }

    string joinElements(vector<string> ar) {
        string ret;
        for (string itr : ar) ret += itr + " ";
        return ret.substr(0, ret.size() - 1);
    }

    string joinElements(vector<void*> ar) {
        string ret;
        for (void* itr : ar) ret += to_string(itr) + " ";
        return ret.substr(0, ret.size() - 1);
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long max(vector<long> ar) {
        long ret = ar[0];
        for (long itr : ar) ret = max(ret, itr);
        return ret;
    }

    int max(vector<int> ar) {
        int ret = ar[0];
        for (int itr : ar) ret = max(ret, itr);
        return ret;
    }

    long min(vector<long> ar) {
        long ret = ar[0];
        for (long itr : ar) ret = min(ret, itr);
        return ret;
    }

    int min(vector<int> ar) {
        int ret = ar[0];
        for (int itr : ar) ret = min(ret, itr);
        return ret;
    }

    long sum(vector<long> ar) {
        long sum = 0;
        for (long itr : ar) sum += itr;
        return sum;
    }

    long sum(vector<int> ar) {
        long sum = 0;
        for (int itr : ar) sum += itr;
        return sum;
    }

    void shuffle(vector<int>& ar) {
        for (int i = 0; i < ar.size(); ++i) {
            int r = rnd() % ar.size();
            if (r != i) {
                swap(ar[i], ar[r]);
            }
        }
    }

    void shuffle(vector<long>& ar) {
        for (int i = 0; i < ar.size(); ++i) {
            int r = rnd() % ar.size();
            if (r != i) {
                swap(ar[i], ar[r]);
            }
        }
    }

    void reverse(vector<int>& ar) {
        for (int i = 0; i < ar.size(); ++i) {
            int r = ar.size() - 1 - i;
            if (r > i) {
                swap(ar[i], ar[r]);
            }
        }
    }

    void reverse(vector<long>& ar) {
        for (int i = 0; i < ar.size(); ++i) {
            int r = ar.size() - 1 - i;
            if (r > i) {
                swap(ar[i], ar[r]);
            }
        }
    }

    long pow(long base, long exp, long MOD) {
        base %= MOD;
        long ret = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }

    void initIO(FILE* in, FILE* out) {
        this->in = in;
        this->out = out;
    }

    void initIO(const char* inputFile, const char* outputFile) {
        in = fopen(inputFile, "r");
        out = fopen(outputFile, "w");
    }

    int scan() {
        if (index >= total) {
            index = 0;
            total = fread(buf, 1, sizeof(buf), in);
            if (total <= 0)
                return -1;
        }
        return buf[index++];
    }

    string next() {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        string ret;
        for (; c > 32; c = scan())
            ret += (char)c;
        return ret;
    }

    int nextInt() {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    long nextLong() {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    void print(const string& a) {
        fwrite(a.c_str(), 1, a.size(), out);
    }

    void printsp(const string& a) {
        print(a);
        print(" ");
    }

    void println() {
        print("\n");
    }

    void println(const string& a) {
        print(a);
        println();
    }

    void flush() {
        fflush(out);
    }

private:
    FILE* in;
    FILE* out;
    char buf[1 << 20];
    int index = 0;
    int total = 0;
};

class Solver {
public:
    Helper hp;
    const int MAXN = 1000006;
    const long MOD = 1e9 + 7;

    Solver() : hp(MOD, MAXN) {
        hp.initIO(stdin, stdout);
    }

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
        hp.flush();
    }

    bool TESTCASES = false;

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
            hp.println(to_string(straight[(int)K] + 1));
        } else {
            K -= straight.size();
            hp.println(to_string(cycle[(int)(K % cycle.size())] + 1));
        }
    }
};

void run() {
    try {
        Solver().solve();
        exit(0);
    } catch (exception& e) {
        e.what();
        exit(1);
    }
}

int main() {
    run();
    return 0;
}
// End of Code
