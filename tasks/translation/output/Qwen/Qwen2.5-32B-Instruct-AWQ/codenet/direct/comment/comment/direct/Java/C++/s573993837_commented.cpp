#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Pair {
public:
    int u, v, i;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

template<typename T>
void feedArr(T arr[], int size, istream &is) {
    for (int i = 0; i < size; ++i)
        is >> arr[i];
}

template<>
void feedArr(string arr[], int size, istream &is) {
    for (int i = 0; i < size; ++i)
        is >> arr[i];
}

template<typename T>
string printArr(T arr[], int size) {
    string result;
    for (int i = 0; i < size; ++i)
        result += to_string(arr[i]) + " ";
    return result;
}

template<>
string printArr(string arr[], int size) {
    string result;
    for (int i = 0; i < size; ++i)
        result += arr[i] + " ";
    return result;
}

void solve(istream &is, ostream &os) {
    int t = 1;
    while (t--) {
        long long n, m;
        is >> n >> m;
        if (n == 0) {
            os << 0 << endl;
            continue;
        }
        if (n == m) {
            os << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            os << min(m - n, n) << endl;
            continue;
        }
        os << min(m - n, n) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve(cin, cout);

    return 0;
} // End of Code
