#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Main {
private:
    int max_val = 0, cur = 0;

    // actual logic
    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }

    // constructor
    Main() {
        // No need to handle exceptions for cin in C++
    }

    // utility methods
    // input an integer from cin
    int ni() {
        int a;
        cin >> a;
        return a;
    }

    // input a long from cin
    long long nl() {
        long long a;
        cin >> a;
        return a;
    }

    // input a float from cin
    float nf() {
        float a;
        cin >> a;
        return a;
    }

    // input a double from cin
    double nd() {
        double a;
        cin >> a;
        return a;
    }

    // input a sentence from cin
    string ns() {
        string s;
        getline(cin, s);
        return s;
    }

    // input an integer array
    void ia(vector<int>& a) {
        for (int& i : a) {
            cin >> i;
        }
    }

    // input a long array
    void la(vector<long long>& a) {
        for (long long& i : a) {
            cin >> i;
        }
    }

    // input a float array
    void fa(vector<float>& a) {
        for (float& i : a) {
            cin >> i;
        }
    }

    // input a double array
    void da(vector<double>& a) {
        for (double& i : a) {
            cin >> i;
        }
    }

    // input a string array either with all empty input or from cin
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

    // input two dimensional integer array
    void ida(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    // input two dimensional long array
    void lda(vector<vector<long long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    // input two dimensional double array
    void dda(vector<vector<double>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    // convert string to integer
    int stoi(const string& s) {
        return std::stoi(s);
    }

    // convert string to double
    double stod(const string& s) {
        return std::stod(s);
    }

    // find minimum in a long array
    long long lmin(const vector<long long>& a) {
        long long min_val = LLONG_MAX;
        for (long long i : a) {
            if (min_val > i) {
                min_val = i;
            }
        }
        return min_val;
    }

    // find minimum in a integer array
    int imin(const vector<int>& a) {
        int min_val = INT_MAX;
        for (int i : a) {
            if (min_val > i) {
                min_val = i;
            }
        }
        return min_val;
    }

    // find maximum in a long array
    long long lmax(const vector<long long>& a) {
        long long max_val = LLONG_MIN;
        for (long long i : a) {
            if (max_val < i) {
                max_val = i;
            }
        }
        return max_val;
    }

    // find maximum in an integer array
    int imax(const vector<int>& a) {
        int max_val = INT_MIN;
        for (int i : a) {
            if (max_val < i) {
                max_val = i;
            }
        }
        return max_val;
    }

    // check whether an element is present in an integer array by binary search
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

    // check whether an element is present in a long array
    bool lbs(vector<long long>& a, long long toFind) {
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

public:
    static void main() {
        Main main_instance;
        main_instance.solve();
    }
};

int main() {
    Main::main();
    return 0;
}
// End of Code
