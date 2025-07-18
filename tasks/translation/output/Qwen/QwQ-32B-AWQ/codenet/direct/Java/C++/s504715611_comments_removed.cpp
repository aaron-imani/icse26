#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const long mod = 1000000007;
const double eps = 1.0e-14;
const int big = INT_MAX;
const double PI = 3.14159265358979323846262338327950288;

class UnionFind {
public:
    vector<int> Parent;
    UnionFind(int n) : Parent(n, -1) {}
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    int size(int A) {
        return -Parent[root(A)];
    }
    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0, buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, BUFFER_SIZE, stdin);
        return buflen > 0;
    }
    int readByte() {
        return hasNextByte() ? static_cast<unsigned char>(buffer[ptr++]) : -1;
    }
public:
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
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
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Out of range");
        return static_cast<int>(nl);
    }
    double nextDouble() { return stod(next()); }
    char nextChar() {
        int b = readByte();
        if (b == -1) throw runtime_error("No more input");
        return static_cast<char>(b);
    }
};

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
long long lmax(long long a, long long b) { return max(a, b); }
long long lmin(long long a, long long b) { return min(a, b); }
long factorial(int i) { return i == 1 ? 1 : i * factorial(i - 1); }
long gcd(long a, long b) { return b > 0 ? gcd(b, a % b) : a; }
long lcm(long a, long b) { return a * b / gcd(a, b); }
long modlcm(long a, long b) { return a * b * modint(gcd(a, b), mod); }

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
    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int upper_division(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}

long long lupper_division(long long a, long long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

vector<int> setArray(FastScanner& scan, int a) {
    vector<int> b(a);
    for (int i = 0; i < a; ++i) b[i] = scan.nextInt();
    return b;
}

string reverse(const string& str) {
    int a = str.length();
    string ch_str = str;
    for (int i = 0; i < (a + 1)/2; ++i)
        swap(ch_str[i], ch_str[a - 1 - i]);
    return ch_str;
}

void printArray(const vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; ++i) cout << que[i] << " ";
    cout << que.back() << endl;
}

void doublesort(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    });
}

long long modpow(long long x, long long n, long long mo) {
    long long sum = 1;
    while (n > 0) {
        if (n % 2 == 1) sum = sum * x % mo;
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

vector<char> revch(const vector<char>& ch) {
    vector<char> ret(ch.size());
    for (int i = ch.size() - 1, j = 0; i >= 0; i--, j++)
        ret[j] = ch[i];
    return ret;
}

vector<int> revint(const vector<int>& ch) {
    vector<int> ret(ch.size());
    for (int i = ch.size() - 1, j = 0; i >= 0; i--, j++)
        ret[j] = ch[i];
    return ret;
}

void warshall_floyd(vector<vector<int>>& v, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

long long modint(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b != 0) {
        long long t = a / b;
        a -= t * b;
        long long x = a;
        a = b;
        b = x;
        u -= t * v;
        x = u;
        u = v;
        v = x;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    FastScanner scan;
    string str = scan.next();
    cout << (str.length() >=6 && str[2]==str[3] && str[4]==str[5] ? "Yes" : "No") << endl;
    return 0;
} // End of Code
