#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX / 2;
const int MOD = 1000000007;
const int SIZE = 1000000;

class Main {
public:
    vector<long long> fac, inv, finv;
    istream& sc = cin;

    Main() : fac(SIZE), inv(SIZE), finv(SIZE) {}

    void solve() {
        int n, m;
        sc >> n >> m;
        map<int, int> map;

        for (int i = 0; i < m; i++) {
            int s, c;
            sc >> s >> c;
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
                if ((map.find(j + 1) != map.end() && map[j + 1] != s[j] - '0') || (map.find(j + 1) == map.end() && s[j] - '0' != 0)) {
                    if (map.find(j + 1) == map.end() && j == 0 && s[j] - '0' == 1) {
                        continue;
                    }
                    flag = false;
                    break;
                }
            }
            if (flag && s.length() == n) {
                cout << s << endl;
                exit(0);
            }
        }

        cout << -1 << endl;
    }

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
            a *= a;
            a %= MOD;
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
        fac[0] = fac[1] = 1;
        inv[1] = 1;
        finv[0] = finv[1] = 1;
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
        for (int i = 2; i * i <= a; i++) {
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

        if (pivotPos == -1 && pivot == 0) return "";

        int L = pivotPos + 1;
        int R = list.size() - 1;
        int minPos = -1;
        char minVal = CHAR_MAX;
        for (int i = R; i >= L; i--) {
            if (pivot < list[i]) {
                if (list[i] < minVal) {
                    minVal = list[i];
                    minPos = i;
                }
            }
        }

        swap(list[pivotPos], list[minPos]);
        sort(list.begin() + L, list.begin() + R + 1);

        return string(list.begin(), list.end());
    }

    bool nextPermutation(vector<long long>& a) {
        for (int i = a.size() - 1; i > 0; i--) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.size() - 1);
                swap(a[swapIndex], a[i - 1]);
                sort(a.begin() + i, a.end());
                return true;
            }
        }
        return false;
    }

    int find(long long dest, vector<long long>& a, int s, int e) {
        if (s == e) return s;
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }

    void elimination(vector<vector<int>>& a, vector<int>& b) {
        int n = a.size();
        double f;
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                f = -a[i][k] / (double)a[k][k];
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
};

int main() {
    Main mainInstance;
    mainInstance.solve();
    return 0;
}
// End of Code
