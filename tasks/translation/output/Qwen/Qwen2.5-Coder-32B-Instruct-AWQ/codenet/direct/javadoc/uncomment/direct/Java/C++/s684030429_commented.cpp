#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
        ios::sync_with_stdio(false);
        cin.tie(0);
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
        for (int& x : a) {
            cin >> x;
        }
    }

    // input a long array
    void la(vector<long long>& a) {
        for (long long& x : a) {
            cin >> x;
        }
    }

    // input a float array
    void fa(vector<float>& a) {
        for (float& x : a) {
            cin >> x;
        }
    }

    // input a double array
    void da(vector<double>& a) {
        for (double& x : a) {
            cin >> x;
        }
    }

    // input a string array
    void sa(vector<string>& a) {
        for (string& s : a) {
            cin >> s;
        }
    }

    // input two dimensional integer array
    void ida(vector<vector<int>>& a) {
        for (vector<int>& row : a) {
            for (int& x : row) {
                cin >> x;
            }
        }
    }

    // input two dimensional long array
    void lda(vector<vector<long long>>& a) {
        for (vector<long long>& row : a) {
            for (long long& x : row) {
                cin >> x;
            }
        }
    }

    // input two dimensional double array
    void dda(vector<vector<double>>& a) {
        for (vector<double>& row : a) {
            for (double& x : row) {
                cin >> x;
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
        return *min_element(a.begin(), a.end());
    }

    // find minimum in a integer array
    int imin(const vector<int>& a) {
        return *min_element(a.begin(), a.end());
    }

    // find maximum in a long array
    long long lmax(const vector<long long>& a) {
        return *max_element(a.begin(), a.end());
    }

    // find maximum in an integer array
    int imax(const vector<int>& a) {
        return *max_element(a.begin(), a.end());
    }

    // check whether an element is present in an integer array by binary search
    bool ibs(vector<int>& a, int toFind) {
        sort(a.begin(), a.end());
        return binary_search(a.begin(), a.end(), toFind);
    }

    // check whether an element is present in a long array
    bool lbs(vector<long long>& a, long long toFind) {
        sort(a.begin(), a.end());
        return binary_search(a.begin(), a.end(), toFind);
    }

    int stb(const string& s) {
        int sum = 0;
        int k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += (s[i] - '0') * pow(2, k++);
        }
        return sum;
    }

public:
    static void run() {
        Main mainInstance;
        mainInstance.solve();
    }
};

int main() {
    Main::run();
    return 0;
}
// End of Code
