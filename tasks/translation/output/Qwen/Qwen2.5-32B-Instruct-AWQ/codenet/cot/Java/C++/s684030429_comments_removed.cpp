#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Main {
public:
    int max = 0, cur = 0;
    istream& sc;

    Main(istream& input) : sc(input) {}

    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }

    int ni() {
        int a;
        sc >> a;
        return a;
    }

    long nl() {
        long a;
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

    string ns() {
        string s;
        sc >> s;
        return s;
    }

    void ia(vector<int>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = ni();
    }

    void la(vector<long>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nl();
    }

    void fa(vector<float>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nf();
    }

    void da(vector<double>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nd();
    }

    void sa(vector<string>& a, bool empty) {
        if (empty) {
            for (int i = 0; i < a.size(); i++)
                a[i] = "";
        } else {
            for (int i = 0; i < a.size(); i++)
                a[i] = ns();
        }
    }

    void ida(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = ni();
            }
        }
    }

    void lda(vector<vector<long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nl();
            }
        }
    }

    void dda(vector<vector<double>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nd();
            }
        }
    }

    int stoi(string s) {
        return stoi(s);
    }

    double stod(string s) {
        return stod(s);
    }

    long lmin(vector<long>& a) {
        long min = LONG_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    int imin(vector<int>& a) {
        int min = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    long lmax(vector<long>& a) {
        long max = LONG_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    int imax(vector<int>& a) {
        istringstream input;
        Main main(input);
        main.solve();
    }
};

int main() {
    istream& input = cin;
    Main main(input);
    main.solve();
    // End of Code
}
