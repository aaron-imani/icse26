#include <bits/stdc++.h>
using namespace std;

void solve() {
    string tmp;
    cin >> tmp;
    int n = tmp.length();
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << n - 2 * ans << endl;
}

const long long mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int inf = INT_MAX / 2;
const long long linf = LLONG_MAX / 3;
const double dinf = numeric_limits<double>::max() / 3;
const double eps = 1e-10;
const double pi = M_PI;

template <typename T>
void reverse(vector<T>& ar) {
    int len = ar.size();
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

template <typename T>
void reverse(T ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

string getReverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

template <typename T>
int lowerBound(vector<T>& a, T x) {
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

template <typename T>
int upperBound(vector<T>& a, T x) {
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

template <typename T>
int rlowerBound(vector<T>& a, T x) {
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

template <typename T>
int rupperBound(vector<T>& a, T x) {
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

template <typename T>
void fill(vector<T>& arr, T x) {
    fill(arr.begin(), arr.end(), x);
}

template <typename T>
void fill(vector<vector<T>>& arr, T x) {
    for (auto& row : arr) {
        fill(row.begin(), row.end(), x);
    }
}

long long plus(long long x, long long y) {
    long long res = (x + y) % mod;
    return res < 0 ? res + mod : res;
}

long long sub(long long x, long long y) {
    long long res = (x - y) % mod;
    return res < 0 ? res + mod : res;
}

long long mul(long long x, long long y) {
    long long res = (x * y) % mod;
    return res < 0 ? res + mod : res;
}

long long div(long long x, long long y) {
    long long res = x * pow(y, mod - 2) % mod;
    return res < 0 ? res + mod : res;
}

long long pow(long long x, long long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % mod;
    long long root = pow(x, y / 2);
    return root * root % mod;
}

int main() {
    solve();
    return 0;
}
// End of Code
