#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;

class FastScanner {
private:
    istream& in;
    vector<char> buffer;
    size_t ptr = 0, buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buffer.clear();
        buflen = 0;
        buffer.resize(1024);
        in.read(buffer.data(), 1024);
        buflen = in.gcount();
        return buflen > 0;
    }
    int readByte() {
        return hasNextByte() ? static_cast<unsigned char>(buffer[ptr++]) : -1;
    }
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
public:
    FastScanner(istream& in_ = cin) : in(in_), buffer(1024), ptr(0), buflen(0) {}
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
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
        long long l = nextLong();
        if (l < INT_MIN || l > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(l);
    }
    double nextDouble() { return stod(next()); }
    char nextChar() {
        if (!hasNext()) throw runtime_error("No element");
        int b = readByte();
        if (!isPrintableChar(b)) throw runtime_error("Invalid character");
        return static_cast<char>(b);
    }
};

struct UnionFind {
    vector<int> Parent;
    UnionFind(int n) : Parent(n, -1) {}
    int root(int a) { return Parent[a] < 0 ? a : (Parent[a] = root(Parent[a])); }
    int size(int a) { return -Parent[root(a)]; }
    bool connect(int a, int b) {
        a = root(a); b = root(b);
        if (a == b) return false;
        if (size(a) < size(b)) swap(a, b);
        Parent[a] += Parent[b];
        Parent[b] = a;
        return true;
    }
};

struct Main {
    static FastScanner scan;
    static const long long mod = 1000000007;
    static const double eps = 1.0e-14;
    static const int big = INT_MAX;
    static const double PI = 3.14159265358979323846262338327950288;
    
    static long long modlcm(long long a, long long b) {
        return a * b * modint(gcd(a, b), mod);
    }
    static long long gcd(long long a, long long b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
    static long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    static int max(int a, int b) { return a > b ? a : b; }
    static int min(int a, int b) { return a < b ? a : b; }
    static long long lmax(long long a, long long b) { return a > b ? a : b; }
    static long long lmin(long long a, long long b) { return a < b ? a : b; }
    static long long factorial(int i) { return i == 1 ? 1LL : i * factorial(i-1); }
    static int lower_bound(const vector<int>& a, int key) {
        int l = 0, r = a.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            (a[m] < key ? l : r) = m;
        }
        return l;
    }
    static int upper_bound(const vector<int>& a, int key) {
        int l = 0, r = a.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            (a[m] <= key ? l : r) = m;
        }
        return l;
    }
    static bool isPrime(long long n) {
        if (n == 2) return true;
        if (n < 2 || n % 2 == 0) return false;
        for (long long i = 3; i*i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }
    static int upper_division(int a, int b) {
        return a % b == 0 ? a / b : a / b + 1;
    }
    static long long lupper_division(long long a, long long b) {
        return a % b == 0 ? a / b : a / b + 1;
    }
    static vector<int> setArray(int n) {
        vector<int> arr(n);
        for (int& x : arr) x = scan.nextInt();
        return arr;
    }
    static vector<long long> lsetArray(int n) {
        vector<long long> arr(n);
        for (long long& x : arr) x = scan.nextLong();
        return arr;
    }
    static string reverse(const string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev;
    }
    static void printArray(const vector<int>& arr) {
        for (size_t i = 0; i < arr.size(); ++i)
            cout << arr[i] << (i == arr.size()-1 ? "\n" : " ");
    }
    static vector<vector<int>> doublesort(const vector<vector<int>>& a) {
        vector<vector<int>> res(a);
        sort(res.begin(), res.end(), [](const auto& x, const auto& y) {
            return x[0] < y[0];
        });
        return res;
    }
    static vector<vector<long long>> ldoublesort(const vector<vector<long long>>& a) {
        vector<vector<long long>> res(a);
        sort(res.begin(), res.end(), [](const auto& x, const auto& y) {
            return x[0] < y[0];
        });
        return res;
    }
    static long long modpow(long long x, long long n, long long mo) {
        long long res = 1;
        while (n) {
            if (n & 1) res = res * x % mo;
            x = x * x % mo;
            n >>= 1;
        }
        return res;
    }
    static long long modint(long long a, long long m) {
        long long b = m, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= m;
        return u < 0 ? u + m : u;
    }
    static void warshall_floyd(vector<vector<int>>& v, int n) {
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
    }
};

FastScanner Main::scan;

int main() {
    string s = Main::scan.next();
    cout << (s.size() >=6 && s[2]==s[3] && s[4]==s[5] ? "Yes" : "No") << endl;
    return 0;
} // End of Code
