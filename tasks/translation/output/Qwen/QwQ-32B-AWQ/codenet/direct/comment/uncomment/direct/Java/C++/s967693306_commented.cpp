#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX / 2;
const long long MOD = 1e9 + 7;
const int SIZE = 1e6;

long long fac[SIZE];
long long inv[SIZE];
long long finv[SIZE];

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, BUFFER_SIZE, stdin);
        return buflen > 0;
    }

public:
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
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
        if (!hasNext()) throw runtime_error("No input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw runtime_error("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + (b - '0');
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(n);
    }

    double nextDouble() {
        return stod(next());
    }

private:
    int readByte() {
        if (!hasNextByte()) return -1;
        return buffer[ptr++];
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
};

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long inv(long long a) {
    return pow(a, MOD - 2);
}

long long pow(long long a, long long r) {
    long long sum = 1;
    while (r > 0) {
        if (r & 1) {
            sum *= a;
            sum %= MOD;
        }
        a = a * a % MOD;
        r >>= 1;
    }
    return sum;
}

long long modFact(long long n) {
    if (n == 0) return 1;
    return n * modFact(n - 1) % MOD;
}

long long fact(long long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void initCOMB() {
    fac[0] = 1;
    fac[1] = 1;
    inv[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long modComb(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}

long long comb(long long n, long long r) {
    long long num = 1;
    for (long long i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

bool isPrime(long long a) {
    if (a <= 1) return false;
    for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

string nextPermutation(string s) {
    vector<char> list(s.begin(), s.end());
    int pivotPos = -1;
    char pivot = 0;
    for (int i = list.size() - 2; i >= 0; i--) {
        if (list[i] < list[i + 1]) {
            pivotPos = i;
            pivot = list[i];
            break;
        }
    }
    if (pivotPos == -1) return "";
    int L = pivotPos + 1;
    int R = list.size() - 1;
    int minPos = -1;
    char minChar = CHAR_MAX;
    for (int i = R; i >= L; i--) {
        if (pivot < list[i]) {
            if (list[i] < minChar) {
                minChar = list[i];
                minPos = i;
            }
        }
    }
    swap(list[pivotPos], list[minPos]);
    sort(list.begin() + L, list.begin() + R + 1);
    return string(list.begin(), list.end());
}

bool nextPermutation(long long a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            int swapIndex = find(a, a[i - 1], i, n - 1);
            swap(a[swapIndex], a[i - 1]);
            sort(a + i, a + n);
            return true;
        }
    }
    return false;
}

int find(long long a[], long long dest, int s, int e) {
    if (s == e) return s;
    int m = (s + e + 1) / 2;
    if (a[m] <= dest) return find(a, dest, s, m - 1);
    else return find(a, dest, m, e);
}

void elimination(vector<vector<int>>& a, vector<int>& b) {
    int n = a.size();
    double f;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            f = -a[i][k] / static_cast<double>(a[k][k]);
            for (int j = k + 1; j < n; j++) {
                a[i][j] += f * a[k][j];
            }
            b[i] += f * b[k];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                b[i] -= a[i][j] * b[j];
            }
            b[i] = b[i] / a[i][i];
        }
    }
}

void solve() {
    FastScanner sc;
    int n = sc.nextInt();
    int m = sc.nextInt();
    map<int, int> mp;

    for (int i = 0; i < m; i++) {
        int s = sc.nextInt();
        int c = sc.nextInt();
        if (mp.count(s)) {
            if (mp[s] != c) {
                cout << -1 << endl;
                exit(0);
            }
        }
        mp[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        string s = to_string(i);
        bool flag = true;
        if (s.length() < n) continue;
        for (int j = 0; j < n; j++) {
            int currentDigit = s[j] - '0';
            int pos = j + 1;
            if (mp.count(pos)) {
                if (mp[pos] != currentDigit) {
                    flag = false;
                    break;
                }
            } else {
                if (currentDigit != 0) {
                    if (j == 0 && currentDigit == 1) continue;
                    else {
                        flag = false;
                        break;
                    }
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

int main() {
    solve();
    return 0;
}
// End of Code
