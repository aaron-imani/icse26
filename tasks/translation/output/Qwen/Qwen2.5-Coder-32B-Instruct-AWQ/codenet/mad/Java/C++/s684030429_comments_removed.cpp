#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <sstream>

class Main {
private:
    std::istream& sc = std::cin;
    int max = 0, cur = 0;

public:
    void solve() {
        int a = ni();
        int b = ni();

        std::cout << std::max(0, a - 2 * b) << std::endl;
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

    std::string ns() {
        std::string a;
        std::getline(sc, a);
        return a;
    }

    void ia(std::vector<int>& a) {
        for (size_t i = 0; i < a.size(); i++)
            a[i] = ni();
    }

    void la(std::vector<long>& a) {
        for (size_t i = 0; i < a.size(); i++)
            a[i] = nl();
    }

    void fa(std::vector<float>& a) {
        for (size_t i = 0; i < a.size(); i++)
            a[i] = nf();
    }

    void da(std::vector<double>& a) {
        for (size_t i = 0; i < a.size(); i++)
            a[i] = nd();
    }

    void sa(std::vector<std::string>& a, bool empty) {
        if (empty) {
            for (size_t i = 0; i < a.size(); i++)
                a[i] = "";
        } else {
            for (size_t i = 0; i < a.size(); i++)
                a[i] = ns();
        }
    }

    void ida(std::vector<std::vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = ni();
            }
        }
    }

    void lda(std::vector<std::vector<long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nl();
            }
        }
    }

    void dda(std::vector<std::vector<double>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nd();
            }
        }
    }

    int stoi(const std::string& s) {
        return std::stoi(s);
    }

    double stod(const std::string& s) {
        return std::stod(s);
    }

    long lmin(const std::vector<long>& a) {
        long min = LONG_MAX;
        for (size_t i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    int imin(const std::vector<int>& a) {
        int min = INT_MAX;
        for (size_t i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    long lmax(const std::vector<long>& a) {
        long max = LONG_MIN;
        for (size_t i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    int imax(const std::vector<int>& a) {
        int max = INT_MIN;
        for (size_t i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    bool ibs(std::vector<int>& a, int toFind) {
        std::sort(a.begin(), a.end());
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

    bool lbs(std::vector<long>& a, long toFind) {
        std::sort(a.begin(), a.end());
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

    int stb(const std::string& s) {
        int sum = 0;
        int k = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += std::stoi(s.substr(i, 1)) * std::pow(2, k++);
        }
        return sum;
    }
};

int main() {
    Main().solve();
    return 0;
}
// End of Code
