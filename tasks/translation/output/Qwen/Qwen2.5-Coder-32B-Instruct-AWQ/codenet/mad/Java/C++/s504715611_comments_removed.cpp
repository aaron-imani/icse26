// Include necessary headers
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cstring>

class UnionFind {
public:
    std::vector<int> Parent;
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
        if (size(A) < size(B)) std::swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    std::istream& in;
    char buffer[1024];
    size_t ptr;
    size_t buflen;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(buffer, sizeof(buffer));
        buflen = in.gcount();
        return buflen > 0;
    }

    char readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    static bool isPrintableChar(char c) {
        return 33 <= c && c <= 126;
    }

public:
    FastScanner(std::istream& in = std::cin) : in(in), ptr(0), buflen(0) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more elements in input");
        std::string sb;
        char b = readByte();
        while (isPrintableChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) throw std::runtime_error("No more elements in input");
        long long n = 0;
        bool minus = false;
        char b = readByte();
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
        if (nl < std::numeric_limits<int>::min() || nl > std::numeric_limits<int>::max()) throw std::runtime_error("Number out of int range");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return std::stod(next());
    }

    char nextchar() {
        return readByte();
    }
};

const long long mod = 1000000007;
const double eps = 1.0E-14;
const int big = std::numeric_limits<int>::max();
const double PI = 3.14159265358979323846262338327950288;

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
    double d = std::sqrt(n);
    for (int i = 3; i <= d; i += 2) if (n % i == 0) return false;
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
    FastScanner scan;
    for (int i = 0; i < a; i++) {
        b[i] = scan.nextInt();
    }
    return b;
}

std::vector<long long> lsetArray(int a) {
    std::vector<long long> b(a);
    FastScanner scan;
    for (int i = 0; i < a; i++) {
        b[i] = scan.nextLong();
    }
    return b;
}

std::string reverse(const std::string& str) {
    std::string ch = str;
    int a = str.length();
    for (int i = 0; i < upper_division(a, 2); i++) {
        std::swap(ch[i], ch[ch.length() - i - 1]);
    }
    return ch;
}

void printArray(const std::vector<int>& que) {
    for (size_t i = 0; i < que.size() - 1; i++) {
        std::cout << que[i] << " ";
    }
    std::cout << que[que.size() - 1] << std::endl;
}

std::vector<std::vector<int>> doublesort(std::vector<std::vector<int>>& a) {
    std::sort(a.begin(), a.end(), [](const std::vector<int>& x, const std::vector<int>& y) {
        return x[0] < y[0];
    });
    return a;
}

std::vector<std::vector<long long>> ldoublesort(std::vector<std::vector<long long>>& a) {
    std::sort(a.begin(), a.end(), [](const std::vector<long long>& x, const std::vector<long long>& y) {
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

std::vector<char> revch(const std::vector<char>& ch) {
    std::vector<char> ret(ch.size());
    for (size_t i = ch.size() - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

std::vector<int> revint(const std::vector<int>& ch) {
    std::vector<int> ret(ch.size());
    for (size_t i = ch.size() - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

void warshall_floyd(std::vector<std::vector<int>>& v, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = std::min(v[i][j], v[i][k] + v[k][j]);
}

long long modint(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b != 0) {
        long long t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    FastScanner scan;
    std::string str = scan.next();
    std::cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << std::endl;
    return 0;
}
// End of Code
