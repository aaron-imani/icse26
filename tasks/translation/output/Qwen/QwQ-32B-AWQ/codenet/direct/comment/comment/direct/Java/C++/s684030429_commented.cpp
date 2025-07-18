#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cmath>

struct Main {
    std::istream& sc;
    int max = 0, cur = 0;

    Main() : sc(std::cin) {}

    int ni() {
        int a;
        sc >> a;
        return a;
    }

    long long nl() {
        long long a;
        sc >> a;
        return a;
    }

    float nf() {
        float a;
        sc >> a;
        return a;
    }

    double nd() {
        double a;
        sc >> a;
        return a;
    }

    std::string ns() {
        std::string s;
        std::getline(sc, s);
        return s;
    }

    std::istringstream nst(std::string s) {
        std::istringstream iss(s);
        return iss;
    }

    void ia(int a[], int n) {
        for (int i = 0; i < n; i++) {
            sc >> a[i];
        }
    }

    void la(long a[], int n) {
        for (int i = 0; i < n; i++) {
            sc >> a[i];
        }
    }

    void fa(float a[], int n) {
        for (int i = 0; i < n; i++) {
            sc >> a[i];
        }
    }

    void da(double a[], int n) {
        for (int i = 0; i < n; i++) {
            sc >> a[i];
        }
    }

    void sa(std::string a[], bool empty, int n) {
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

    void ida(int* a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i * m + j] = ni();
            }
        }
    }

    void lda(long* a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i * m + j] = nl();
            }
        }
    }

    void dda(double* a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i * m + j] = nd();
            }
        }
    }

    int imin(int a[], int n) {
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    long lmin(long a[], int n) {
        long min = std::numeric_limits<long>::max();
        for (int i = 0; i < n; i++) {
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    int imax(int a[], int n) {
        int max = std::numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    long lmax(long a[], int n) {
        long max = std::numeric_limits<long>::min();
        for (int i = 0; i < n; i++) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    bool ibs(int a[], int n, int toFind) {
        std::sort(a, a + n);
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

    bool lbs(long a[], int n, long toFind) {
        std::sort(a, a + n);
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

    int stb(std::string s) {
        int sum = 0;
        for (char c : s) {
            sum <<= 1;
            sum += (c - '0');
        }
        return sum;
    }

    void solve() {
        int a = ni();
        int b = ni();
        std::cout << std::max(0, a - 2 * b) << std::endl;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}
// End of Code
