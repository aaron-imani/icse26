#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

static int L, R, top, bottom;

struct Pair {
    int u, v, i;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
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
        n >>= , 1;
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
    if (a > b) return gcd(b, a % b);
    else return gcd(a, b % a);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0) return 1 % M;
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

template<typename T>
void feedArr(vector<T>& arr, InputReader& in) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = in.nextLong();
    }
}

string printArr(const vector<int>& arr) {
    ostringstream oss;
    for (size_t i = 0; i < arr.size(); ++i) {
        oss << arr[i] << " ";
    }
    return oss.str();
}

string printArr(const vector<long long>& arr) {
    ostringstream oss;
    for (size_t i = 0; i < arr.size(); ++i) {
        oss << arr[i] << " ";
    }
    return oss.str();
}

class InputReader {
private:
    istream& stream;
    queue<string> tokens;
public:
    InputReader(istream& in) : stream(in) {}
    string next() {
        if (tokens.empty()) {
            string line;
            getline(stream, line);
            if (line.empty()) return next();
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        string result = tokens.front();
        tokens.pop();
        return result;
    }
    int nextInt() {
        return stoi(next());
    }
    long long nextLong() {
        return stoll(next());
    }
    double nextDouble() {
        return stod(next());
    }
};

void solve(InputReader& in, ostream& out) {
    int t = 1;
    u:
    while (t-- > 0) {
        long long n = in.nextLong();
        long long m = in.nextLong();
        if (n == 0) {
            out << 0 << endl;
            continue u;
        }
        if (n == m) {
            out << 0 << endl;
            continue u;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            out << min(m - n, n) << endl;
            continue u;
        }
        out << min(m - n, n) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
