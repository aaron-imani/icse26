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
