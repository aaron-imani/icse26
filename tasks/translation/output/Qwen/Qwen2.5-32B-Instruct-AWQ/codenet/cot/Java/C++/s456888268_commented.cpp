#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    string tmp;
    cin >> tmp;
    char s[tmp.length()];
    strcpy(s, tmp.c_str());
    int n = strlen(s);
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'S') {
            cnt++;
        } else {
            if(cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << n - 2*ans << endl;
}

const long mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int inf = INT_MAX / 2;
const long linf = LONG_MAX / 3;
const double dinf = DBL_MAX / 3;
const double eps = 1e-10;
const double pi = M_PI;
string sb;

template<typename T>
void reverse(T ar[], int len) {
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
void reverse(vector<T>& ls) {
    reverse(ls.begin(), ls.end());
}

template<typename T>
void reverse(T ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        T t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void sbnl() {
    sb += "\n";
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

template<typename T>
int lowerBound(vector<T>& ls, T x) {
    return lower_bound(ls.begin(), ls.end(), x) - ls.begin();
}

template<typename T>
int upperBound(vector<T>& ls, T x) {
    return upper_bound(ls.begin(), ls.end(), x) - ls.begin();
}

template<typename T>
int rupperBound(vector<T>& ls, T x) {
    return upper_bound(ls.begin(), ls.end(), x, greater<T>()) - ls.begin();
}

template<typename T>
int rlowerBound(vector<T>& ls, T x) {
    return lower_bound(ls.begin(), ls.end(), x, greater<T>()) - ls.begin();
}

template<typename T>
T* concat(T x, T* arr, int n) {
    T* ret = new T[n + 1];
    for (int i = 0; i < n; i++) {
        ret[i + 1] = arr[i];
    }
    ret[0] = x;
    return ret;
}

template<typename T>
T* concat(T* arr, int n, T x) {
    T* ret = new T[n + 1];
    for (int i = 0; i < n; i++) {
        ret[i] = arr[i];
    }
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
    return std::max({x, y, z});
}

int min(int x, int y, int z) {
    return std::min({x, y, z});
}

long max(long x, long y) {
    return std::max(x, y);
}

long min(long x, long y) {
    return std::min(x, y);
}

long max(long x, long y, long z) {
    return std::max({x, y, z});
}

long min(long x, long y, long z) {
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

void sort(int* ar, int n) {
    std::sort(ar, ar + n);
}

void sort(long* ar, int n) {
    std::sort(ar, ar + n);
}

void sort(double* ar, int n) {
    std::sort(ar, ar + n);
}

void sort(char* ar, int n) {
    std::sort(ar, ar + n);
}

void rsort(int* ar, int n) {
    std::sort(ar, ar + n);
    for (int i = 0; i < n / 2; i++) {
        std::swap(ar[i], ar[n - 1 - i]);
    }
}

void rsort(long* ar, int n) {
    std::sort(ar, ar + n);
    for (int i = 0; i < n / 2; i++) {
        std::swap(ar[i], ar[n - 1 - i]);
    }
}

void rsort(double* ar, int n) {
    std::sort(ar, ar + n);
    for (int i = 0; i < n / 2; i++) {
        std::swap(ar[i], ar[n - 1 - i]);
    }
}

void rsort(char* ar, int n) {
    std::sort(ar, ar + n);
    for (int i = 0; i < n / 2; i++) {
        std::swap(ar[i], ar[n - 1 - i]);
    }
}

void fill(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        arr[i] = x;
    }
}

void fill(long* arr, int n, long x) {
    for (int i = 0; i < n; i++) {
        arr[i] = x;
    }
}

void fill(bool* arr, int n, bool x) {
    for (int i = 0; i < n; i++) {
        arr[i] = x;
    }
}

void fill(double* arr, int n, double x) {
    for (int i = 0; i < n; i++) {
        arr[i] = x;
    }
}

void fill(int** arr, int n, int m, int x) {
    for (int i = 0; i < n; i++) {
        fill(arr[i], m, x);
    }
}

void fill(long** arr, int n, int m, long x) {
    for (int i = 0; i < n; i++) {
        fill(arr[i], m, x);
    }
}

void fill(double** arr, int n, int m, double x) {
    for (int i = 0; i < n; i++) {
        fill(arr[i], m, x);
    }
}

void fill(bool** arr, int n, int m, bool x) {
    for (int i = 0; i < n; i++) {
        fill(arr[i], m, x);
    }
}

long plus(long x, long y) {
    long res = (x + y) % mod;
    return res < 0 ? res + mod : res;
}

long sub(long x, long y) {
    long res = (x - y) % mod;
    return res < 0 ? res + mod : res;
}

long mul(long x, long y) {
    long res = (x * y) % mod;
    return res < 0 ? res + mod : res;
}

long div(long x, long y) {
    long res = x * pow(y, mod - 2) % mod;
    return res < 0 ? res + mod : res;
}

long pow(long x, long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % mod;
    long root = pow(x, y / 2);
    return root * root % mod;
}

int main() {
    solve();
    return 0;
}
// End of Code
