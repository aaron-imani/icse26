#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Main {
    int max = 0, cur = 0;

    int ni() { int a; cin >> a; return a; }
    long nl() { long a; cin >> a; return a; }
    float nf() { float a; cin >> a; return a; }
    double nd() { double a; cin >> a; return a; }
    string ns() { string s; getline(cin, s); return s; }

    void ia(vector<int>& a) {
        for (int& x : a) cin >> x;
    }

    void la(vector<long>& a) {
        for (long& x : a) cin >> x;
    }

    void fa(vector<float>& a) {
        for (float& x : a) cin >> x;
    }

    void da(vector<double>& a) {
        for (double& x : a) cin >> x;
    }

    void sa(vector<string>& a, bool empty) {
        if (empty) {
            for (string& s : a) s = "";
        } else {
            for (string& s : a) s = ns();
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

    long lmin(vector<long>& a) {
        long min_val = LONG_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min_val > a[i]) min_val = a[i];
        }
        return min_val;
    }

    int imin(vector<int>& a) {
        int min_val = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min_val > a[i]) min_val = a[i];
        }
        return min_val;
    }

    long lmax(vector<long>& a) {
        long max_val = LONG_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max_val < a[i]) max_val = a[i];
        }
        return max_val;
    }

    int imax(vector<int>& a) {
        int max_val = INT_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max_val < a[i]) max_val = a[i];
        }
        return max_val;
    }

    bool ibs(vector<int>& a, int toFind) {
        sort(a.begin(), a.end());
        int min = 0;
        int max_idx = a.size() - 1;
        bool found = false;
        while (min <= max_idx && !found) {
            int mid = min + (max_idx - min) / 2;
            if (a[mid] == toFind) found = true;
            else if (toFind > a[mid]) min = mid + 1;
            else max_idx = mid - 1;
        }
        return found;
    }

    bool lbs(vector<long>& a, long toFind) {
        sort(a.begin(), a.end());
        int min = 功力 = a.size() - 1;
        bool found = false;
        while (min <= max_idx && !found) {
            int mid = min + (max_idx - min) / 2;
            if (a[mid] == toFind) found = true;
            else if (toFind > a[mid]) min = mid + 1;
            else max_idx = mid - 1;
        }
        return found;
    }

    int stb(string s) {
        int sum = 0, k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int digit = stoi(s.substr(i, 1));
            sum += digit * pow(2, k++);
        }
        return sum;
    }

    void solve() {
        int a = ni();
        int b = ni();
        cout << max(0, a - 2 * b) << endl;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}
// End of Code
