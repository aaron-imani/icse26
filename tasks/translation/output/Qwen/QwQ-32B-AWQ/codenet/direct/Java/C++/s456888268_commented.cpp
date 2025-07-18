#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

const long long mod = 1e9 +7;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int dx8[] = {-1,-1,-1,0,0,1,1,1};
const int dy8[] = {-1,0,1,-1,1,-1,0,1};
const int inf = INT32_MAX / 2;
const long long linf = LLONG_MAX /3;
const double dinf = numeric_limits<double>::max() /3;
const double eps = 1e-10;
const double pi = 3.14159265358979323846;

void solve() {
    string tmp;
    cin >> tmp;
    int n = tmp.length();
    int ans =0, cnt=0;
    for (char c : tmp) {
        if (c == 'S') {
            cnt++;
        } else {
            if (cnt ==0) continue;
            ans++;
            cnt--;
        }
    }
    cout << (n - 2*ans) << endl;
}

template<typename T>
void reverse(vector<T>& vec) {
    int len = vec.size();
    for (int i=0; i < len/2; i++) {
        swap(vec[i], vec[len-1 -i]);
    }
}

string getReverse(const string& s) {
    string res = s;
    reverse(res.begin(), res.end());
    return res;
}

int lowerBound(const vector<int>& a, int x) {
    int l = -1, r = a.size();
    while (r - l >1) {
        int c = (l + r)/2;
        if (a[c] < x) l =c;
        else r =c;
    }
    return r;
}

int upperBound(const vector<int>& a, int x) {
    int l = -1, r = a.size();
    while (r - l >1) {
        int c = (l + r)/2;
        if (a[c] <=x) l =c;
        else r =c;
    }
    return r;
}

int rlowerBound(const vector<int>& a, int x) {
    int l = -1, r = a.size();
    while (r - l >1) {
        int c = (l + r)/2;
        if (a[c] > x) l =c;
        else r =c;
    }
    return r;
}

int rupperBound(const vector<int>& a, int x) {
    int l = -1, r = a.size();
    while (r - l >1) {
        int c = (l + r)/2;
        if (a[c] >=x) l =c;
        else r =c;
    }
    return r;
}

vector<int> concat(int x, vector<int> arr) {
    arr.insert(arr.begin(), x);
    return arr;
}

vector<int> concat(vector<int> arr, int x) {
    arr.push_back(x);
    return arr;
}

vector<long long> concat(long long x, vector<long long> arr) {
    arr.insert(arr.begin(), x);
    return arr;
}

vector<long long> concat(vector<long long> arr, long long x) {
    arr.push_back(x);
    return arr;
}

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y, int z) { return max(max(x,y), z); }
int min(int x, int y, int z) { return min(min(x,y), z); }
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x < y ? x : y; }
long long max(long long x, long long y, long long z) { return max(max(x,y), z); }
long long min(long long x, long long y, long long z) { return min(min(x,y), z); }
double max(double x, double y) { return x > y ? x : y; }
double min(double x, double y) { return x < y ? x : y; }
double max(double x, double y, double z) { return max(max(x,y), z); }
double min(double x, double y, double z) { return min(min(x,y), z); }

template<typename T>
void sort(vector<T>& vec) {
    sort(vec.begin(), vec.end());
}

template<typename T>
void rsort(vector<T>& vec) {
    sort(vec.begin(), vec.end());
    reverse(vec);
}

void fill(int arr[], int len, int x) {
    for (int i=0; i < len; i++) arr[i] =x;
}

void fill(long long arr[], int len, long long x) {
    for (int i=0; i < len; i++) arr[i] =x;
}

void fill(bool arr[], int len, bool x) {
    for (int i=0; i < len; i++) arr[i] =x;
}

void fill(double arr[], int len, double x) {
    for (int i=0; i < len; i++) arr[i] =x;
}

void fill(int arr[][1000], int rows, int cols, int x) {
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            arr[i][j] =x;
}

void fill(long long arr[][1000], int rows, int cols, long long x) {
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            arr[i][j] =x;
}

void fill(double arr[][1000], int rows, int cols, double x) {
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            arr[i][j] =x;
}

void fill(bool arr[][1000], int rows, int cols, bool x) {
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            arr[i][j] =x;
}

long long plus(long long x, long long y) {
    long long res = (x + y) % mod;
    return res <0 ? res + mod : res;
}

long long sub(long long x, long long y) {
    long long res = (x - y) % mod;
    return res <0 ? res + mod : res;
}

long long mul(long long x, long long y) {
    long long res = (x * y) % mod;
    return res <0 ? res + mod : res;
}

long long div(long long x, long long y) {
    long long res = x * pow(y, mod-2) % mod;
    return res <0 ? res + mod : res;
}

long long pow(long long x, long long y) {
    if (y <0) return 0;
    if (y ==0) return 1;
    if (y%2 ==1) return (x * pow(x, y-1)) % mod;
    long long root = pow(x, y/2);
    return root * root % mod;
}

int main() {
    solve();
    return 0;
}
// End of Code
