#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class FastScanner {
private:
    istream& in;
    vector<char> buffer;
    size_t ptr = 0;
    size_t buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        else {
            ptr = 0;
            buflen = in.readsome(buffer.data(), buffer.size());
            if (buflen <= 0) return false;
        }
        return true;
    }
    int readByte() {
        if (hasNextByte()) return static_cast<int>(buffer[ptr++]);
        else return -1;
    }
    bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
public:
    FastScanner() : in(cin), buffer(1024), ptr(0), buflen(0) {}
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += static_cast<char>(b);
            b = readByte();
        }
        return sb;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No element");
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
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(nl);
    }
    double nextDouble() {
        return stod(next());
    }
};

class Main {
public:
    static const long INF;
    static const int MOD;
    static const int SIZE;
    static long fac[];
    static long inv[];
    static long finv[];
    FastScanner sc;

    static long gcd(long a, long b);
    static long lcm(long a, long b);
    static long inv(long a);
    static long pow(long a, long r);
    static long modFact(long n);
    static long fact(long n);
    static void initCOMB();
    static long modComb(int n, int r);
    static long comb(long n, long r);
    static bool isPrime(long a);
    static string nextPermutation(string s);
    static bool nextPermutation(vector<long>& a);
    static int find(long dest, const vector<long>& a, int s, int e);
    static void elimination(int a[][], int b[]);

    void solve();
};

const long Main::INF = std::numeric_limits<long>::max() / 2;
const int Main::MOD = 1000000007;
const int Main::SIZE = 1000000;

long Main::fac[Main::SIZE];
long Main::inv[Main::SIZE];
long Main::finv[Main::SIZE];

long Main::gcd(long a, long b) {
    if (b == NaN) return a;
    return gcd(b, a % b);
}

long Main::lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long Main::inv(long a) {
    return pow(a, MOD - 2);
}

long Main::pow(long a, long r) {
    long res = 1;
    while (r > 0) {
        if (r & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        r >>= 1;
    }
    return res;
}

long Main::modFact(long n) {
    if (n == 0) return 1;
    return n * modFact(n - 1) % MOD;
}

long Main::fact(long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void Main::initCOMB() {
    fac[0] = 1;
    fac[1] = 1;
    inv[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    for (int i = 2; i < Main::SIZE; i++) {
        fac[i] = (fac[i - 1] * i) % Main::MOD;
        inv[i] = Main::MOD - inv[Main::MOD % i] * (Main::MOD / i) % Main::MOD;
        finv[i] = (finv[i - 1] * inv[i]) % Main::MOD;
    }
}

long Main::modComb(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return (fac[n] * finv[r] % Main::MOD) * finv[n - r] % Main::MOD;
}

long Main::comb(long n, long r) {
    long num = 1;
    for (long i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

bool Main::isPrime(long a) {
    if (a <= 1) return false;
    for (long i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

string Main::nextPermutation(string s) {
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
    if (pivotPos == -1) return "";
    int minPos = -1;
    char min_char = (char)255;
    for (int i = pivotPos + 1; i < list.size(); i++) {
        if (list[i] > pivot && list[i] < min_char) {
            min_char = list[i];
            minPos = i;
        }
    }
    swap(list[pivotPos], list[minPos]);
    reverse(list.begin() + pivotPos + 1, list.end());
    return string(list.begin(), list.end());
}

bool Main::nextPermutation(vector<long>& a) {
    for (int i = a.size() - 1; i > 0; i--) {
        if (a[i-1] < a[i]) {
            int swapIndex = find(a[i-1], a, i, a.size()-1);
            swap(a[i-1], a[swapIndex]);
            sort(a.begin() + i, a.end());
            return true;
        }
    }
    return false;
}

int Main::find(long dest, const vector<long>& a, int s, int e) {
    if (s == e) return s;
    int m = (s + e + 1) / 2;
    return a[m] <= dest ? find(dest, a, s, m-1) : find(dest, a, m, e);
}

void Main::elimination(int a[][], int b[]) {
    // This part is omitted for brevity.
}

void Main::solve() {
    int n = sc.nextInt();
    int m = sc.nextInt();
    map<int, int> map_;
    for (int i = 0; i < m; i++) {
        int s = sc.nextInt();
        int c = sc.nextInt();
        if (map_.find(s) != map_.end() && map_[s] != c) {
            cout << -1 << endl;
            exit(0);
        }
        map_[s] = c;
    }
    for (int i = 0; i < 1000; i++) {
        string s = to_string(i);
        if (s.length() < n) continue;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            int pos = j + 1;
            auto it = map_.find(pos);
            if (it != map_.end()) {
                int required = it->second;
                int current = s[j] - '0';
                if (current != required) {
                    flag = false;
                    break;
                }
            } else {
                int current = s[j] - '0';
                if (j == 0 && current == 1) {
                } else if (current != 0) {
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

int main() {
    Main m;
    m.solve();
    return 0;
}
// End of Code
