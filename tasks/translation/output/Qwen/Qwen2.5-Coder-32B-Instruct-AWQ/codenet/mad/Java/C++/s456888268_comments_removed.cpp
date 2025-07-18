#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int inf = INT_MAX / 2;
const long long linf = LLONG_MAX / 3;
const double dinf = DBL_MAX / 3;
const double eps = 1e-10;
const double pi = M_PI;
stringstream sb;
stringstream out;
string INPUT = "";

string ns() {
    string s;
    if (INPUT.empty()) {
        cin >> s;
    } else {
        stringstream ss(INPUT);
        ss >> s;
    }
    return s;
}

void solve() {
    string tmp = ns();
    vector<char> s(tmp.begin(), tmp.end());
    int n = s.size();
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'S') {
            cnt++;
        }
        else {
            if(cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    out << n - 2 * ans << endl;
}

template<typename T>
void reverse(vector<T>& ar) {
    int len = ar.size();
    for (int i = 0; i < len / 2; i++) {
        T t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

string getReverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
vector<T> concat(T x, vector<T> arr) {
    vector<T> ret = {x};
    ret.insert(ret.end(), arr.begin(), arr.end());
    return ret;
}

template<typename T>
vector<T> concat(vector<T> arr, T x) {
    arr.push_back(x);
    return arr;
}

template<typename T>
T max(T x, T y) {
    return std::max(x, y);
}

template<typename T>
T min(T x, T y) {
    return std::min(x, y);
}

template<typename T>
T max(T x, T y, T z) {
    return std::max(x, std::max(y, z));
}

template<typename T>
T min(T x, T y, T z) {
    return std::min(x, std::min(y, z));
}

template<typename T>
void sort(vector<T>& ar) {
    std::sort(ar.begin(), ar.end());
}

template<typename T>
void rsort(vector<T>& ar) {
    std::sort(ar.begin(), ar.end());
    reverse(ar);
}

template<typename T>
void fill(vector<T>& arr, T x) {
    std::fill(arr.begin(), arr.end(), x);
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
    if (!INPUT.empty()) {
        stringstream ss(INPUT);
        cin.rdbuf(ss.rdbuf());
    }
    solve();
    cout << out.str();
    return 0;
}
// End of Code
