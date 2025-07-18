#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class UnionFind {
public:
    vector<int> Parent;
    UnionFind(int n) {
        Parent.resize(n, -1);
    }
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
        if (size(A) < size(B)) {
            swap(A, B);
        }
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
private:
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, stdin);
        if (buflen <= 0) return false;
        return true;
    }
    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
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
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += (char)b;
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
        if (b < '0' || b > '9') {
            throw runtime_error("Invalid number");
        }
        while (true) {
            if (b >= '0' && b <= '9') {
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
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of range");
        return static_cast<int>(nl);
    }
    double nextDouble() {
        return stod(next());
    }
    char nextChar() {
        int b = readByte();
        while (!isPrintableChar(b) && hasNextByte()) {
            b = readByte();
        }
        if (b == -1) throw runtime_error("No character");
        return (char)b;
    }
};

FastScanner scan;
long mod = 1000000007;
double eps = 1.0e-14;
int big = INT_MAX;
double PI = 3.14159265358979323846262338327950288;

int lower_bound(int a[], int size, int key) {
    int right = size;
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

int upper_bound(int a[], int size, int key) {
    int right = size;
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
    long long d = sqrt(n);
    for (long long i = 3; i <= d; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int upper_division(int a, int b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

long long lupper_division(long long a, long long b) {
    return (a % b == 0) ? a / b : a / b + 1;
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

string reverse(const string& str) {
    string ch = str;
    int a = str.length();
    for (int i = 0; i < upper_division(a, 2); i++) {
        swap(ch[i], ch[a - 1 - i]);
    }
    return ch;
}

void printArray(const vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; i++) {
        cout << que[i] << " ";
    }
    cout << que.back() << endl;
}

vector<vector<int>> doublesort(const vector<vector<int>>& a) {
    vector<vector<int>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const vector<int>& x, const vector<int>& y) { return x[0] < y[0]; });
    return sorted;
}

vector<vector<long long>> ldoublesort(const vector<vector<long long>>& a) {
    vector<vector<long long>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const vector<long long>& x, const vector<long long>& y) { return x[0] < y[0]; });
    return sorted;
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

int main() {
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
