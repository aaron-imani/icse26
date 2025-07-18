#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> Parent;
    UnionFind(int n) : Parent(n, -1) {}
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    int size(int A) { return -Parent[root(A)]; }
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

struct FastScanner {
    char buffer[1024];
    int ptr, buflen;

    FastScanner() : ptr(0), buflen(0) {}

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, stdin);
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    bool hasNext() {
        skipWhite();
        return hasNextByte();
    }

    void skipWhite() {
        while (hasNextByte()) {
            int c = buffer[ptr];
            if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
                ptr++;
            } else {
                break;
            }
        }
    }

    string next() {
        skipWhite();
        if (!hasNextByte()) return "";
        string s;
        int b = buffer[ptr++];
        while (isPrintableChar(b)) {
            s += (char)b;
            if (hasNextByte()) {
                b = buffer[ptr++];
            } else {
                break;
            }
        }
        return s;
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    long long nextLong() {
        if (!hasNext()) return 0;
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') return  bergen:: 0;
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + (b - '0');
            } else if (b == -1 || !isPrintableChar(b)) {
                break;
            } else {
                return 0;
            }
            b = readByte();
        }
        return minus ? -n : n;
    }

    int nextInt() { return (int)nextLong(); }

    double nextDouble() {
        string s = next();
        return stod(s);
    }

    char nextChar() {
        if (!hasNext()) return 0;
        int b = readByte();
        while (!isPrintableChar(b)) {
            b = readByte();
        }
        return (char)b;
    }
};

int lower_bound(int a[], int n, int key) {
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] < key)
            left = mid;
        else
            right = mid;
    }
    return left;
}

int upper_bound(int a[], int n, int key) {
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] <= key)
            left = mid;
        else
            right = mid;
    }
    return left;
}

bool isPrime(long n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    long d = sqrt(n);
    for (long i = 3; i <= d; i += 2)
        if (n % i == 0) return false;
    return true;
}

int upper_division(int a, int b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

vector<int> setArray(int a) {
    vector<int> b(a);
    for (int i = 0; i < a; i++)
        b[i] = scan.nextInt();
    return b;
}

vector<long> lsetArray(int a) {
    vector<long> b(a);
    for (int i = 0; i < a; i++)
        b[i] = scan.nextLong();
    return b;
}

string reverse(const string& str) {
    string s = str;
    int n = s.length();
    for (int i = 0; i < (n + 1) / 2; i++)
        swap(s[i], s[n - 1 - i]);
    return s;
}

void printArray(const vector<int>& que) {
    for (int i = 0; i < que.size() - 1; i++)
        cout << que[i] << " ";
    cout << que.back() << endl;
}

vector<vector<int>> doublesort(const vector<vector<int>>& a) {
    vector<vector<int>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    });
    return sorted;
}

vector<vector<long>> ldoublesort(const vector<vector<long>>& a) {
    vector<vector<long>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const vector<long>& x, const vector<long>& y) {
        return x[0] < y[0];
    });
    return sorted;
}

long long modpow(long long x, long long n, long long mo) {
    long long sum = 1;
    while (n > 0) {
        if (n & 1)
            sum = sum * x % mo;
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

char* revch(char ch[], int len) {
    char* ret = new char[len];
    for (int i = 0, j = len - 1; i < len; i++, j--)
        ret[i] = ch[j];
    return ret;
}

int* revint(int ch[], int len) {
    int* ret = new int[len];
    for (int i = 0, j = len - 1; i < len; i++, j--)
        ret[i] = ch[j];
    return ret;
}

void warshall_floyd(int v[][100], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
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

FastScanner scan;

int main() {
    string str = scan.next();
    if (str.length() < 6)
        cout << "No" << endl;
    else {
        if (str[2] == str[3] && str[4] == str[5])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
} // End of Code
