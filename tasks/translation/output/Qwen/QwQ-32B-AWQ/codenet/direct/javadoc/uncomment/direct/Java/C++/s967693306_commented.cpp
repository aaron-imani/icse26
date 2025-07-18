#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class FastScanner {
private:
    istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
public:
    FastScanner() : in(cin) {}

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = in.read(buffer, sizeof(buffer));
        if (buflen <= 0) return false;
        return true;
    }

    int readByte() {
        if (hasNextByte()) return static_cast<int>(buffer[ptr++]);
        else return -1;
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ++ptr;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
    }

    long long nextLong() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw runtime_error("Invalid number format");
        while (true) {
            if (b >= '0' && b <= '9') {
                n = n * 10 + (b - '0');
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw runtime_error("Integer overflow");
        return static_cast<int>(n);
    }

    double nextDouble() {
        return stod(next());
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
};

class Main {
private:
    const long long INF = numeric_limits<long long>::max() / 2;
    const int MOD = 1000000007;
    const int SIZE = 1000000;
    vector<long long> fac;
    vector<long long> inv;
    vector<long long> finv;
    FastScanner sc;

public:
    Main() : sc(), fac(SIZE, 0), inv(SIZE, 0), finv(SIZE, 0) {}

    void solve();

    long long gcd(long long a, long long b) const {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) const {
        return a * b / gcd(a, b);
    }

    long long invMod(long long a) const {
        return powMod(a, MOD - 2);
    }

    long long powMod(long long a, long long r) const {
        long long res = 1;
        while (r > 0) {
            if (r & 1) res = res * a % MOD;
            a = a * a % MOD;
            r >>= 1;
        }
        return res;
    }

    long long modFact(long long n) const {
        return n == 0 ? 1 : n * modFact(n - 1) % MOD;
    }

    long long fact(long long n) const {
        return n == 0 ? 1 : n * fact(n - 1);
    }

    void initCOMB() {
        fac[0] = 1;
        fac[1] = 1;
        inv[1] = 1;
        finv[0] = 1;
        finv[1] = 1;
        for (int i = 2; i < SIZE; ++i) {
            fac[i] = (fac[i-1] * i) % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = (finv[i-1] * inv[i]) % MOD;
        }
    }

    long long modComb(int n, int r) const {
        if (n < r || n < 0 || r < 0) return 0;
        return (fac[n] * finv[r] % MOD) * finv[n - r] % MOD;
    }

    long long comb(long long n, long long r) const {
        long long num = 1;
        for (long long i = 1; i <= r; ++i) {
            num = num * (n - i + 1) / i;
        }
        return num;
    }

    bool isPrime(long long a) const {
        if (a <= 1) return false;
        for (long long i = 2; i * i <= a; ++i) {
            if (a % i == 0) return false;
        }
        return true;
    }

    string nextPermutation(string s) {
        vector<char> list(s.begin(), s.end());
        int pivotPos = -1;
        char pivot = 0;
        for (int i = list.size() - 2; i >= 0; --i) {
            if (list[i] < list[i+1]) {
                pivotPos = i;
                pivot = list[i];
                break;
            }
        }
        if (pivotPos == -1) return "";
        int L = pivotPos + 1;
        int R = list.size() - 1;
        int minPos = -1;
        char minChar = static_cast<char>(-1);
        for (int i = R; i >= L; --i) {
            if (list[i] > pivot) {
                if (list[i] < minChar || minChar == static_cast<char>(-1)) {
                    minChar = list[i];
                    minPos = i;
                }
            }
        }
        swap(list[pivotPos], list[minPos]);
        sort(list.begin() + L, list.begin() + R + 1);
        return string(list.begin(), list.end());
    }

    bool nextPermutation(long long a[], int size) {
        for (int k = 0; k < size - 1; ++k) {
            for (int i = k + 1; i < size; ++i) {
                if (a[k] < a[i]) {
                    int swapIndex = find(a[k], a, i, size - 1);
                    swap(a[k], a[swapIndex]);
                    sort(a + k + 1, a + size);
                    return true;
                }
            }
        }
        return false;
    }

    int find(long long dest, long long a[], int s, int e) {
        if (s == e) return s;
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }

    void elimination(int a[][n], int b[], int n) {
        // Implementation not provided as per original code structure
    }
};

void Main::solve() {
    int n = sc.nextInt();
    int m = sc.nextInt();
    unordered_map<int, int> map;

    for (int i = 0; i < m; ++i) {
        int s = sc.nextInt();
        int c = sc.nextInt();
        if (map.find(s) != map.end() && map[s] != c) {
            cout << -1 << endl;
            exit(0);
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; ++i) {
        string s = to_string(i);
        if (s.length() < static_cast<size_t>(n)) continue;
        if (s.length() != static_cast<size_t>(n)) continue;
        bool flag = true;
        for (size_t j = 0; j < n; ++j) {
            int pos = j + 1;
            int required = map.count(pos) ? map[pos] : -1;
            int currentDigit = s[j] - '0';
            if (map.count(pos)) {
                if (currentDigit != required) {
                    flag = false;
                    break;
                }
            } else {
                if (currentDigit != 0) {
                    if (j == 0 && currentDigit == 1) {
                        // allowed
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) {
            cout << s << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}

int main() {
    Main m;
    m.solve();
    return 0;
}
// End of Code
