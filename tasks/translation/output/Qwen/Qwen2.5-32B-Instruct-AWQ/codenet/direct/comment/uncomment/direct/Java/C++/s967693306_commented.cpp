#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

const long long INF = LLONG_MAX / 2;
const int MOD = 1'000'000'007;
const int SIZE = 1'000'000;

long long fac[SIZE];
long long inv[SIZE];
long long finv[SIZE];

class FastScanner {
private:
    istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(buffer, sizeof(buffer));
        buflen = in.gcount();
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

public:
    FastScanner(istream& input = cin) : in(input) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more tokens");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.push_back(static_cast<char>(b));
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) throw runtime_error("No more tokens");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of range");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return stod(next());
    }
};

class Main {
public:
    void solve() {
        FastScanner sc;
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

    long long gcd(long long a, long long b) { // return aとbの最大公約数
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { // return aとbの最小公倍数
        return a * b / gcd(a, b);
    }

    long long inv(long long a) { // return aの逆元 (mod MOD)
        return pow(a, MOD - 2);
    }

    long long pow(long long a, long long r) { // return a^r (mod MOD)
        long long sum = 1;
        while (r > 0) {
            if ((r & 1) == 1) { // 2進数表記で末尾1の時
                sum *= a;
                sum %= MOD;
            }
            a *= a;
            a %= MOD;
            r >>= 1;
        }
        return sum;
    }

    long long modFact(long long n) { // retur n! (mod MOD)
        if (n == 0) return 1;
        return n * modFact(n - 1) % MOD;
    }

    long long fact(long long n) { // return n!
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

    long long modComb(int n, int r) { // return nCr (先にinitCOMB()必要)
        if (n < r || n < 0 || r < 0) return 0;
        return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
    }

    long long comb(long long n, long long r) { // return nCr
        long long num = 1;
        for (long long i = 1; i <= r; i++) {
            num = num * (n - i + 1) / i;
        }
        return num;
    }

    bool isPrime(long long a) { // aの素数判定
        if (a <= 1) return false;
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) return false;
        }
        return true;
    }

    string nextPermutation(string s) { // return sの次の順列
        vector<char> list;
        for (int i = 0; i < s.length(); i++) list.push_back(s[i]);

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
        char min = CHAR_MAX;
        for (int i = R; i >= L; i--) {
            if (pivot < list[i]) {
                if (list[i] < min) {
                    min = list[i];
                    minPos = i;
                }
            }
        }

        swap(list[pivotPos], list[minPos]);
        sort(list.begin() + L, list.begin() + R + 1);

        string result(list.begin(), list.end());
        return result;
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

    int find(long long dest, const vector<long long>& a, int s, int e) {
        if (s == e) return s;
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
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
                b[i] /= a[i][i];
            }
        }
    }
};

int main() {
    Main().solve();
    return 0;
} // End of Code
