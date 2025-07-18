#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Main {
private:
    int max_val = 0, cur = 0;

public:
    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }

    Main() {}

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

    void ia(vector<int>& a) {
        for (int& i : a) {
            cin >> i;
        }
    }

    void la(vector<long>& a) {
        for (long& i : a) {
            cin >> i;
        }
    }

    void fa(vector<float>& a) {
        for (float& i : a) {
            cin >> i;
        }
    }

    void da(vector<double>& a) {
        for (double& i : a) {
            cin >> i;
        }
    }

    void sa(vector<string>& a, bool empty) {
        if (empty) {
            for (string& i : a) {
                i = "";
            }
        } else {
            for (string& i : a) {
                getline(cin, i);
            }
        }
    }

    void ida(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    void lda(vector<vector<long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    void dda(vector<vector<double>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
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
        for (long i : a) {
            if (min_val > i) {
                min_val = i;
            }
        }
        return min_val;
    }

    int imin(const vector<int>& a) {
        int min_val = INT_MAX;
        for (int i : a) {
            if (min_val > i) {
                min_val = i;
            }
        }
        return min_val;
    }

    long lmax(const vector<long>& a) {
        long max_val = LONG_MIN;
        for (long i : a) {
            if (max_val < i) {
                max_val = i;
            }
        }
        return max_val;
    }

    int imax(const vector<int>& a) {
        int max_val = INT_MIN;
        for (int i : a) {
            if (max_val < i) {
                max_val = i;
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
    Main().solve();
    return 0;
}
// End of Code
