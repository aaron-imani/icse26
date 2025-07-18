#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long mod = 1000000007LL;
const double eps = 1.0e-14;
const int big = numeric_limits<int>::max();
const double PI = 3.14159265358979323846262338327950288;

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
    istream& in;
    vector<char> buffer;
    size_t ptr = 0, buflen = 0;
public:
    FastScanner() : in(cin), buffer(1024) {}
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = in.read(buffer.data(), buffer.size());
        return buflen > 0;
    }
    int readByte() {
        if (!hasNextByte()) return -1;
        return static_cast<unsigned char>(buffer[ptr++]);
    }
    bool hasNext() {
        while (hasNextByte()) {
            int current = buffer[ptr];
            if (current >= 33 && current <= 126) return true;
            ptr++;
        }
        return false;
    }
    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string sb;
        int b = readByte();
        while (b >= 33 && b <= 126) {
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
        if (b < '0' || b > '9') throw invalid_argument("Invalid number format");
        while (true) {
            if (b >= '0' && b <= '9') {
                n = n * 10 + (b - '0');
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw invalid_argument("Invalid number format");
            }
            b = readByte();
        }
    }
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw out_of_range("Value out of range");
        return static_cast<int>(nl);
    }
    double nextDouble() {
        string s = next();
        return stod(s);
    }
    char nextchar() {
        if (!hasNextByte()) throw runtime_error("No more input");
        return static_cast<char>(readByte());
    }
private:
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
};

FastScanner scan;

long long modlcm(long long a, long long b) {
    return a * b * modint(gcd(a, b), mod);
}

long long gcd(long long a, long long b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int upper_division(int a, int b) {
    return (a + b - 1) / b;
}

long long lupper_division(long long a, long long b) {
    return (a + b - 1) / b;
}

vector<int> setArray(int a) {
    vector<int> b(a);
    for (int i = 0; i < a; ++i) b[i] = scan.nextInt();
    return b;
}

vector<long long> lsetArray(int a) {
    vector<long long> b(a);
    for (int i = 0; i < a; ++i) b[i] = scan.nextLong();
    return b;
}

string reverse(const string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t;
}

void printArray(const vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; ++i) cout << que[i] << " ";
    cout << que.back() << endl;
}

vector<vector<int>> doublesort(const vector<vector<int>>& a) {
    vector<vector<int>> sorted = a;
    sort(sorted.begin(), sorted.end(), [](const auto& x, const auto& y) {
        return x[0] < y[0];
    });
    return sorted;
}

long long modpow(long long x, long long n, long long mo) {
    long long sum = 1;
    while (n > 0) {
        if (n & 1) sum = sum * x % mo;
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

vector<char> revch(const vector<char>& ch) {
    vector<char> ret(ch.size());
    for (int i = ch.size() - 1, j = 0; i >= 0; --i, ++j) ret[j] = ch[i];
    return ret;
}

vector<int> revint(const vector<int>& ch) {
    vector<int> ret(ch.size());
    for (int i = ch.size() - 1, j = 0; i >= 0; --i, ++j) ret[j] = ch[i];
    return ret;
}

void warshall_floyd(vector<vector<int>>& v, int n) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
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
    return u < 0 ? u + m : u;
}

int main() {
    string s = scan.next();
    cout << (s.length() >= 6 && s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << endl;
    return 0;
} // End of Code
