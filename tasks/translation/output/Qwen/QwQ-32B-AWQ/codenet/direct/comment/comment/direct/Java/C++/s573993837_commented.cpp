#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class InputReader {
private:
    istream& in;
    vector<string> tokens;
    size_t current = 0;

public:
    InputReader(istream& in) : in(in) {}

    string next() {
        if (current >= tokens.size()) {
            tokens.clear();
            string line;
            getline(in, line);
            istringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
            current = 0;
        }
        return tokens[current++];
    }

    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
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
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0) return 1;
    if (n == 1) return base % M;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0) {
        return (halfn * halfn) % M;
    } else {
        return ((halfn * halfn) % M * base) % M;
    }
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

void swap(char arr[], int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template<typename T>
void feedArr(vector<T>& arr, InputReader& in) {
    for (T& x : arr) {
        if constexpr (is_same_v<T, int>) {
            x = in.nextInt();
        } else if constexpr (is_same_v<T, long long>) {
            x = in.nextLong();
        } else if constexpr (is_same_v<T, double>) {
            x = in.nextDouble();
        } else if constexpr (is_same_v<T, string>) {
            x = in.next();
        }
    }
}

string printArr(const vector<int>& arr) {
    string res;
    for (int num : arr) {
        res += to_string(num) + ' ';
    }
    return res;
}

string printArr(const vector<long long>& arr) {
    string res;
    for (long long num : arr) {
        res += to_string(num) + ' ';
    }
    return res;
}

string printArr(const vector<string>& arr) {
    string res;
    for (const string& s : arr) {
        res += s + ' ';
    }
    return res;
}

string printArr(const vector<double>& arr) {
    string res;
    for (double num : arr) {
        res += to_string(num) + ' ';
    }
    return res;
}

void solve(InputReader& in, ostream& out) {
    int t = in.nextInt();
    while (t--) {
        long long n = in.nextLong();
        long long m = in.nextLong();
        if (n == 0) {
            out << 0 << '\n';
            continue;
        }
        if (n == m) {
            out << 0 << '\n';
            continue;
        }
        if (n > m) {
            n %= m;
            out << min(m - n, n) << '\n';
        } else {
            out << min(m - n, n) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    ostream& out = cout;
    solve(in, out);
    return 0;
}
// End of Code
