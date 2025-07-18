#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdint>
using namespace std;

static int L, R, top, bottom;

class InputReader {
private:
    istream& in;
    string line;
    istringstream currentStream;
public:
    InputReader(istream& _in) : in(_in) {}
    string next() {
        while (true) {
            if (currentStream.eof()) {
                if (!getline(in, line)) {
                    throw runtime_error("Error reading input");
                }
                currentStream.str(line);
                currentStream.clear();
            }
            string token;
            if (currentStream >> token) {
                return token;
            }
        }
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

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

struct Pair {
    int u, v, i, val;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

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
    return b == 0 ? a : gcd(b, a % b);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0) return 1;
    long long halfn = fast_pow(base, n / 2, M);
    return (n % 2 == 0) ? 
        (halfn * halfn) % M : 
        ((halfn * halfn) % M * base) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

void solve(InputReader& in, ostream& out) {
    int t = 1;
    while (t-- > 0) {
        long long n = in.nextLong(), m = in.nextLong();
        if (n == 0) {
            out << "0\n";
            continue;
        }
        if (n == m) {
            out << "0\n";
            continue;
        }
        if (n > m) {
            n %= m;
        }
        out << min(m - n, n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
