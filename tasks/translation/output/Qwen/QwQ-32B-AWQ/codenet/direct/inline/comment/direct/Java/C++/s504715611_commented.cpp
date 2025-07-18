#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <unistd.h>

using namespace std;

class UnionFind {
private:
    vector<int> Parent;
public:
    UnionFind(int n) : Parent(n, -1) {}
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    int size(int A) {
        return -Parent[root(A)];
    }
    bool connect(int A, int B) {
        int rootA = root(A), rootB = root(B);
        if (rootA == rootB) return false;
        if (size(rootA) < size(rootB)) swap(rootA, rootB);
        Parent[rootA] += Parent[rootB];
        Parent[rootB] = rootA;
        return true;
    }
};

class FastScanner {
private:
    static const int bufferSize = 1024;
    char buffer[bufferSize];
    int ptr = 0, buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = read(0, buffer, bufferSize);
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
            if ('0' <= b && b <= '9') n = n * 1指望(b - '0');
            else if (b == -1 || !isPrintableChar(b)) return minus ? -n : n;
            else throw runtime_error("Invalid number");
            b = readByte();
        }
    }
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(nl);
    }
    double nextDouble() { return stod(next()); }
    char nextchar() {
        int c = readByte();
        return c == -1 ? throw runtime_error("No character") : static_cast<char>(c);
    }
};

class Main {
public:
    static FastScanner scan;
    static const long long mod = 1e9 + 7;
    static const double eps = 1.0e-14;
    static const int big = numeric_limits<int>::max();
    static const double PI = 3.14159265358979323846262338327950288;

    static long long modlcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    static long long gcd(long a, long b) {
        return b > 0 ? gcd(b, a % b) : a;
    }

    static int max(int a, int b) { return a > b ? a : b; }
    static int min(int a, int b) { return a < b ? a : b; }
    static long long lmax(long long a, long long b) { return a > b ? a : b; }
    static long long lmin(long long a, long long b) { return a < b ? a : b; }
    static long long factorial(int i) {
        return i == 1 ? 1LL : static_cast<long long>(i) * factorial(i - 1);
    }

    static int lower_bound(int a[], int len, int key) {
        int right = len, left = 0;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (a[mid] < key) left = mid;
            else right = mid;
        }
        return left;
    }

    static int upper_bound(int a[], int len, int key) {
        int right = len, left = 0;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (a[mid] <= key) left = mid;
            else right = mid;
        }
        return left;
    }

    static bool isPrime(long long n) {
        if (n == 2) return true;
        if (n < 2 || n % 2 == 0) return false;
        long long d = sqrt(n);
        for (long long i = 3; i <= d; i += 2)
            if (n % i == 0) return false;
        return true;
    }

    static int upper_division(int a, int b) { return a % b == 0 ? a / b : a / b + 1; }
    static long long lupper_division(long long a, long long b) { return a % b == 0 ? a / b : a / b + 1; }

    static vector<int> setArray(int a) {
        vector<int> b(a);
        for (int i = 0; i < a; ++i) b[i] = scan.nextInt();
        return b;
    }

    static vector<long long> lsetArray(int a) {
        vector<long long> b(a);
        for (int i = 0; i < a; ++i) b[i] = scan.nextLong();
        return b;
    }

    static string reverse(string str) {
        reverse(str.begin(), str.end());
        return str;
    }

    static void printArray(const vector<int>& que) {
        for (size_t i = 0; i < que.size() - 1; ++i) cout << que[i] << ' ';
        cout << que.back() << endl;
    }

    static vector<vector<int>> doublesort(const vector<vector<int>>& a) {
        vector<vector<int>> sorted = a;
        sort(sorted.begin(), sorted.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0];
        });
        return sorted;
    }

    static vector<vector<long long>> ldoublesort(const vector<vector<long long>>& a) {
        vector<vector<long long>> sorted = a;
        sort(sorted.begin(), sorted.end(), [](const vector<long long>& x, const vector<long long>& y) {
            return x[0] < y[0];
        });
        return sorted;
    }

    static long long modpow(long long x, long long n, long long mo) {
        long long sum = 1;
        while (n > 0) {
            if (n & 1) sum = sum * x % mo;
            x = x * x % mo;
            n >>= 1;
        }
        return sum;
    }

    static vector<char> revch(const vector<char>& ch) {
        vector<char> ret(ch.rbegin(), ch.rend());
        return ret;
    }

    static vector<int> revint(const vector<int>& ch) {
        vector<int> ret(ch.rbegin(), ch.rend());
        return ret;
    }

    static void warshall_floyd(vector<vector<int>>& v, int n) {
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
    }

    static long long modint(long long a, long long m) {
        long long b = m, u = 1, v = 0;
        while (b != 0) {
            long long t = a / b;
            a -= t * b;
            long long x = a; a = b; b = x;
            u -= t * v;
            x = u; u = v; v = x;
        }
        u %= m;
        return u < 0 ? u + m : u;
    }
};

FastScanner Main::scan;

int main() {
    string str = Main::scan.next();
    cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << endl;
    return 0;
} // End of Code
