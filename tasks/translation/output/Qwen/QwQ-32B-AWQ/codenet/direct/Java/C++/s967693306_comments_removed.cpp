#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct Pair {
    long a, b;
    Pair(long i, long j) : a(i), b(j) {}
    bool operator<(const Pair& p) const {
        return b < p.b;
    }
};

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = cin.read(buffer, BUFFER_SIZE).gcount();
        if (buflen <= 0) return false;
        return true;
    }

    int readByte() {
        if (hasNextByte()) return static_cast<unsigned char>(buffer[ptr++]);
        else return -1;
    }

    bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

public:
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw invalid_argument("No more tokens");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
    }

    long long nextLong() {
        if (!hasNext()) throw invalid_argument("No more tokens");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw invalid_argument("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw invalid_argument("Invalid number format");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw invalid_argument("Integer overflow");
        return static_cast<int>(n);
    }

    double nextDouble() {
        return stod(next());
    }
};

struct Main {
    static constexpr long INF = LLONG_MAX / 2;
    static constexpr int MOD = 1'000'000'007;
    static constexpr int SIZE = 1'000'000;
    vector<long> fac;
    vector<long> inv;
    vector<long> finv;
    FastScanner sc;

    Main() : fac(SIZE), inv(SIZE), finv(SIZE) {}

    void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        unordered_map<int, int> map;

        for (int i = 0; i < m; i++) {
            int s = sc.nextInt();
            int c = sc.nextInt();
            if (map.find(s) != map.end() && map[s] != c) {
                cout << -1 << endl;
                exit(0);
            }
            map[s] = c;
        }

        for (int i = 0; i < 1000; i++) {
            string s = to_string(i);
            bool flag = true;
            if (s.length() < n) continue;
            for (int j = 0; j < n; j++) {
                int digit = s[j] - '0';
                int pos = j + 1;
                bool problem = false;
                if (map.find(pos) != map.end()) {
                    if (digit != map[pos]) problem = true;
                } else {
                    if (digit != 0) problem = true;
                }
                if (problem) {
                    if (!map.count(pos) && j == 0 && digit == 1) {
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && s.length() == n) {
                cout << s << endl;
                exit(0);
            }
        }
        cout << -1 << endl;
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    long inv(long a) {
        return pow(a, MOD - 2);
    }

    long pow(long a, long r) {
        long res = 1;
        while (r > 0) {
            if (r & 1) res = res * a % MOD;
            a = a * a % MOD;
            r >>= 1;
        }
        return res;
    }

    long modFact(long n) {
        return n == 0 ? 1 : n * modFact(n - 1) % MOD;
    }

    long fact(long n) {
        return n == 0 ? 1 : n * fact(n - 1);
    }

    void initCOMB() {
        fac[0] = 1;
        fac[1] = 1;
        inv[1] = 1;
        finv[0] = 1;
        finv[1] = 1;
        for (int i = 2; i < SIZE; i++) {
            fac[i] = fac[i-1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i-1] * inv[i] % MOD;
        }
    }

    long modComb(int n, int r) {
        if (n < r || n < 0 || r < 0) return 0;
        return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
    }

    long comb(long n, long r) {
        long res = 1;
        for (long i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    bool isPrime(long a) {
        if (a <= 1) return false;
        for (long i = 2; i * i <= a; i++) {
            if (a % i == 0) return false;
        }
        return true;
    }

    string nextPermutation(string s) {
        vector<char> list(s.begin(), s.end());
        int pivotPos = -1;
        char pivot = 0;
        for (int i = list.size() - 2; i >= 0; i--) {
            if (list[i] < list[i+1]) {
                pivotPos = i;
                pivot = list[i];
                break;
            }
        }
        if (pivotPos == -1 && pivot == 0) return "";
        int L = pivotPos + 1;
        int R = list.size() - 1;
        int minPos = -1;
        char minChar = CHAR_MAX;
        for (int i = R; i >= L; i--) {
            if (pivot < list[i] && list[i] < minChar) {
                minChar = list[i];
                minPos = i;
            }
        }
        swap(list[pivotPos], list[minPos]);
        sort(list.begin() + L, list.end());
        return string(list.begin(), list.end());
    }

    bool nextPermutation(long* a, int len) {
        for (int i = len - 1; i > 0; i--) {
            if (a[i-1] < a[i]) {
                long dest = a[i-1];
                int swapIndex = find(dest, a, i, len - 1);
                swap(a[i-1], a[swapIndex]);
                sort(a + i, a + len);
                return true;
            }
        }
        return false;
    }

    int find(long dest, long* a, int s, int e) {
        if (s == e) return s;
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }

    void elimination(int a[][100], int b[], int n) {
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                long f = -a[i][k] / static_cast<long>(a[k][k]);
                for (int j = k + 1; j < n; j++) {
                    a[i][j] += f * a[k][j];
                }
                b[i] += f * b[k];
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    b[i] -= a[i][j] * b[j];
                }
                b[i] /= a[i][i];
            }
        }
    }
};

int main() {
    Main mainObj;
    mainObj.solve();
    return 0;
}
// End of Code
