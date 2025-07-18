#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int L, R, top, bottom;

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

void swap(char &chrr, char &ch) {
    char temp = chrr;
    chrr = ch;
    ch = temp;
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

void feedArr(vector<long long> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

void feedArr(vector<double> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

void feedArr(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

void feedArr(vector<string> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

string printArr(const vector<int> &arr) {
    stringstream sbr;
    for (int i : arr)
        sbr << i << " ";
    return sbr.str();
}

string printArr(const vector<long long> &arr) {
    stringstream sbr;
    for (long long i : arr)
        sbr << i << " ";
    return sbr.str();
}

string printArr(const vector<string> &arr) {
    stringstream sbr;
    for (string i : arr)
        sbr << i << " ";
    return sbr.str();
}

string printArr(const vector<double> &arr) {
    stringstream sbr;
    for (double i : arr)
        sbr << i << " ";
    return sbr.str();
}

int main() {
    solve();
    // End of Code
}
