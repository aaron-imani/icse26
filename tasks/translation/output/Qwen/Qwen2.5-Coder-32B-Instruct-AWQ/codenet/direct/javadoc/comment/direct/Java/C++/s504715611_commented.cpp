#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <random>
#include <cstdio>

using namespace std;

class UnionFind {
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
    FILE *fp;
    char buffer[1024];
    int ptr;
    int buflen;
public:
    FastScanner() {
        fp = stdin;
        ptr = 0;
        buflen = 0;
    }

    ~FastScanner() {
        fclose(fp);
    }

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, sizeof(buffer), fp);
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string result;
        int b = readByte();
        while (isPrintableChar(b)) {
            result.push_back(b);
            b = readByte();
        }
        return result;
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
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of int range");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return stod(next());
    }

    char nextchar() {
        return static_cast<char>(readByte());
    }
};

const long long mod = 1000000007;
const double eps = 1.0E-14;
const int big = INT_MAX;
const double PI = 3.14159265358979323846262338327950288;

long long modint(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b != 0) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long long gcd(long long a, long long b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

long long lmax(long long a, long long b) {
    return max(a, b);
}

long long lmin(long long a, long long b) {
    return min(a, b);
}

long long factorial(int i) {
    return i == 1 ? 1 : i * factorial(i - 1);
}

int lower_bound(const vector<int>& a, int key) {
    int right = a.size();
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(const vector<int>& a, int key) {
    int right = a.size();
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] <= key) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

bool isPrime(long long n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    double d = sqrt(n);
    for (int i = 3; i <= d; i += 2) if (n % i == 0) return false;
    return true;
}

int upper_division(int a, int b) {
    return (a + b - 1) / b;
}

long long lupper_division(long long a, long long b) {
    return (a + b - 1) / b;
}

vector<int> setArray(int a) {
    vector<int> b(a);
    for (int i = 0; i < a; i++) {
        b[i] = FastScanner().nextInt();
    }
    return b;
}

vector<long long> lsetArray(int a) {
    vector<long long> b(a);
    for (int i = 0; i < a; i++) {
        b[i] = FastScanner().nextLong();
    }
    return b;
}

string reverse(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

void printArray(const vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; i++) {
        cout << que[i] << " ";
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

vector<char> revch(const vector<char>& ch) {
    vector<char> ret = ch;
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> revint(const vector<int>& ch) {
    vector<int> ret = ch;
    reverse(ret.begin(), ret.end());
    return ret;
}

void warshall_floyd(vector<vector<int>>& v, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

int main() {
    FastScanner scan;
    string str = scan.next();
    cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << endl;
    return 0;
}
// End of Code
