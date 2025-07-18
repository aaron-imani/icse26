#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
const long long MOD = 1e9 + 7;

class Helper {
private:
    static char buf[1 << 20];
    static int index;
    static int total;
public:
    static int sieve[MAXN];
    static vector<int> primes;
    static long long factorial[MAXN];
    
    Helper() {}
    
    void initIO() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        index = 0;
        total = 0;
    }
    
    void setSieve() {
        primes.clear();
        fill(sieve, sieve + MAXN, 0);
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
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = (factorial[i-1] * i) % MOD;
        }
    }
    
    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }
    
    int nextInt() {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        bool neg = c == '-';
        if (c == '-' || c == '+') c = scan();
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
        if (c == '-' || c == '+') c = scan();
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = val * 10 + (c - '0');
        }
        return neg ? -val : val;
    }
    
    int scan() {
        if (index >= total) {
            index = 0;
            total = fread(buf, 1, sizeof(buf), stdin);
            if (total <= 0) return -1;
        }
        return buf[index++];
    }
    
    void println(int a) { cout << a << '\n'; }
    void println(long long a) { cout << a << '\n'; }
    void flush() { cout << flush; }
};

char Helper::buf[1 << 20];
int Helper::index = 0;
int Helper::total = 0;
int Helper::sieve[MAXN];
vector<int> Helper::primes;
long long Helper::factorial[MAXN];

class Solver {
public:
    Helper hp;
    bool TESTCASES = false;
    
    Solver() { hp.initIO(); }
    
    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
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
    return 0; // End of Code
}
