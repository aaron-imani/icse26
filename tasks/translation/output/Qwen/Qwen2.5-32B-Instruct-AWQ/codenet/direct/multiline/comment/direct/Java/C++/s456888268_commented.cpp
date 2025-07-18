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
const int INF = numeric_limits<int>::max() / 2;
const long long LINF = numeric_limits<long long>::max() / 3;
const double DINFINITY = numeric_limits<double>::max() / 3;
const double EPS = 1e-10;
const double PI = acos(-1);

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
    reverse(s.begin(), s.end());
}

template<typename T>
void reverse(vector<T>& ls) {
    int sz = ls.size();
    for (int i = 0; i < sz / 2; i++) {
        swap(ls[i], ls[sz - 1 - i]);
    }
}

template<typename T>
void reverse(T ar[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(ar[i], ar[size - 1 - i]);
    }
}

int lowerBound(const vector<int>& a, int x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int upperBound(const vector<int>& a, int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int rlowerBound(const vector<int>& a, int x) {
    return lower_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int rupperBound(const vector<int>& a, int x) {
    return upper_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int lowerBound(const vector<long long>& a, long long x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int upperBound(const vector<long long>& a, long long x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int rlowerBound(const vector<long long>& a, long long x) {
    return lower_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int rupperBound(const vector<long long>& a, long long x) {
    return upper_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int lowerBound(const vector<double>& a, double x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int upperBound(const vector<double>& a, double x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int rlowerBound(const vector<double>& a, double x) {
    return lower_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int rupperBound(const vector<double>& a, double x) {
    return upper_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int lowerBound(const string& a, char x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int upperBound(const string& a, char x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int rlowerBound(const string& a, char x) {
    return lower_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int rupperBound(const string& a, char x) {
    return upper_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

template<typename T>
int lowerBound(const vector<T>& ls, const T& x) {
    return lower_bound(ls.begin(), ls.end(), x) - ls.begin();
}

template<typename T>
int upperBound(const vector<T>& ls, const T& x) {
    return upper_bound(ls.begin(), ls.end(), x) - ls.begin();
}

template<typename T>
int rlowerBound(const vector<T>& ls, const T& x) {
    return lower_bound(ls.rbegin(), ls.rend(), x) - ls.rbegin();
}

template<typename T>
int rupperBound(const vector<T>& ls, const T& x) {
    return upper_bound(ls.rbegin(), ls.rend(), x) - ls.rbegin();
}

vector<int> concat(int x, const vector<int>& arr) {
    vector<int> ret(arr);
    ret.insert(ret.begin(), x);
    return ret;
}

vector<int> concat(const vector<int>& arr, int x) {
    vector<int> ret(arr);
    ret.push_back(x);
    return ret;
}

vector<long long> concat(long long x, const vector<long long>& arr) {
    vector<long long> ret(arr);
    ret.insert(ret.begin(), x);
    return ret;
}

vector<long long> concat(const vector<long long>& arr, long long x) {
    vector<long long> ret(arr);
    ret.push_back(x);
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

void sort(string& ar) {
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

void rsort(string& ar) {
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
    cin.tie(nullptr);
    solve();
    return 0;
}

// End of Code
