#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Main {
public:
    void solve();
    static int ni() { int x; cin >> x; return x; }
    static long nl() { long x; cin >> x; return x; }
    static float nf() { float x; cin >> x; return x; }
    static double nd() { double x; cin >> x; return x; }
    static string ns() { string s; getline(cin, s); return s; }
    static void ia(int a[], int n) { for (int i = 0; i < n; i++) cin >> a[i]; }
    static void la(long a[], int n) { for (int i = 0; i < n; i++) cin >> a[i]; }
    static void fa(float a[], int n) { for (int i = 0; i < n; i++) cin >> a[i]; }
    static void da(double a[], int n) { for (int i = 0; i < n; i++) cin >> a[i]; }
    static void sa(string a[], int n, bool empty) {
        if (empty) {
            for (int i = 0; i < n; i++) a[i] = "";
        } else {
            for (int i = 0; i < n; i++) a[i] = ns();
        }
    }
    static void ida(int a[][/* some size */], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = ni();
            }
        }
    }
    static void lda(long a[][/* some size */], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nl();
            }
        }
    }
    static void dda(double a[][/* some size */], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nd();
            }
        }
    }
    static int imin(int a[], int n) {
        int min = INT_MAX;
        for (int i = 0; i < n; i++) if (a[i] < min) min = a[i];
        return min;
    }
    static long lmin(long a[], int n) {
        long min = LLONG_MAX;
        for (int i = 0; i < n; i++) if (a[i] < min) min = a[i];
        return min;
    }
    static int imax(int a[], int n) {
        int max = INT_MIN;
        for (int i = 0; i < n; i++) if (a[i] > max) max = a[i];
        return max;
    }
    static long lmax(long a[], int n) {
        long max = LLONG_MIN;
        for (int i = 0; i < n; i++) if (a[i] > max) max = a[i];
        return max;
    }
    static bool ibs(int a[], int n, int toFind) {
        sort(a, a + n);
        int min = 0, max = n - 1;
        bool found = false;
        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (a[mid] == toFind) found = true;
            else if (toFind > a[mid]) min = mid + 1;
            else max = mid - 1;
        }
        return found;
    }
    static bool lbs(long a[], int n, long toFind) {
        sort(a, a + n);
        int min = 0, max = n - 1;
        bool found = false;
        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (a[mid] == toFind) found = true;
            else if (toFind > a[mid]) min = mid + 1;
            else max = mid - 1;
        }
        return found;
    }
    static int stb(string s) {
        int sum = 0, k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += (s[i] - '0') * pow(2, k++);
        }
        return sum;
    }
};

void Main::solve() {
    int a = ni();
    int b = ni();
    cout << max(0, a - 2 * b) << endl;
}

int main() {
    Main().solve();
    return 0;
}
// End of Code
