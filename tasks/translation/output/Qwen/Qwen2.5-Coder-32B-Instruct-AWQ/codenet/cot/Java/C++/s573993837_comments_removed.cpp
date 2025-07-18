#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int t = 1;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        if (n == m) {
            cout << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            cout << min(m - n, n) << endl;
            continue;
        }
        cout << min(m - n, n) << endl;
    }
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
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
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
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

template <typename T>
void feedArr(vector<T> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

template <typename T>
string printArr(const vector<T> &arr) {
    stringstream ss;
    for (const T &i : arr)
        ss << i << " ";
    return ss.str();
}

struct Pair {
    int u, v, i, val;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

int main() {
    solve();
    return 0;
}
// End of Code
