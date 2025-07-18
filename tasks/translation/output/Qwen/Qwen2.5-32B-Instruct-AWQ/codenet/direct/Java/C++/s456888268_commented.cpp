#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <chrono>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define clr(x, v) memset(x, v, sizeof(x))
#define debug(x) cerr << #x << " = " << x << endl

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
const double dinf = (double)1e30;
const double eps = 1e-10;
const double pi = acos(-1.0);

void reverse(int ar[]) {
    int len = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < len / 2; i++) {
        int t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse(long ar[]) {
    int len = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < len / 2; i++) {
        long t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse(double ar[]) {
    int len = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < len / 2; i++) {
        double t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse(char ar[]) {
    int len = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < len / 2; i++) {
        char t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

string getReverse(string s) {
    char c[] = s.c_str();
    reverse(c);
    s = string(c);
    return s;
}

template <typename T>
void reverse(vector<T>& ls) {
    int sz = ls.size();
    for (int i = 0; i < sz / 2; i++) {
        T t = ls[i];
        ls[i] = ls[sz - 1 - i];
        ls[sz - 1 - i] = t;
    }
}

template <typename T>
void reverse(T ar[]) {
    int len = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < len / 2; i++) {
        T t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void sbnl() {
    cout << "\n";
}

int lowerBound(int a[], int x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(int a[], int x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(int a[], int x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(int a[], int x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound(long a[], long x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(long a[], long x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(long a[], long x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(long a[], long x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound(double a[], double x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(double a[], double x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(double a[], double x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(double a[], double x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound(char a[], char x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(char a[], char x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(char a[], char x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(char a[], char x, int n) {
    int l = -1, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

template <typename T>
int lowerBound(vector<T>& ls, T x) {
    if (ls.size() == 0)
        return -1;
    return lower_bound(all(ls), x) - ls.begin();
}

template <typename T>
int upperBound(vector<T>& ls, T x) {
    if (ls.size() == 0)
        return -1;
    return upper_bound(all(ls), x) - ls.begin();
}

template <typename T>
int rupperBound(vector<T>& ls, T x) {
    if (ls.size() == 0)
        return -1;
    return lower_bound(all(ls), x) - ls.begin();
}

template <typename T>
int rlowerBound(vector<T>& ls, T x) {
    if (ls.size() == 0)
        return -1;
    return upper_bound(all(ls), x) - ls.begin();
}

int* concat(int x, int arr[], int n) {
    int* ret = new int[n + 1];
    memcpy(ret + 1, arr, n * sizeof(int));
    ret[0] = x;
    return ret;
}

int* concat(int arr[], int n, int x) {
    int* ret = new int[n + 1];
    memcpy(ret, arr, n * sizeof(int));
    ret[n] = x;
    return ret;
}

long* concat(long x, long arr[], int n) {
    long* ret = new long[n + 1];
    memcpy(ret + 1, arr, n * sizeof(long));
    ret[0] = x;
    return ret;
}

long* concat(long arr[], int n, long x) {
    long* ret = new long[n + 1];
    memcpy(ret, arr, n * sizeof(long));
    ret[n] = x;
    return ret;
}

int max(int x, int y) {
    return std::max(x, y);
}

int min(int x, int y) {
    return std::min(x, y);
}

int max(int x, int y, int z) {
    x = std::max(x, y);
    x = std::max(x, z);
    return x;
}

int min(int x, int y, int z) {
    x = std::min(x, y);
    x = std::min(x, z);
    return x;
}

long max(long x, long y) {
    return std::max(x, y);
}

long min(long x, long y) {
    return std::min(x, y);
}

long max(long x, long y, long z) {
    x = std::max(x, y);
    x = std::max(x, z);
    return x;
}

long min(long x, long y, long z) {
    x = std::min(x, y);
    x = std::min(x, z);
    return x;
}

double max(double x, double y) {
    return std::max(x, y);
}

double min(double x, double y) {
    return std::min(x, y);
}

double max(double x, double y, double z) {
    x = std::max(x, y);
    x = std::max(x, z);
    return x;
}

double min(double x, double y, double z) {
    x = std::min(x, y);
    x = std::min(x, z);
    return x;
}

void sort(int arr[], int n) {
    std::sort(arr, arr + n);
}

void sort(long arr[], int n) {
    std::sort(arr, arr + n);
}

void sort(double arr[], int n) {
    std::sort(arr, arr + n);
}

void sort(char arr[], int n) {
    std::sort(arr, arr + n);
}

void rsort(int arr[], int n) {
    std::sort(arr, arr + n);
    for (int i = 0; i < n / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

void rsort(long arr[], int n) {
    std::sort(arr, arr + n);
    for (int i = 0; i < n / 2; i++) {
        long tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

void rsort(double arr[], int n) {
    std::sort(arr, arr + n);
    for (int i = 0; i < n / 2; i++) {
        double tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

void rsort(char arr[], int n) {
    std::sort(arr, arr + n);
    for (int i = 0; i < n / 2; i++) {
        char tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

void fill(int arr[], int x, int n) {
    std::fill(arr, arr + n, x);
}

void fill(long arr[], long x, int n) {
    std::fill(arr, arr + n, x);
}

void fill(bool arr[], bool x, int n) {
    std::fill(arr, arr + n, x);
}

void fill(double arr[], double x, int n) {
    std::fill(arr, arr + n, x);
}

void fill(int arr[][], int x, int n, int m) {
    for (int i = 0; i < n; i++)
        std::fill(arr[i], arr[i] + m, x);
}

void fill(long arr[][], long x, int n, int m) {
    for (int i = 0; i < n; i++)
        std::fill(arr[i], arr[i] + m, x);
}

void fill(double arr[][], double x, int n, int m) {
    for (int i = 0; i < n; i++)
        std::fill(arr[i], arr[i] + m, x);
}

void fill(bool arr[][], bool x, int n, int m) {
    for (int i = 0; i < n; i++)
        std::fill(arr[i], arr[i] + m, x);
}

//MOD culc
long plus(long x, long y, long mod) {
    long res = (x + y) % mod;
    return res < 0 ? res + mod : res;
}

long sub(long x, long y, long mod) {
    long res = (x - y) % mod;
    return res < 0 ? res + mod : res;
}

long mul(long x, long y, long mod) {
    long res = (x * y) % mod;
    return res < 0 ? res + mod : res;
}

long div(long x, long y, long mod) {
    long res = x * pow(y, mod - 2, mod) % mod;
    return res < 0 ? res + mod : res;
}

long pow(long x, long y, long mod) {
    if (y < 0)
        return 0;
    if (y == 0)
        return 1;
    if (y % 2 == 1)
        return (x * pow(x, y - 1, mod)) % mod;
    long root = pow(x, y / 2, mod);
    return root * root % mod;
}

void solve() {
    string tmp;
    cin >> tmp;
    char s[] = tmp.c_str();
    int n = strlen(s);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0)
                continue;
            ans++;
            cnt--;
        }
    }
    cout << n - 2 * ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// End of Code
