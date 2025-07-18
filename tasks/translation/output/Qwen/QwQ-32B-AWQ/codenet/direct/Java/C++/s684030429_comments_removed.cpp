#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int ni() {
    int a;
    cin >> a;
    return a;
}

long long nl() {
    long long a;
    cin >> a;
    return a;
}

float nf() {
    float a;
    cin >> a;
    return a;
}

double nd() {
    double a;
    cin >> a;
    return a;
}

string ns() {
    string s;
    getline(cin, s);
    return s;
}

vector<string> nst(const string &s) {
    istringstream iss(s);
    vector<string> tokens;
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void ia(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = ni();
    }
}

void la(long a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = nl();
    }
}

void fa(float a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = nf();
    }
}

void da(double a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = nd();
    }
}

void sa(string a[], int n, bool empty) {
    if (empty) {
        for (int i = 0; i < n; i++) {
            a[i] = "";
        }
    } else {
        for (int i = 0; i < n; i++) {
            a[i] = ns();
        }
    }
}

void ida(int a[][/* m */], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = ni();
        }
    }
}

void lda(long a[][/* m */], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = nl();
        }
    }
}

void dda(double a[][/* m */], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = nd();
        }
    }
}

int stoi(const string &s) {
    return stoi(s);
}

double stod(const string &s) {
    return stod(s);
}

long lmin(long a[], int n) {
    long min_val = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) min_val = a[i];
    }
    return min_val;
}

int imin(int a[], int n) {
    int min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) min_val = a[i];
    }
    return min_val;
}

long lmax(long a[], int n) {
    long max_val = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_val) max_val = a[i];
    }
    return max_val;
}

int imax(int a[], int n) {
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_val) max_val = a[i];
    }
    return max_val;
}

bool ibs(int a[], int n, int toFind) {
    sort(a, a + n);
    int min = 0;
    int max = n-1;
    bool found = false;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) {
            found = true;
        } else if (toFind > a[mid]) {
            min = mid + 1;
        } else {
            max = mid -1;
        }
    }
    return found;
}

bool lbs(long a[], int n, long toFind) {
    sort(a, a + n);
    int min = 0;
    int max = n-1;
    bool found = false;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) {
            found = true;
        } else if (toFind > a[mid]) {
            min = mid +1;
        } else {
            max = mid-1;
        }
    }
    return found;
}

int stb(const string &s) {
    int sum =0, k=0;
    for (int i = s.length()-1; i >=0; i--) {
        int digit = s[i] - '0';
        sum += digit * pow(2, k++);
    }
    return sum;
}

void solve() {
    int a = ni();
    int b = ni();
    cout << std::max(0, a - 2 * b) << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
