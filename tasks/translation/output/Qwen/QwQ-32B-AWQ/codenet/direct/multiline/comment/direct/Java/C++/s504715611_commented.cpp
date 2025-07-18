#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <limits>
using namespace std;

const long mod = 1000000007;
const double eps = 1.0e-14;
const double PI = 3.14159265358979323846262338327950288;
const int big = numeric_limits<int>::max();

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
        int rootA = root(A);
        int rootB = root(B);
        if (rootA == rootB) return false;
        if (size(rootA) < size(rootB)) swap(rootA, rootB);
        Parent[rootA] += Parent[rootB];
        Parent[rootB] = rootA;
        return true;
    }
};

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    FILE *in;
    char buffer[BUFFER_SIZE];
    int ptr = 0;
    int buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, sizeof(char), BUFFER_SIZE, in);
        return buflen > 0;
    }
    int readByte() {
        if (hasNextByte()) return static_cast<unsigned char>(buffer[ptr++]);
        else return -1;
    }
public:
    FastScanner() : in(stdin) {}
    bool hasNext() {
        while (hasNextByte()) {
            char c = buffer[ptr];
            if (c == '\n' || c == ' ' || isspace(c)) {
                ptr++;
            } else {
                break;
            }
        }
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No token");
        string str;
        int b = readByte();
        while (isPrintableChar(b)) {
            str += static_cast<char>(b);
            b = readByte();
        }
        return str;
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
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(nl);
    }
    double nextDouble() { return stod(next()); }
    char nextChar() {
        if (!hasNext()) throw runtime_error("No character");
        int b = readByte();
        return static_cast<char>(b);
    }
private:
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
};

int lower_bound(int a[], int n, int key) {
    int right = n;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) left = mid;
        else right = mid;
    }
    return left;
}

int upper_bound(int a[], int n, int key) {
    int right = n;
    int left = 0;
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
    return (a % b == 0) ? a / b : a / b + 1;
}

vector<int> setArray(int a, FastScanner& scan) {
    vector<int> b(a);
    for (int i = 0; i < a; ++i) {
        b[i] = scan.nextInt();
    }
    return b;
}

vector<long long> lsetArray(int a, FastScanner& scan) {
    vector<long long> b(a);
    for (int i = 0; i < a; ++i) {
        b[i] = scan.nextLong();
    }
    return b;
}

long modlcm(long a, long b) {
    return a * b * modint(gcd(a, b), mod);
}

long gcd(long a, long b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long modint(long a, long m) {
    long b = m, u = 1, v = 0;
    while (b != 0) {
        long t = a / b;
        a -= t * b;
        long x = a;
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

string reverse(const string& str) {
    string s = str;
    reverse(s.begin(), s.end());
    return s;
}

vector<char> revch(const vector<char>& ch) {
    vector<char> ret(ch.size());
    for (int i = ch.size() - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

vector<int> revint(const vector<int>& ch) {
    vector<int> ret(ch.size());
    for (int i = ch.size() - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
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

vector<vector<int>> doublesort(const vector<vector<int>>& a) {
    vector<vector<int>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    });
    return sorted;
}

vector<vector<long long>> ldoublesort(const vector<vector<long long>>& a) {
    vector<vector<long long>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const vector<long long>& x, const vector<long long>& y) {
        return x[0] < y[0];
    });
    return sorted;
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
long long lmax(long long a, long long b) { return a > b ? a : b; }
long long lmin(long long a, long long b) { return a < b ? a : b; }
long long factorial(int i) {
    return i == 1 ? 1 : static_cast<long long>(i) * factorial(i-1);
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

void printArray(const vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; ++i) {
        cout << que[i] << " ";
    }
    cout << que.back() << endl;
}

int main() {
    FastScanner scan;
    string str = scan.next();
    if (str.length() < 6) {
        cout << "No" << endl;
    } else {
        if (str[2] == str[3] && str[4] == str[5]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
// End of Code
