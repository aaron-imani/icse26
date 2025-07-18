#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Helper {
public:
    long MOD;
    int MAXN;
    std::vector<int> primes;
    std::vector<long> sieve;
    std::vector<long> factorial;
    std::ifstream in;
    std::ofstream out;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn) {
        setSieve();
        setFactorial();
    }

    void setSieve() {
        primes.clear();
        sieve.resize(MAXN, 0);
        for (int i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.push_back(i);
                for (int j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
    }

    void setFactorial() {
        factorial.resize(MAXN, 0);
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) factorial[i] = factorial[i - 1] * i % MOD;
    }

    long getFactorial(int n) {
        return factorial[n];
    }

    long ncr(int n, int r) {
        if (r > n) return 0;
        long numerator = factorial[n];
        long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * pow(denominator, MOD - 2, MOD) % MOD;
    }

    std::vector<long> getLongArray(int size) {
        std::vector<long> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    std::vector<int> getIntArray(int size) {
        std::vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    std::vector<string> getStringArray(int size) {
        std::vector<string> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = next();
        return ar;
    }

    string joinElements(std::vector<long> ar) {
        std::stringstream ss;
        for (long itr : ar) ss << itr << " ";
        return ss.str();
    }

    string joinElements(std::vector<int> ar) {
        std::stringstream ss;
        for (int itr : ar) ss << itr << " ";
        return ss.str();
    }

    string joinElements(std::vector<string> ar) {
        std::stringstream ss;
        for (string itr : ar) ss << itr << " ";
        return ss.str();
    }

    string joinElements(std::vector<void*> ar) {
        std::stringstream ss;
        for (void* itr : ar) ss << itr << " ";
        return ss.str();
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long max(std::vector<long> ar) {
        long ret = ar[0];
        for (long itr : ar) ret = std::max(ret, itr);
        return ret;
    }

    int max(std::vector<int> ar) {
        int ret = ar[0];
        for (int itr : ar) ret = std::max(ret, itr);
        return ret;
    }

    long min(std::vector<long> ar) {
        long ret = ar[0];
        for (long itr : ar) ret = std::min(ret, itr);
        return ret;
    }

    int min(std::vector<int> ar) {
        int ret = ar[0];
        for (int itr : ar) ret = std::min(ret, itr);
        return ret;
    }

    long sum(std::vector<long> ar) {
        long sum = 0;
        for (long itr : ar) sum += itr;
        return sum;
    }

    long sum(std::vector<int> ar) {
        long sum = 0;
        for (int itr : ar) sum += itr;
        return sum;
    }

    void shuffle(std::vector<int>& ar) {
        std::srand(std::time(0));
        std::random_shuffle(ar.begin(), ar.end());
    }

    void shuffle(std::vector<long>& ar) {
        std::srand(std::time(0));
        std::random_shuffle(ar.begin(), ar.end());
    }

    void reverse(std::vector<int>& ar) {
        std::reverse(ar.begin(), ar.end());
    }

    void reverse(std::vector<long>& ar) {
        std::reverse(ar.begin(), ar.end());
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

    void initIO(std::istream& is, std::ostream& os) {
        in = is;
        out = os;
    }

    void initIO(const string& inputFile, const string& outputFile) {
        in.open(inputFile);
        out.open(outputFile);
    }

    string next() {
        string str;
        in >> str;
        return str;
    }

    int nextInt() {
        int val;
        in >> val;
        return val;
    }

    long nextLong() {
        long val;
        in >> val;
        return val;
    }

    void print(const string& a) {
        out << a;
    }

    void printsp(const string& a) {
        print(a);
        print(" ");
    }

    void println() {
        out << "\n";
    }

    void println(const string& a) {
        print(a);
        println();
    }

    void flush() {
        out.flush();
    }
};

class Solver {
public:
    Helper hp;
    const int MAXN = 1000006;
    const long MOD = 1000000007;
    bool TESTCASES = false;

    Solver() : hp(MOD, MAXN) {
        hp.initIO(cin, cout);
    }

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
        hp.flush();
    }

    void solve(int tc) {
        int N = hp.nextInt();
        long K = hp.nextLong();
        std::vector<int> A = hp.getIntArray(N);

        std::vector<int> straight, cycle;
        std::vector<bool> vis(N, false);
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
};

class Main {
public:
    void run() {
        try {
            Solver().solve();
            exit(0);
        } catch (const std::exception& e) {
            e.what();
            exit(1);
        }
    }

    static void main() {
        Main().run();
    }
};

int main() {
    Main::main();
    return 0;
} // End of Code
