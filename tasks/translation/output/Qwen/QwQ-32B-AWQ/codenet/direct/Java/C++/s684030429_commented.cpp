#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Main {
private:
    int max;
    int cur;

public:
    Main() : max(0), cur(0) {}

    void solve() {
        int a = ni();
        int b = ni();
        cout << std::max(0, a - 2 * b) << endl;
    }

    static int ni() {
        int a;
        cin >> a;
        return a;
    }

    static long long nl() {
        long long a;
        cin >> a;
        return a;
    }

    static float nf() {
        float a;
        cin >> a;
        return a;
    }

    static double nd() {
        double a;
        cin >> a;
        return a;
    }

    static string ns() {
        string s;
        getline(cin, s);
        return s;
    }

    static void ia(int a[], int size) {
        for (int i = 0; i < size; i++) {
            cin >> a[i];
        }
    }

    static void la(long a[], int size) {
        for (int i = 0; i < size; i++) {
            cin >> a[i];
        }
    }

    static void fa(float a[], int size) {
        for (int i = 0; i < size; i++) {
            cin >> a[i];
        }
    }

    static void da(double a[], int size) {
        for (int i = 0; i < size; i++) {
            cin >> a[i];
        }
    }

    static void sa(string a[], int size, bool empty) {
        if (empty) {
            for (int i = 0; i < size; i++) {
                a[i] = "";
            }
        } else {
            for (int i = 0; i < size; i++) {
                a[i] = ns();
            }
        }
    }

    static void ida(int a[][100], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    static void lda(long a[][100], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    static int stoi(const string& s) {
        return stoi(s);
    }

    static double stod(const string& s) {
        return stod(s);
    }

    static long lmin(long a[], int size) {
        long min = LLONG_MAX;
        for (int i = 0; i < size; i++) {
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    static int imin(int a[], int size) {
        int min = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    static long lmax(long a[], int size) {
        long max = LLONG_MIN;
        for (int i = 0; i < size; i++) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    static int imax(int a[], int size) {
        int max = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    static bool ibs(int a[], int size, int toFind) {
        sort(a, a + size);
        int min = 0;
        int max_idx = size - 1;
        bool found = false;
        while (min <= max_idx && !found) {
            int mid = min + (max_idx - min) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                min = mid + 1;
            } else {
                max_idx = mid - 1;
            }
        }
        return found;
    }

    static bool lbs(long a[], int size, long toFind) {
        sort(a, a + size);
        int min = 0;
        int max_idx = size - 1;
        bool found = false;
        while (min <= max_idx && !found) {
            int mid = min + (max_idx - min) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                min = mid + 1;
            } else {
                max_idx = mid - 1;
            }
        }
        return found;
    }

    static int stb(string s) {
        int sum = 0;
        int k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += stoi(s.substr(i, 1)) * pow(2, k++);
        }
        return sum;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
} // End of Code
