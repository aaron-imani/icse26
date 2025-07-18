#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1000006;

class Helper {
public:
    Helper(long long mod, int maxn) : MOD(mod), MAXN(maxn), rnd(time(nullptr)) {}

    vector<int> sieve;
    vector<int> primes;

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

    vector<long long> factorial;

    void setFactorial() {
        factorial.assign(MAXN, 0);
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = factorial[i - 1] * i % MOD;
        }
    }

    long long getFactorial(int n) {
        if (factorial.empty()) setFactorial();
        return factorial[n];
    }

    long long ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial.empty()) setFactorial();
        long long numerator = factorial[n];
        long long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * powMod(denominator, MOD - 2, MOD) % MOD;
    }

    vector<long long> getLongArray(int size) {
        vector<long long> ar(size);
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

    string joinElements(const vector<long long>& ar) {
        stringstream ss;
        for (auto itr : ar) ss << itr << " ";
        return ss.str();
    }

    string joinElements(const vector<int>& ar) {
        stringstream ss;
        for (auto itr : ar) ss << itr << " ";
        return ss.str();
    }

    string joinElements(const vector<string>& ar) {
        stringstream ss;
        for (auto itr : ar) ss << itr << " ";
        return ss.str();
    }

    string joinElements(const vector<void*>& ar) {
        stringstream ss;
        for (auto itr : ar) ss << itr << " ";
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
        for (auto itr : ar) ret = max(ret, itr);
        return ret;
    }

    int max(const vector<int>& ar) {
        int ret = ar[0];
        for (auto itr : ar) ret = max(ret, itr);
        return ret;
    }

    long long min(const vector<long long>& ar) {
        long long ret = ar[0];
        for (auto itr : ar) ret = min(ret, itr);
        return ret;
    }

    int min(const vector<int>& ar) {
        int ret = ar[0];
        for (auto itr : ar) ret = min(ret, itr);
        return ret;
    }

    long long sum(const vector<long long>& ar) {
        long long sum = 0;
        for (auto itr : ar) sum += itr;
        return sum;
    }

    long long sum(const vector<int>& ar) {
        long long sum = 0;
        for (auto itr : ar) sum += itr;
        return sum;
    }

    void shuffle(vector<int>& ar) {
        int r;
        for (int i = 0; i < ar.size(); ++i) {
            r = rand() % ar.size();
            if (r != i) swap(ar[i], ar[r]);
        }
    }

    void shuffle(vector<long long>& ar) {
        int r;
        for (int i = 0; i < ar.size(); ++i) {
            r = rand() % ar.size();
            if (r != i) swap(ar[i], ar[r]);
        }
    }

    void reverse(vector<int>& ar) {
        for (int i = 0; i < ar.size() / 2; ++i) {
            swap(ar[i], ar[ar.size() - 1 - i]);
        }
    }

    void reverse(vector<long long>& ar) {
        for (int i = 0; i < ar.size() / 2; ++i) {
            swap(ar[i], ar[ar.size() - 1 - i]);
        }
    }

    long long powMod(long long base, long long exp, long long MOD) {
        base %= MOD;
        long long ret = 1;
        while (exp > 0) {
            if (exp & 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }

private:
    long long MOD;
    int MAXN;
    unsigned int rnd;

    string next() {
        string str;
        cin >> str;
        return str;
    }

    int nextInt() {
        int num;
        cin >> num;
        return num;
    }

    long long nextLong() {
        long long num;
        cin >> num;
        return num;
    }
};

class Solver {
public:
    Solver() : hp(MOD, MAXN) {}

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
    }

    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A = hp.getIntArray(N);

        vector<int> straight, cycle;
        bool vis[N] = {false};
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
            cout << straight[K] + 1 << endl;
        } else {
            K -= straight.size();
            cout << cycle[K % cycle.size()] + 1 << endl;
        }
    }

private:
    Helper hp;
    const bool TESTCASES = false;
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
} // End of Code
