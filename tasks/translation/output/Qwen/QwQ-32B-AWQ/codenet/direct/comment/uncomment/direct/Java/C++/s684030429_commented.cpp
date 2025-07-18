#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Main {
    int max = 0, cur = 0;

    void solve() {
        int a = ni();
        int b = ni();
        cout << std::max(0, a - 2 * b) << endl;
    }

    static int ni() {
        int x;
        cin >> x;
        return x;
    }

    static long long nl() {
        long long x;
        cin >> x;
        return x;
    }

    static double nd() {
        double x;
        cin >> x;
        return x;
    }

    static float nf() {
        float x;
        cin >> x;
        return x;
    }

    static string ns() {
        string s;
        getline(cin, s);
        return s;
    }

    static vector<string> nst(const string& s) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static void ia(int a[], int size) {
        for (int i = 0; i < size; ++i) cin >> a[i];
    }

    static void la(long a[], int size) {
        for (int i = 0; i < size; ++i) cin >> a[i];
    }

    static void fa(float a[], int size) {
        for (int i = 0; i < size; ++i) cin >> a[i];
    }

    static void da(double a[], int size) {
        for (int i = 0; i < size; ++i) cin >> a[i];
    }

    static void sa(string a[], bool empty, int size) {
        if (empty) {
            for (int i = 0; i < size; ++i) a[i] = "";
        } else {
            for (int i = 0; i < size; ++i) a[i] = ns();
        }
    }

    template <int M>
    static void ida(int a[][M], int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
    }

    static int imin(int a[], int size) {
        int min = INT_MAX;
        for (int i = 0; i < size; ++i) {
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    static int imax(int a[], int size) {
        int max = INT_MIN;
        for (int i = 0; i < size; ++i) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    static long lmin(long a[], int size) {
        long min = LLONG_MAX;
        for (int i = 0; i < size; ++i) {
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    static long lmax(long a[], int size) {
        long max = LLONG_MIN;
        for (int i = 0; i < size; ++i) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    static bool ibs(int a[], int size, int toFind) {
        sort(a, a + size);
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == toFind) return true;
            else if (toFind > a[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    static bool lbs(long a[], int size, long toFind) {
        sort(a, a + size);
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == toFind) return true;
            else if (toFind > a[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    static int stb(const string& s) {
        int sum = 0, k = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            int digit = s[i] - '0';
            sum += digit * (1 << k++);
        }
        return sum;
    }
};

int main() {
    Main().solve();
    return 0;
}
// End of Code
