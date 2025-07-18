#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

static int L, R, top, bottom;

class InputReader {
private:
    istream& in;
    queue<string> tokens;
public:
    InputReader(istream& is) : in(is) {}
    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            istringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push(token);
            }
        }
        if (tokens.empty()) return "";
        string result = tokens.front();
        tokens.pop();
        return result;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

void solve(InputReader& sc, ostream& out) {
    int t = 1;
    u_loop:
    while (t-- > 0) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            out << "0\n";
            continue u_loop;
        }
        if (n == m) {
            out << "0\n";
            continue u_loop;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            out << min(m - n, n) << '\n';
            continue u_loop;
        }
        out << min(m - n, n) << '\n';
    }
}

void swap(char arr[], int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

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
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return (a > b) ? gcd(b, a % b) : gcd(a, b % a);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0) return 1LL;
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

void feedArr(long arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) {
        arr[i] = sc.nextLong();
    }
}

void feedArr(int arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) {
        arr[i] = sc.nextInt();
    }
}

void feedArr(double arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) {
        arr[i] = sc.nextDouble();
    }
}

void feedArr(string arr[], int size, InputReader& sc) {
    for (int i = 0; i < size; ++i) {
        arr[i] = sc.next();
    }
}

string printArr(int arr[], int size) {
    ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << arr[i] << " ";
    }
    return oss.str();
}

string printArr(long arr[], int size) {
    ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << arr[i] << " ";
    }
    return oss.str();
}

string printArr(string arr[], int size) {
    ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << arr[i] << " ";
    }
    return oss.str();
}

string printArr(double arr[], int size) {
    ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << arr[i] << " ";
    }
    return oss.str();
}

struct Pair {
    int u, v, i, val;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    ostream& out = cout;
    solve(in, out);
    return 0;
}
// End of Code
