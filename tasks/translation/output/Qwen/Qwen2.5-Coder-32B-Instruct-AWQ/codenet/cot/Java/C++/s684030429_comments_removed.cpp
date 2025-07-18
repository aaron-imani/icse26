#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

class Main {
public:
    int max = 0, cur = 0;

    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }

    Main() {
        try {
            // No need to initialize cin, it's already ready for input
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    }

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
        getline(cin, a);
        return a;
    }

    vector<string> nst(string s) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void ia(vector<int> &a) {
        for (int i = 0; i < a.size(); i++)
            cin >> a[i];
    }

    void la(vector<long> &a) {
        for (int i = 0; i < a.size(); i++)
            cin >> a[i];
    }

    void fa(vector<float> &a) {
        for (int i = 0; i < a.size(); i++)
            cin >> a[i];
    }

    void da(vector<double> &a) {
        for (int i = 0; i < a.size(); i++)
            cin >> a[i];
    }

    void sa(vector<string> &a, bool empty) {
        if (empty) {
            for (int i = 0; i < a.size(); i++)
                a[i] = "";
        } else {
            for (int i = 0; i < a.size(); i++)
                a[i] = ns();
        }
    }

    void ida(vector<vector<int>> &a, int n, int m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
    }

    void lda(vector<vector<long>> &a, int n, int m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
    }

    void dda(vector<vector<double>> &a, int n, int m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
    }

    int stoi(string s) {
        return std::stoi(s);
    }

    double stod(string s) {
        return std::stod(s);
    }

    long lmin(vector<long> a) {
        long min = LONG_MAX;
        for (int i = 0; i < a.size(); i++)
            if (min > a[i])
                min = a[i];
        return min;
    }

    int imin(vector<int> a) {
        int min = INT_MAX;
        for (int i = 0; i < a.size(); i++)
            if (min > a[i])
                min = a[i];
        return min;
    }

    long lmax(vector<long> a) {
        long max = LONG_MIN;
        for (int i = 0; i < a.size(); i++)
            if (max < a[i])
                max = a[i];
        return max;
    }

    int imax(vector<int> a) {
        int max = INT_MIN;
        for (int i = 0; i < a.size(); i++)
            if (max < a[i])
                max = a[i];
        return max;
    }

    bool ibs(vector<int> &a, int toFind) {
        sort(a.begin(), a.end());
        int min = 0;
        int max = a.size() - 1;
        bool found = false;

        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (a[mid] == toFind)
                found = true;
            else if (toFind > a[mid])
                min = mid + 1;
            else
                max = mid - 1;
        }
        return found;
    }

    bool lbs(vector<long> &a, long toFind) {
        sort(a.begin(), a.end());
        int min = 0;
        int max = a.size() - 1;
        bool found = false;

        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (a[mid] == toFind)
                found = true;
            else if (toFind > a[mid])
                min = mid + 1;
            else
                max = mid - 1;
        }
        return found;
    }

    int stb(string s) {
        int sum = 0;
        int k = 0;
        for (int i = s.length() - 1; i >= 0; i--)
            sum += stoi(s.substr(i, 1)) * pow(2, k++);
        return sum;
    }
};

int main() {
    Main().solve();
    return 0;
}
// End of Code
