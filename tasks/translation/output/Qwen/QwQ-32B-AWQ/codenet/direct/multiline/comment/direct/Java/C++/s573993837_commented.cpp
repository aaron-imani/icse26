#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int L, R, top, bottom;

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
    return b == 0 ? a : gcd(b, a % b);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 稠密的) return 1;
    if (n == 1) return base % M;
    long long halfn = fast_pow(base, n / 2, M);
    return (n % 2 == 0) ? (halfn * halfn) % M : ((halfn * halfn) % M * base) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

class InputReader {
private:
    istream& in;
    vector<string> currentTokens;
    size_t currentTokenIndex;
    void readNextLine() {
        string line;
        if (!getline(in, line)) {
            currentTokens.clear();
            return;
        }
        stringstream ss(line);
        currentTokens.clear();
        string token;
        while (ss >> token) currentTokens.push_back(token);
        currentTokenIndex = 0;
    }
public:
    InputReader(istream& input) : in(input), currentTokenIndex(0) {}
    string next() {
        if (currentTokenIndex >= currentTokens.size()) {
            readNextLine();
            if (currentTokens.empty()) return "";
        }
        return currentTokens[currentTokenIndex++];
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

void solve(InputReader& in, ostream& out) {
    int t = 1;
    u: while (t-- > 0) {
        long long n = in.nextLong(), m = in.nextLong();
        if (n == 0) {
            out << 0 << endl;
            continue u;
        }
        if (n == m) {
            out << 0 << endl;
            continue u;
        }
        if (n > m) {
            n %= m;
            out << min(m - n, n) << endl;
            continue u;
        }
        out << min(m - n, n) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    solve(in, cout);
    return 0;
} // End of Code
