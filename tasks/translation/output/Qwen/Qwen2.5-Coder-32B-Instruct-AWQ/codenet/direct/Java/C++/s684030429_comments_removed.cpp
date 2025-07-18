#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>

using namespace std;

class Main {
private:
    istream& sc;
    int max_val = 0, cur_val = 0;

public:
    Main() : sc(cin) {}

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
        string a;
        getline(sc, a);
        return a;
    }

    void ia(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = ni();
        }
    }

    void la(vector<long>& a) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = nl();
        }
    }

    void fa(vector<float>& a) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = nf();
        }
    }

    void da(vector<double>& a) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = nd();
        }
    }

    void sa(vector<string>& a, bool empty) {
        if (empty) {
            for (int i = 0; i < a.size(); i++) {
                a[i] = "";
            }
        } else {
            for (int i = 0; i < a.size(); i++) {
                a[i] = ns();
            }
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

    int stoi(const string& s) {
        return std::stoi(s);
    }

    double stod(const string& s) {
        return std::stod(s);
    }

    long lmin(const vector<long>& a) {
        long min_val = LONG_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min_val > a[i]) {
                min_val = a[i];
            }
        }
        return min_val;
    }

    int imin(const vector<int>& a) {
        int min_val = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min_val > a[i]) {
                min_val = a[i];
            }
        }
        return min_val;
    }

    long lmax(const vector<long>& a) {
        long max_val = LONG_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max_val < a[i]) {
                max_val = a[i];
            }
        }
        return max_val;
    }

    int imax(const vector<int>& a) {
        int max_val = INT_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max_val < a[i]) {
                max_val = a[i];
            }
        }
        return max_val;
    }

    bool ibs(vector<int>& a, int toFind) {
        sort(a.begin(), a.end());
        int min_val = 0;
        int max_val = a.size() - 1;
        bool found = false;

        while (min_val <= max_val && !found) {
            int mid = min_val + (max_val - min_val) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                min_val = mid + 1;
            } else {
                max_val = mid - 1;
            }
        }
        return found;
    }

    bool lbs(vector<long>& a, long toFind) {
        sort(a.begin(), a.end());
        int min_val = 0;
        int max_val = a.size() - 1;
        bool found = false;

        while (min_val <= max_val && !found) {
            int mid = min_val + (max_val - min_val) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                min_val = mid + 1;
            } else {
                max_val = mid - 1;
            }
        }
        return found;
    }

    int stb(const string& s) {
        int sum = 0;
        int k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += stoi(s.substr(i, 1)) * pow(2, k++);
        }
        return sum;
    }
};

int main() {
    Main main_instance;
    main_instance.solve();
    return 0;
}
// End of Code
