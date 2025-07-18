#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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
const double pi = acos(-1.0);

string inputBuffer;
int ptr = 0;

int readByte() {
    if (ptr >= inputBuffer.size()) return -1;
    return inputBuffer[ptr++];
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && isSpaceChar(b));
    return b;
}

string ns() {
    int b = skip();
    string res;
    while (!isSpaceChar(b)) {
        res += (char)b;
        b = readByte();
    }
    return res;
}

int ni() {
    int num = 0, b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

long long nl() {
    long long num = 0;
    int b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

template<typename T>
void reverse(T arr[], int len) {
    for (int i = 0; i < len/2; ++i) {
        swap(arr[i], arr[len-1-i]);
    }
}

void reverse(vector<int>& ls) {
    int sz = ls.size();
    for (int i = 0; i < sz/2; ++i) {
        swap(ls[i], ls[sz-1-i]);
    }
}

string getReverse(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev;
}

int lowerBound(int arr[], int len, int x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (arr[c] < x) l = c;
        else r = c;
    }
    return r;
}

int upperBound(int arr[], int len, int x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r)/2;
        if (arr[c] <= x) l = c;
        else r = c;
    }
    return r;
}

void fill(int arr[], int len, int x) {
    for (int i = 0; i < len; ++i) arr[i] = x;
}

void fill(vector<int>& vec, int x) {
    for (auto& e : vec) e = x;
}

long long plus(long long x, long long y) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
    return x;
}

long long sub(long long x, long long y) {
    x -= y;
    if (x < 0) x += mod;
    return x;
}

long long mul(long long x, long long y) {
    x *= y;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

long long div(long long x, long long y) {
    return mul(x, pow(y, mod-2));
}

long long pow(long long x, long long y) {
    if (y == 0) return 1;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = mul(res, x);
        x = mul(x, x);
        y /= 2;
    }
    return res;
}

void solve() {
    string tmp = ns();
    int n = tmp.length();
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (tmp[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << (n - 2 * ans) << endl;
}

int main() {
    cin >> noskipws;
    inputBuffer.clear();
    char c;
    while (cin.get(c)) {
        inputBuffer += c;
    }
    ptr = 0;
    solve();
    return 0;
}
// End of Code
