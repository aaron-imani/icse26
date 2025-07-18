#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const long long MOD = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int INF = INT_MAX / 2;
const long long LINF = LLONG_MAX / 3;
const double DINF = DBL_MAX / 3;
const double EPS = 1e-10;
const double PI = M_PI;

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
    char c[s.length()];
    strcpy(c, s.c_str());
    reverse(c);
    s = string(c);
    return s;
}

template<typename T>
void reverse(vector<T>& ls) {
    int sz = ls.size();
    for (int i = 0; i < sz / 2; i++) {
        T t = ls[i];
        ls[i] = ls[sz - 1 - i];
        ls[sz - 1 - i] = t;
    }
}

template<typename T>
void reverse(T ar[]) {
    int len = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < len / 2; i++) {
        T t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

int lowerBound(int ar[], int x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(int ar[], int x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(int ar[], int x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(int ar[], int x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound(long ar[], long x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(long ar[], long x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(long ar[], long x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(long ar[], long x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound(double ar[], double x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(double ar[], double x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(double ar[], double x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(double ar[], double x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound(char ar[], char x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound(char ar[], char x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound(char ar[], char x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound(char ar[], char x) {
    int l = -1, r = sizeof(ar) / sizeof(ar[0]);
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (ar[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

template<typename T>
int lowerBound(vector<T>& ls, T x) {
    if (ls.empty())
        return -1;
    auto it = lower_bound(ls.begin(), ls.end(), x);
    return it - ls.begin();
}

template<typename T>
int upperBound(vector<T>& ls, T x) {
    if (ls.empty())
        return -1;
    auto it = upper_bound(ls.begin(), ls.end(), x);
    return it - ls.begin();
}

template<typename T>
int rupperBound(vector<T>& ls, T x) {
    if (ls.empty())
        return -1;
    auto it = upper_bound(ls.rbegin(), ls.rend(), x);
    return ls.size() - (it - ls.rbegin());
}

template<typename T>
int rlowerBound(vector<T>& ls, T x) {
    if (ls.empty())
        return -1;
    auto it = lower_bound(ls.rbegin(), ls.rend(), x);
    return ls.size() - (it - ls.rbegin());
}

int* concat(int x, int ar[], int size) {
    int* ret = new int[size + 1];
    memcpy(ret + 1, ar, size * sizeof(int));
    ret[0] = x;
    return ret;
}

int* concat(int ar[], int size, int x) {
    int* ret = new int[size + 1];
    memcpy(ret, ar, size * sizeof(int));
    ret[size] = x;
    return ret;
}

long* concat(long x, long ar[], int size) {
    long* ret = new long[size + 1];
    memcpy(ret + 1, ar, size * sizeof(long));
    ret[0] = x;
    return ret;
}

long* concat(long ar[], int size, long x) {
    long* ret = new long[size + 1];
    memcpy(ret, ar, size * sizeof(long));
    ret[size] = x;
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

void sort(int ar[], int size) {
    std::sort(ar, ar + size);
}

void sort(long ar[], int size) {
    std::sort(ar, ar + size);
}

void sort(double ar[], int size) {
    std::sort(ar, ar + size);
}

void sort(char ar[], int size) {
    std::sort(ar, ar + size);
}

void rsort(int ar[], int size) {
    std::sort(ar, ar + size);
    for (int i = 0; i < size / 2; i++) {
        std::swap(ar[i], ar[size - 1 - i]);
    }
}

void rsort(long ar[], int size) {
    std::sort(ar, ar + size);
    for (int i = 0; i < size / 2; i++) {
        std::swap(ar[i], ar[size - 1 - i]);
    }
}

void rsort(double ar[], int size) {
    std::sort(ar, ar + size);
    for (int i = 0; i < size / 2; i++) {
        std::swap(ar[i], ar[size - 1 - i]);
    }
}

void rsort(char ar[], int size) {
    std::sort(ar, ar + size);
    for (int i = 0; i < size / 2; i++) {
        std::swap(ar[i], ar[size - 1 - i]);
    }
}

void fill(int ar[], int size, int x) {
    memset(ar, x, size * sizeof(int));
}

void fill(long ar[], int size, long x) {
    memset(ar, x, size * sizeof(long));
}

void fill(bool ar[], int size, bool x) {
    memset(ar, x ? 1 : 0, size * sizeof(bool));
}

void fill(double ar[], int size, double x) {
    memset(ar, x, size * sizeof(double));
}

void fill(int ar[][100], int rows, int cols, int x) {
    for (int i = 0; i < rows; i++) {
        fill(ar[i], cols, x);
    }
}

void fill(long ar[][100], int rows, int cols, long x) {
    for (int i = 0; i < rows; i++) {
        fill(ar[i], cols, x);
    }
}

void fill(double ar[][100], int rows, int cols, double x) {
    for (int i = 0; i < rows; i++) {
        fill(ar[i], cols, x);
    }
}

void fill(bool ar[][100], int rows, int cols, bool x) {
    for (int i = 0; i < rows; i++) {
        fill(ar[i], cols, x);
    }
}

long plus(long x, long y) {
    long res = (x + y) % MOD;
    return res < 0 ? res + MOD : res;
}

long sub(long x, long y) {
    long res = (x - y) % MOD;
    return res < 0 ? res + MOD : res;
}

long mul(long x, long y) {
    long res = (x * y) % MOD;
    return res < 0 ? res + MOD : res;
}

long div(long x, long y) {
    long res = x * pow(y, MOD - 2) % MOD;
    return res < 0 ? res + MOD : res;
}

long pow(long x, long y) {
    if (y < 0)
        return 0;
    if (y == 0)
        return 1;
    if (y % 2 == 1)
        return (x * pow(x, y - 1)) % MOD;
    long root = pow(x, y / 2);
    return root * root % MOD;
}

void solve() {
    string tmp;
    cin >> tmp;
    char s[tmp.length()];
    strcpy(s, tmp.c_str());
    int n = strlen(s);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << n - 2 * ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
// End of Code
