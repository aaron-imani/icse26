#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

class UnionFind {
private:
    std::vector<int> parent;

public:
    UnionFind(int n) : parent(n, -1) {}

    int root(int A) {
        if (parent[A] < 0) return A;
        return parent[A] = root(parent[A]);
    }

    int size(int A) {
        return -parent[root(A)];
    }

    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) std::swap(A, B);
        parent[A] += parent[B];
        parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    std::istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(buffer, sizeof(buffer));
        buflen = in.gcount();
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
    FastScanner(std::istream& in) : in(in) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more input");
        std::string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.push_back(static_cast<char>(b));
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) throw std::runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw std::runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw std::runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw std::runtime_error("Number out of range");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return std::stod(next());
    }

    char nextChar() {
        int c = in.get();
        if (c == EOF) throw std::runtime_error("No more input");
        return static_cast<char>(c);
    }
};

static const long long mod = 1000000007;
static const double eps = 1.0E-14;
static const int big = INT_MAX;
static const double PI = 3.14159265358979323846262338327950288;

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
    return std::max(a, b);
}

long long lmin(long long a, long long b) {
    return std::min(a, b);
}

long long factorial(int i) {
    return i == 1 ? 1 : i * factorial(i - 1);
}

int lower_bound(const std::vector<int>& a, int key) {
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

int upper_bound(const std::vector<int>& a, int key) {
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

std::vector<int> setArray(int a) {
    std::vector<int> b(a);
    FastScanner scan(std::cin);
    for (int i = 0; i < a; i++) {
        b[i] = scan.nextInt();
    }
    return b;
}

std::vector<long long> lsetArray(int a) {
    std::vector<long long> b(a);
    FastScanner scan(std::cin);
    for (int i = 0; i < a; i++) {
        b[i] = scan.nextLong();
    }
    return b;
}

std::string reverse(const std::string& str) {
    std::string ch(str.rbegin(), str.rend());
    return ch;
}

void printArray(const std::vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; i++) {
        std::cout << que[i] << " ";
    }
    std::cout << que.back() << std::endl;
}

std::vector<std::pair<int, int>> doublesort(const std::vector<std::pair<int, int>>& a) {
    std::vector<std::pair<int, int>> sorted = a;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

std::vector<std::pair<long long, long long>> ldoublesort(const std::vector<std::pair<long long, long long>>& a) {
    std::vector<std::pair<long long, long long>> sorted = a;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

long long modpow(long long x, long long n, long long mo) {
    long long sum = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            sum = sum * x % mo;
        }
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

char* revch(char ch[], int len) {
    char* ret = new char[len];
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

int* revint(int ch[], int len) {
    int* ret = new int[len];
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

void warshall_floyd(int v[][100], int n) {
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
    FastScanner scan(std::cin);
    std::string str = scan.next();
    std::cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << std::endl;
    // End of Code
}
