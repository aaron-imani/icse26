#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int ni() {
    int a;
    cin >> a;
    return a;
}

long nl() {
    long a;
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

void ia(int a[], int size) {
    for (int i = 0; i < size; i++)
        a[i] = ni();
}

void la(long a[], int size) {
    for (int i = 0; i < size; i++)
        a[i] = nl();
}

void fa(float a[], int size) {
    for (int i = 0; i < size; i++)
        a[i] = nf();
}

void da(double a[], int size) {
    for (int i = 0; i < size; i++)
        a[i] = nd();
}

void sa(string a[], bool empty, int size) {
    if (empty) {
        for (int i = 0; i < size; i++)
            a[i] = "";
    } else {
        for (int i = 0; i < size; i++)
            a[i] = ns();
    }
}

void ida(vector<vector<int>>& a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = ni();
}

void lda(vector<vector<long>>& a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = nl();
}

void dda(vector<vector<double>>& a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = nd();
}

long lmin(long a[], int size) {
    long min = LONG_MAX;
    for (int i = 0; i < size; i++)
        if (min > a[i]) min = a[i];
    return min;
}

int imin(int a[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
        if (min > a[i]) min = a[i];
    return min;
}

long lmax(long a[], int size) {
    long max = LONG_MIN;
    for (int i = 0; i < size; i++)
        if (max < a[i]) max = a[i];
    return max;
}

int imax(int a[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        if (max < a[i]) max = a[i];
    return max;
}

bool ibs(int a[], int size, int toFind) {
    sort(a, a + size);
    int min = 0, max = size - 1;
    bool found = false;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = true;
        else if (toFind > a[mid]) min = mid + 1;
        else max = mid - 1;
    }
    return found;
}

bool lbs(long a[], int size, long toFind) {
    sort(a, a + size);
    int min = 0, max = size - 1;
    bool found = false;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = true;
        else if (toFind > a[mid]) min = mid + 1;
        else max = mid - 1;
    }
    return found;
}

int stb(const string& s) {
    int sum = 0, k = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        string temp(1, s[i]);
        int num = stoi(temp);
        sum += num * static_cast<int>(pow(2, k++));
    }
    return sum;
}

void solve() {
    int a = ni();
    int b = ni();
    cout << std::max(0, a - 2*b) << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
