#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple>
#include <utility>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

class Pair {
public:
    int u, v, i, val;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

static bool isPrime(int n) {
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

static long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

static long long fast_pow(long long base, long long n, long long M) {
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

static long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

static void feedArr(vector<long long> &arr, istream &in) {
    for (int i = 0; i < arr.size(); i++)
        in >> arr[i];
}

static void feedArr(vector<double> &arr, istream &in) {
    for (int i = 0; i < arr.size(); i++)
        in >> arr[i];
}

static void feedArr(vector<int> &arr, istream &in) {
    for (int i = 0; i < arr.size(); i++)
        in >> arr[i];
}

static void feedArr(vector<string> &arr, istream &in) {
    for (int i = 0; i < arr.size(); i++)
        in >> arr[i];
}

static string printArr(const vector<int> &arr) {
    string sbr;
    for (int i : arr)
        sbr += to_string(i) + " ";
    return sbr;
}

static string printArr(const vector<long long> &arr) {
    string sbr;
    for (long long i : arr)
        sbr += to_string(i) + " ";
    return sbr;
}

static string printArr(const vector<string> &arr) {
    string sbr;
    for (const string &i : arr)
        sbr += i + " ";
    return sbr;
}

static string printArr(const vector<double> &arr) {
    string sbr;
    for (double i : arr)
        sbr += to_string(i) + " ";
    return sbr;
}

static void solve(istream &in, ostream &out) {
    int t = 1;
    while (t--) {
        long long n = 0, m = 0;
        in >> n >> m;
        if (n == 0) {
            out << 0 << "\n";
            continue;
        }
        if (n == m) {
            out << 0 << "\n";
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            out << min(m - n, n) << "\n";
            continue;
        }
        out << min(m - n, n) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve(cin, cout);

    return 0;
}
// End of Code
