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
const double DINFINITY = DBL_MAX / 3;
const double EPS = 1e-10;
const double PI = M_PI;

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void reverse(long arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void reverse(double arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void reverse(char arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

string getReverse(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

template<typename T>
void reverse(vector<T>& ls) {
    reverse(ls.begin(), ls.end());
}

template<typename T>
void reverse(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
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

int lowerBound(const vector<char>& a, char x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int upperBound(const vector<char>& a, char x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int rlowerBound(const vector<char>& a, char x) {
    return lower_bound(a.rbegin(), a.rend(), x) - a.rbegin();
}

int rupperBound(const vector<char>& a, char x) {
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

int* concat(int x, int arr[], int size) {
    int* ret = new int[size + 1];
    memcpy(ret + 1, arr, size * sizeof(int));
    ret[0] = x;
    return ret;
}

int* concat(int arr[], int size, int x) {
    int* ret = new int[size + 1];
    memcpy(ret, arr, size * sizeof(int));
    ret[size] = x;
    return ret;
}

long long* concat(long long x, long long arr[], int size) {
    long long* ret = new long long[size + 1];
    memcpy(ret + 1, arr, size * sizeof(long long));
    ret[0] = x;
    return ret;
}

long long* concat(long long arr[], int size, long long x) {
    long long* ret = new long long[size + 1];
    memcpy(ret, arr, size * sizeof(long long));
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

void sort(int arr[], int size) {
    std::sort(arr, arr + size);
}

void sort(long long arr[], int size) {
    std::sort(arr, arr + size);
}

void sort(double arr[], int size) {
    std::sort(arr, arr + size);
}

void sort(char arr[], int size) {
    std::sort(arr, arr + size);
}

void rsort(int arr[], int size) {
    std::sort(arr, arr + size);
    reverse(arr, size);
}

void rsort(long long arr[], int size) {
    std::sort(arr, arr + size);
    reverse(arr, size);
}

void rsort(double arr[], int size) {
    std::sort(arr, arr + size);
    reverse(arr, size);
}

void rsort(char arr[], int size) {
    std::sort(arr, arr + size);
    reverse(arr, size);
}

void fill(int arr[], int size, int x) {
    std::fill(arr, arr + size, x);
}

void fill(long long arr[], int size, long long x) {
    std::fill(arr, arr + size, x);
}

void fill(bool arr[], int size, bool x) {
    std::fill(arr, arr + size, x);
}

void fill(double arr[], int size, double x) {
    std::fill(arr, arr + size, x);
}

void fill(int arr[][100], int rows, int cols, int x) {
    for (int i = 0; i < rows; ++i) {
        std::fill(arr[i], arr[i] + cols, x);
    }
}

void fill(long long arr[][100], int rows, int cols, long long x) {
    for (int i = 0; i < rows; ++i) {
        std::fill(arr[i], arr[i] + cols, x);
    }
}

void fill(double arr[][100], int rows, int cols, double x) {
    for (int i = 0; i < rows; ++i) {
        std::fill(arr[i], arr[i] + cols, x);
    }
}

void fill(bool arr[][100], int rows, int cols, bool x) {
    for (int i = 0; i < rows; ++i) {
        std::fill(arr[i], arr[i] + cols, x);
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
    char s[tmp.size()];
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
} // End of Code
