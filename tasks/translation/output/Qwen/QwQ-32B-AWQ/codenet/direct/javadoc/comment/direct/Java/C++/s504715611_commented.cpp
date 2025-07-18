#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const long long mod = 1000000007;
const double eps = 1.0e-14;
const int big = INT_MAX;
const double PI = 3.14159265358979323846262338327950288;

class FastScanner {
private:
    FILE* in;
    char buffer[1024];
    size_t ptr = 0;
    size_t buflen = 0;
public:
    FastScanner() : in(stdin) {}
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, sizeof(buffer), in);
        return buflen > 0;
    }
    int readByte() {
        if (!hasNextByte()) return -1;
        return buffer[ptr++];
    }
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += (char)b;
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
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(n);
    }
    double nextDouble() { return stod(next()); }
    char nextChar() {
        if (!hasNext()) throw runtime_error("No element");
        return (char)readByte();
    }
};

FastScanner scan;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) : parent(n, -1) {}
    int root(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = root(parent[a]);
    }
    int size(int a) {
        return -parent[root(a)];
    }
    bool connect(int a, int b) {
        int rootA = root(a);
        int rootB = root(b);
        if (rootA == rootB) return false;
        if (size(rootA) < size(rootB)) swap(rootA, rootB);
        parent[rootA] += parent[rootB];
        parent[rootB] = rootA;
        return true;
    }
};

long long modlcm(long long a, long long b) {
    return a * b * modint(gcd(a, b), mod) % mod;
}

long long gcd(long long a, long long b) {
    return b != 0 ? gcd(b, a % b) : a;
}

long long modint(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b != 0) {
        long long t = a / b;
        a -= t * b;
        long long x = a; a = b; b = x;
        u -= t * v;
        x = u; u = v; v = x;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
long long lmax(long long a, long long b) { return max(a, b); }
long long lmin(long long a, long long b) { return min(a, b); }
long long factorial(int i) { return i == 1 ? 1 : i * factorial(i - 1); }

int lower_bound(const vector<int>& a, int key) {
    int right = a.size(), left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) left = mid;
        else right = mid;
    }
    return left;
}

int upper_bound(const vector<int>& a, int key) {
    int right = a.size(), left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] <= key) left = mid;
        else right = mid;
    }
    return left;
}

bool isPrime(long long n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    long long d = sqrt(n);
    for (long long i = 3; i <= d; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int upper_division(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}

long long lupper_division(long long a, long long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

vector<int> setArray(int a) {
    vector<int> b(a);
    for (int i = 0; i < a; ++i) {
        b[i] = scan.nextInt();
    }
    return b;
}

vector<long long> lsetArray(int a) {
    vector<long long> b(a);
    for (int i = 0; i < a; ++i) {
        b[i] = scan.nextLong();
    }
    return b;
}

string reverseString(const string& str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}

void printArray(const vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; i++) {
        cout << que[i] << ' ';
    }
    cout << que.back() << endl;
}

vector<vector<int>> doublesort(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    });
    return a;
}

vector<vector<long long>> ldoublesort(vector<vector<long long>>& a) {
    sort(a.begin(), a.end(), [](const vector<long long>& x, const vector<long long>& y) {
        return x[0] < y[0];
    });
    return a;
}

long long modpow(long long x, long long n, long long mo) {
    long long sum = 1;
    while (n > 0) {
        if (n & 1) {
            sum = sum * x % mo;
        }
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

vector<int> revint(const vector<int>& ch) {
    vector<int> ret(ch.rbegin(), ch.rend());
    return ret;
}

void warshall_floyd(vector<vector<int>>& v, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

int main() {
    string str = scan.next();
    if (str.length() >= 6 && str[2] == str[3] && str[4] == str[5]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
} // End of Code
