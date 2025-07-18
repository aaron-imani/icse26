#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

class Helper {
public:
    const long MOD;
    const int MAXN;
    default_random_engine rnd;

    Helper(long mod, int maxn) : MOD(mod), MAXN(maxn), rnd(chrono::system_clock::now().time_since_epoch().count()) {}

    static vector<int> sieve;
    static vector<int> primes;

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

    static vector<long> factorial;

    void setFactorial() {
        factorial.assign(MAXN, 0);
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
    }

    long getFactorial(int n) {
        if (factorial.empty()) {
            setFactorial();
        }
        return factorial[n];
    }

    long ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial.empty()) {
            setFactorial();
        }
        long numerator = factorial[n];
        long denominator = (factorial[r] * factorial[n - r]) % MOD;
        return (numerator * pow(denominator, MOD - 2, MOD)) % MOD;
    }

    vector<long> getLongArray(int size) {
        vector<long> ar(size);
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

    string joinElements(const vector<long>& ar) {
        stringstream ss;
        for (long itr : ar) {
            ss << itr << " ";
        }
        string s = ss.str();
        return s.substr(0, s.length() - 1);
    }

    string joinElements(const vector<int>& ar) {
        stringstream ss;
        for (int itr : ar) {
            ss << itr << " ";
        }
        string s = ss.str();
        return s.substr(0, s.length() - 1);
    }

    string joinElements(const vector<string>& ar) {
        stringstream ss;
        for (string itr : ar) {
            ss << itr << " ";
        }
        string s = ss.str();
        return s.substr(0, s.length() - 1);
    }

    string joinElements(const vector<stringstream>& ar) {
        stringstream ss;
        for (stringstream itr : ar) {
            ss << itr.str() << " ";
        }
        string s = ss.str();
        return s.substr(0, s.length() - 1);
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long max(const vector<long>& ar) {
        long ret = ar[0];
        for (long itr : ar) {
            ret = std::max(ret, itr);
        }
        return ret;
    }

    int max(const vector<int>& ar) {
        int ret = ar[0];
        for (int itr : ar) {
            ret = std::max(ret, itr);
        }
        return ret;
    }

    long min(const vector<long>& ar) {
        long ret = ar[0];
        for (long itr : ar) {
            ret = std::min(ret, itr);
        }
        return ret;
    }

    int min(const vector<int>& ar) {
        int ret = ar[0];
        for (int itr : ar) {
            ret = std::min(ret, itr);
        }
        return ret;
    }

    long sum(const vector<long>& ar) {
        long sum = 0;
        for (long itr : ar) {
            sum += itr;
        }
        return sum;
    }

    long sum(const vector<int>& ar) {
        long sum = 0;
        for (int itr : ar) {
            sum += itr;
        }
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
        for (int i = 0; i < ar.size() / 2; ++i) {
            swap(ar[i], ar[ar.size() - 1 - i]);
        }
    }

    void reverse(vector<long>& ar) {
        for (int i = 0; i < ar.size() / 2; ++i) {
            swap(ar[i], ar[ar.size() - 1 - i]);
        }
    }

    long pow(long base, long exp, long MOD) {
        base %= MOD;
        long ret = 1;
        while (exp > 0) {
            if (exp & 1) {
                ret = (ret * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ret;
    }

    istream* in;
    ostream* out;

    void initIO(istream& is, ostream& os) {
        in = &is;
        out = &os;
    }

    void initIO(const string& inputFile, const string& outputFile) {
        in = new ifstream(inputFile);
        out = new ofstream(outputFile);
    }

    int scan() {
        int c;
        if (!(*in >> c)) {
            return -1;
        }
        return c;
    }

    string next() {
        string s;
        *in >> s;
        return s;
    }

    int nextInt() {
        int val;
        *in >> val;
        return val;
    }

    long nextLong() {
        long val;
        *in >> val;
        return val;
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
};

vector<int> Helper::sieve;
vector<int> Helper::primes;
vector<long> Helper::factorial;

class Solver {
public:
    const Helper hp;
    const int MAXN = 1000006;
    const long MOD = 1e9 + 7;

    Solver() : hp(MOD, MAXN) {
        hp.initIO(cin, cout);
    }

    void solve() {
        try {
            int tc = TESTCASES ? hp.nextInt() : 1;
            for (int tce = 1; tce <= tc; ++tce) {
                solve(tce);
            }
            hp.flush();
        } catch (const exception& e) {
            cerr << e.what() << endl;
            exit(1);
        }
    }

    bool TESTCASES = false;

    void solve(int tc) {
        int i, j, k;

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
