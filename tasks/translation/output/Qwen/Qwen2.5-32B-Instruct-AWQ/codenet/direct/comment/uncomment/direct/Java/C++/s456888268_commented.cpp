#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

const long long MOD = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int INF = INT_MAX / 2;
const long long LINF = LLONG_MAX / 3;
const double DINFINITY = DBL_MAX / 3;
const double EPS = 1e-10;
const double PI = M_PI;

void reverse(vector<int>& ar) {
    int len = ar.size();
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

void reverse(vector<long long>& ar) {
    int len = ar.size();
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

void reverse(vector<double>& ar) {
    int len = ar.size();
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

void reverse(string& s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        swap(s[i], s[len - 1 - i]);
    }
}

template<typename T>
void reverse(vector<T>& ls) {
    int sz = ls.size();
    for (int i = 0; i < sz / 2; i++) {
        swap(ls[i], ls[sz - 1 - i]);
    }
}

template<typename T>
void reverse(T* ar, int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

int lowerBound(vector<int>& a, int x) {
    int l = -1, r = a.size();
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

int upperBound(vector<int>& a, int x) {
    int l = -1, r = a.size();
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

int rlowerBound(vector<int>& a, int x) {
    int l = -1, r = a.size();
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

int rupperBound(vector<int>& a, int x) {
    int l = -1, r = a.size();
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

int lowerBound(vector<long long>& a, long long x) {
    int l = -1, r = a.size();
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

int upperBound(vector<long long>& a, long long x) {
    int l = -1, r = a.size();
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

int rlowerBound(vector<long long>& a, long long x) {
    int l = -1, r = a.size();
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

int rupperBound(vector<long long>& a, long long x) {
    int l = -1, r = a.size();
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

int lowerBound(vector<double>& a, double x) {
    int l = -1, r = a.size();
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

int upperBound(vector<double>& a, double x) {
    int l = -1, r = a.size();
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

int rlowerBound(vector<double>& a, double x) {
    int l = -1, r = a.size();
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

int rupperBound(vector<double>& a, double x) {
    int l = -1, r = a.size();
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

int lowerBound(vector<char>& a, char x) {
    int l = -1, r = a.size();
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

int upperBound(vector<char>& a, char x) {
    int l = -1, r = a.size();
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

int rlowerBound(vector<char>& a, char x) {
    int l = -1, r = a.size();
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

int rupperBound(vector<char>& a, char x) {
    int l = -1, r = a.size();
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

template<typename T>
int lowerBound(vector<T>& ls, T x) {
    auto it = lower_bound(ls.begin(), ls.end(), x);
    return it - ls.begin();
}

template<typename T>
int upperBound(vector<T>& ls, T x) {
    auto it = upper_bound(ls.begin(), ls.end(), x);
    return it - ls.begin();
}

template<typename T>
int rupperBound(vector<T>& ls, T x) {
    auto it = upper_bound(ls.rbegin(), ls.rend(), x);
    return ls.size() - (it - ls.rbegin());
}

template<typename T>
int rlowerBound(vector<T>& ls, T x) {
    auto it = lower_bound(ls.rbegin(), ls.rend(), x);
    return ls.size() - (it - ls.rbegin());
}

vector<int> concat(int x, vector<int>& arr) {
    vector<int> ret(arr.size() + 1);
    copy(arr.begin(), arr.end(), ret.begin() + 1);
    ret[0] = x;
    return ret;
}

vector<int> concat(vector<int>& arr, int x) {
    vector<int> ret(arr.size() + 1);
    copy(arr.begin(), arr.end(), ret.begin());
    ret.back() = x;
    return ret;
}

vector<long long> concat(long long x, vector<long long>& arr) {
    vector<long long> ret(arr.size() + 1);
    copy(arr.begin(), arr.end(), ret.begin() + 1);
    ret[0] = x;
    return ret;
}

vector<long long> concat(vector<long long>& arr, long long x) {
    vector<long long> ret(arr.size() + 1);
    copy(arr.begin(), arr.end(), ret.begin());
    ret.back() = x;
    return ret;
}

int max(int x, int y) {
    return std::max(x, y);
}

int min(int x, int y) {
    return std::min(x, y);
}

int max(int x, int y, int z) {
    return std::max({x, y, z});
}

int min(int x, int y, int z) {
    return std::min({x, y, z});
}

long long max(long long x, long long y) {
    return std::max(x, y);
}

long long min(long long x, long long y) {
    return std::min(x, y);
}

long long max(long long x, long long y, long long z) {
    return std::max({x, y, z});
}

long long min(long long x, long long y, long long z) {
    return std::min({x, y, z});
}

double max(double x, double y) {
    return std::max(x, y);
}

double min(double x, double y) {
    return std::min(x, y);
}

double max(double x, double y, double z) {
    return std::max({x, y, z});
}

double min(double x, double y, double z) {
    return std::min({x, y, z});
}

void sort(vector<int>& ar) {
    std::sort(ar.begin(), ar.end());
}

void sort(vector<long long>& ar) {
    std::sort(ar.begin(), ar.end());
}

void sort(vector<double>& ar) {
    std::sort(ar.begin(), ar.end());
}

void sort(vector<char>& ar) {
    std::sort(ar.begin(), ar.end());
}

void rsort(vector<int>& ar) {
    std::sort(ar.begin(), ar.end());
    reverse(ar);
}

void rsort(vector<long long>& ar) {
    std::sort(ar.begin(), ar.end());
    reverse(ar);
}

void rsort(vector<double>& ar) {
    std::sort(ar.begin(), ar.end());
    reverse(ar);
}

void rsort(vector<char>& ar) {
    std::sort(ar.begin(), ar.end());
    reverse(ar);
}

void fill(vector<int>& arr, int x) {
    std::fill(arr.begin(), arr.end(), x);
}

void fill(vector<long long>& arr, long long x) {
    std::fill(arr.begin(), arr.end(), x);
}

void fill(vector<bool>& arr, bool x) {
    std::fill(arr.begin(), arr.end(), x);
}

void fill(vector<double>& arr, double x) {
    std::fill(arr.begin(), arr.end(), x);
}

void fill(vector<vector<int>>& arr, int x) {
    for (auto& row : arr) {
        std::fill(row.begin(), row.end(), x);
    }
}

void fill(vector<vector<long long>>& arr, long long x) {
    for (auto& row : arr) {
        std::fill(row.begin(), row.end(), x);
    }
}

void fill(vector<vector<double>>& arr, double x) {
    for (auto& row : arr) {
        std::fill(row.begin(), row.end(), x);
    }
}

void fill(vector<vector<bool>>& arr, bool x) {
    for (auto& row : arr) {
        std::fill(row.begin(), row.end(), x);
    }
}

long long plus(long long x, long long y) {
    long long res = (x + y) % MOD;
    return res < 0 ? res + MOD : res;
}

long long sub(long long x, long long y) {
    long long res = (x - y) % MOD;
    return res < 0 ? res + MOD : res;
}

long long mul(long long x, long long y) {
    long long res = (x * y) % MOD;
    return res < 0 ? res + MOD : res;
}

long long div(long long x, long long y) {
    long long res = x * pow(y, MOD - 2) % MOD;
    return res < 0 ? res + MOD : res;
}

long long pow(long long x, long long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % MOD;
    long long root = pow(x, y / 2);
    return root * root % MOD;
}

void solve() {
    string tmp;
    cin >> tmp;
    vector<char> s(tmp.begin(), tmp.end());
    int n = s.size();
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
