#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int L, R, top, bottom;

void solve() {
    int t = 1;
    while (t--) {
        ll n, m;
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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

ll fast_pow(ll base, ll n, ll M) {
    if (n == 0) return 1;
    if (n == 1) return base;
    ll halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0) return (halfn * halfn) % M;
    else return (((halfn * halfn) % M) * base) % M;
}

ll modInverse(ll n, ll M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(vector<ll> &arr) {
    for (auto &i : arr) cin >> i;
}

void feedArr(vector<double> &arr) {
    for (auto &i : arr) cin >> i;
}

void feedArr(vector<int> &arr) {
    for (auto &i : arr) cin >> i;
}

void feedArr(vector<string> &arr) {
    for (auto &i : arr) cin >> i;
}

string printArr(const vector<int> &arr) {
    stringstream ss;
    for (int i : arr) ss << i << " ";
    return ss.str();
}

string printArr(const vector<ll> &arr) {
    stringstream ss;
    for (ll i : arr) ss << i << " ";
    return ss.str();
}

string printArr(const vector<string> &arr) {
    stringstream ss;
    for (const string &i : arr) ss << i << " ";
    return ss.str();
}

string printArr(const vector<double> &arr) {
    stringstream ss;
    for (double i : arr) ss << i << " ";
    return ss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// End of Code
