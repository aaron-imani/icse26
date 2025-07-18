#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Main {
public:
    int max = 0, cur = 0;

    // actual logic
    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }

    // constructor
    Main() {}

    // main method
    static void main() {
        Main().solve();
    }

    // utility methods
    // input an integer from cin
    int ni() {
        int a;
        cin >> a;
        return a;
    }

    // input a long from cin
    long nl() {
        long a;
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

    // converts a string to stringstream
    stringstream nst(string s) {
        return stringstream(s);
    }

    // input an integer array
    void ia(vector<int>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = ni();
    }

    // input a long array
    void la(vector<long>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nl();
    }

    // input a float array
    void fa(vector<float>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nf();
    }

    // input a double array
    void da(vector<double>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nd();
    }

    // input a string array either with all empty input or from cin
    void sa(vector<string>& a, bool empty) {
        if (empty) {
            for (int i = 0; i < a.size(); i++)
                a[i] = "";
        } else {
            for (int i = 0; i < a.size(); i++)
                a[i] = ns();
        }
    }

    // input two-dimensional integer array
    void ida(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = ni();
            }
        }
    }

    // input two-dimensional long array
    void lda(vector<vector<long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nl();
            }
        }
    }

    // input two-dimensional double array
    void dda(vector<vector<double>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nd();
            }
        }
    }

    // convert string to integer
    int stoi(string s) {
        return stoi(s);
    }

    // convert string to double
    double stod(string s) {
        return stod(s);
    }

    // find minimum in a long array
    long lmin(vector<long>& a) {
        long min = LONG_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    // find minimum in an integer array
    int imin(vector<int>& a) {
        int min = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    // find maximum in a long array
    long lmax(vector<long>& a) {
        long max = LONG_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    // find maximum in an integer array
    int imax(vector<int>& a) {
        int max = INT_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    // check whether an element is present in an integer array by binary search
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

    // check whether an element is present in a long array
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
};

int main() {
    Main::main();
    return 0;
}
// End of Code
