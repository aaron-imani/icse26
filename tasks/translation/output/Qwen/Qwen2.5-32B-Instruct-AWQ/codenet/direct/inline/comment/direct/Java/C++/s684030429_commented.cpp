#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Main {
private:
    int max = 0, cur = 0;
    int ni() {
        int a;
        cin >> a;
        return a;
    }
    int nl() {
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
    int stoi(string s) {
        return stoi(s);
    }
    double stod(string s) {
        return stod(s);
    }
    long lmin(vector<long>& a) {
        long min = LONG_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i]) min = a[i];
        }
        return min;
    }
    int imin(vector<int>& a) {
        int min = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i]) min = a[i];
        }
        return min;
    }
    long lmax(vector<long>& a) {
        long max = LONG_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i]) max = a[i];
        }
        return max;
    }
    int imax(vector<int>& a) {
        int max = INT_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i]) max = a[i];
        }
        return max;
    }
    bool ibs(vector<int>& a, int toFind) {
        sort(a.begin(), a.end());
        int min = 0;
        int max = a.size() - 1;
        bool found = false;

        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return found;
    }
    bool lbs(vector<long>& a, long toFind) {
        sort(a.begin(), a.end());
        int min = 0;
        int max = a.size() - 1;
        bool found = false;

        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return found;
    }
    int stb(string s) {
        int sum = 0;
        int k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += stoi(s.substr(i, 1)) * pow(2, k++);
        }
        return sum;
    }
public:
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
