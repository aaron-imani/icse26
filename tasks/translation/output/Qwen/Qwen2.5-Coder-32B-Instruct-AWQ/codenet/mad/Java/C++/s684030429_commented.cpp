#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Main {
private:
    int maxVal = 0, cur = 0;

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
        string a;
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, a);
        return a;
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
        long minVal = LONG_MAX;
        for (long i : a) {
            if (minVal > i) {
                minVal = i;
            }
        }
        return minVal;
    }

    int imin(const vector<int>& a) {
        int minVal = INT_MAX;
        for (int i : a) {
            if (minVal > i) {
                minVal = i;
            }
        }
        return minVal;
    }

    long lmax(const vector<long>& a) {
        long maxVal = LONG_MIN;
        for (long i : a) {
            if (maxVal < i) {
                maxVal = i;
            }
        }
        return maxVal;
    }

    int imax(const vector<int>& a) {
        int maxVal = INT_MIN;
        for (int i : a) {
            if (maxVal < i) {
                maxVal = i;
            }
        }
        return maxVal;
    }

    bool ibs(vector<int>& a, int toFind) {
        sort(a.begin(), a.end());
        int minVal = 0;
        int maxVal = a.size() - 1;
        bool found = false;

        while (minVal <= maxVal && !found) {
            int mid = minVal + (maxVal - minVal) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                minVal = mid + 1;
            } else {
                maxVal = mid - 1;
            }
        }
        return found;
    }

    bool lbs(vector<long>& a, long toFind) {
        sort(a.begin(), a.end());
        int minVal = 0;
        int maxVal = a.size() - 1;
        bool found = false;

        while (minVal <= maxVal && !found) {
            int mid = minVal + (maxVal - minVal) / 2;
            if (a[mid] == toFind) {
                found = true;
            } else if (toFind > a[mid]) {
                minVal = mid + 1;
            } else {
                maxVal = mid - 1;
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

public:
    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }
};

int main() {
    Main mainObj;
    mainObj.solve();
    return 0;
}
// End of Code
