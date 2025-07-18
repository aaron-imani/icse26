#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

int L, R, top, bottom;

class InputReader {
private:
    std::istream& in;
    std::queue<std::string> tokens;
public:
    InputReader(std::istream& inputStream = std::cin) : in(inputStream) {}
    std::string next() {
        if (tokens.empty()) {
            std::string line;
            std::getline(in, line);
            std::stringstream ss(line);
            std::string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        std::string result = tokens.front();
        tokens.pop();
        return result;
    }
    int nextInt() { return std::stoi(next()); }
    long long nextLong() { return std::stoll(next()); }
    double nextDouble() { return std::stod(next()); }
};

struct Pair {
    int u, v, i;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

int num(int n) {
    int a = 0;
    while (n > 0) {
        a += (n & 1);
        n >>= 1;
    }
    return a;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0) return 1;
    if (n == 1) return base % M;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return ((halfn * halfn) % M * base) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

void swap(char arr[], int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void feedArr(int arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) arr[i] = sc.nextInt();
}

void feedArr(long long arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) arr[i] = sc.nextLong();
}

void feedArr(double arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) arr[i] = sc.nextDouble();
}

void feedArr(std::string arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) arr[i] = sc.next();
}

std::string printArr(int arr[], int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; ++i)
        oss << arr[i] << " ";
    return oss.str();
}

std::string printArr(long long arr[], int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; ++i)
        oss << arr[i] << " ";
    return oss.str();
}

std::string printArr(std::string arr[], int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; ++i)
        oss << arr[i] << " ";
    return oss.str();
}

std::string printArr(double arr[], int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; ++i)
        oss << arr[i] << " ";
    return oss.str();
}

void solve(InputReader& sc, std::ostream& pw) {
    int t = 1;
    u: while (t-- > 0) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            pw << 0 << '\n';
            continue u;
        }
        if (n == m) {
            pw << 0 << '\n';
            continue u;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            pw << std::min(m - n, n) << '\n';
            continue u;
        }
        pw << std::min(m - n, n) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    InputReader in;
    solve(in, std::cout);
    return 0;
}
// End of Code
