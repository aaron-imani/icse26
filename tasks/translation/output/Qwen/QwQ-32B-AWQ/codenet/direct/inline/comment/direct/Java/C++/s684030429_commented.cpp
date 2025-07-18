#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Main {
    int max = 0, cur = 0;

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

    istringstream nst(const string& s) {
        return istringstream(s);
    }

    void ia(int a[], int n) {
        for (int i = 0; i < n; ++i) {
            a[i] = ni();
        }
    }

    void la(long a[], int n) {
        for (int i = 0; i < n; ++i) {
            a[i] = nl();
        }
    }

    void fa(float a[], int n) {
        for (int i = 0; i < n; ++i) {
            a[i] = nf();
        }
    }

    void da(double a[], int n) {
        for (int i = 0; i < n; ++i) {
            a[i] = nd();
        }
    }

    void sa(string a[], int n, bool empty) {
        if (empty) {
            for (int i = 0; i < n; ++i) {
                a[i] = "";
            }
        } else {
            for (int i = 0; i < n; ++i) {
                a[i] = ns();
            }
        }
    }

    void ida(int a[][/* size */], int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = ni();
            }
        }
    }

    void solve() {
        int a = ni();
        int b = ni();
        cout << max(0, a - 2 * b) << endl;
    }
};

int main() {
    Main().solve();
    return 0;
}
// End of Code
