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
    char line[1024];
    char *cursor;
public:
    FastScanner() {
        fp = stdin;
        cursor = line;
    }

    bool hasNextByte() {
        if (*cursor != '\0') return true;
        memset(line, 0, sizeof(line));
        if (fgets(line, sizeof(line), fp) == nullptr) return false;
        cursor = line;
        return true;
    }

    int readByte() {
        if (!hasNextByte()) return -1;
        return *(cursor++);
    }

    bool hasNext() {
        while (hasNextByte() && isspace(*cursor)) cursor++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string result;
        while (hasNextByte() && !isspace(*cursor)) result += *(cursor++);
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
            } else if (b == -1 || isspace(b)) {
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
        return (int) nl;
    }

    double nextDouble() {
        return stod(next());
    }

    char nextchar() {
        if (!hasNextByte()) throw runtime_error("No more input");
        return *(cursor++);
    }
};

static FastScanner scan;
static mt19937 rand((random_device())());
static const long long mod = 1000000007;
static const double eps = 1.0E-14;
static const int big = INT_MAX;
static const double PI = 3.14159265358979323846262338327950288;

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

long long modlcm(long long a, long long b) {
    return a * b * modint(gcd(a, b), mod);
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

int lower_bound(vector<int>& a, int key) {
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

int upper_bound(vector<int>& a, int key) {
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
        b[i] = scan.nextInt();
    }
    return b;
}

vector<long long> lsetArray(int a) {
    vector<long long> b(a);
    for (int i = 0; i < a; i++) {
        b[i] = scan.nextLong();
    }
    return b;
}

string reverse(string str) {
    reverse(str.begin(), str.end());
    return str;
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
    vector<char> ret(ch.rbegin(), ch.rend());
    return ret;
}

vector<int> revint(const vector<int>& ch) {
    vector<int> ret(ch.rbegin(), ch.rend());
    return ret;
}

void warshall_floyd(vector<vector<int>>& v, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

int main() {
    string str = scan.next();
    cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << endl;
    return 0;
}
// End of Code
