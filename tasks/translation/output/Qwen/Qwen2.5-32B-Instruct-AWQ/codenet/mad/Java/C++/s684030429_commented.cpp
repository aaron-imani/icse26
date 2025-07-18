#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Main {
public:
    std::istream& sc;
    int max = 0, cur = 0;

    // actual logic
    void solve() {
        int a = ni();
        int b = ni();

        std::cout << std::max(0, a - 2 * b) << std::endl;
    }

    // constructor
    Main(std::istream& input) : sc(input) {}

    // main method
    static void main() {
        Main main(std::cin);
        main.solve();
    }

    // Utility methods
    // input an integer from scanner
    int ni() {
        int a;
        sc >> a;
        return a;
    }

    // input a long from scanner
    long nl() {
        long a;
        sc >> a;
        return a;
    }

    // input a float from scanner
    float nf() {
        float a;
        sc >> a;
        return a;
    }

    // input a double from scanner
    double nd() {
        double a;
        sc >> a;
        return a;
    }

    // input a sentence from scanner
    std::string ns() {
        std::string s;
        std::getline(sc, s);
        return s;
    }

    // input an integer array
    void ia(std::vector<int>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = ni();
    }

    // input a long array
    void la(std::vector<long>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nl();
    }

    // input a float array
    void fa(std::vector<float>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nf();
    }

    // input a double array
    void da(std::vector<double>& a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = nd();
    }

    // input a string array either with all empty input or from scanner
    void sa(std::vector<std::string>& a, bool empty) {
        if (empty) {
            for (int i = 0; i < a.size(); i++)
                a[i] = "";
        } else {
            for (int i = 0; i < a.size(); i++)
                a[i] = ns();
        }
    }

    // input two dimensional integer array
    void ida(std::vector<std::vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = ni();
            }
        }
    }

    // input two dimensional long array
    void lda(std::vector<std::vector<long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nl();
            }
        }
    }

    // input two dimensional double array
    void dda(std::vector<std::vector<double>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nd();
            }
        }
    }

    // convert string to integer
    int stoi(const std::string& s) {
        return std::stoi(s);
    }

    // convert string to double
    double stod(const std::string& s) {
        return std::stod(s);
    }

    // find minimum in a long array
    long lmin(const std::vector<long>& a) {
        long min = std::numeric_limits<long>::max();
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    // find minimum in an integer array
    int imin(const std::vector<int>& a) {
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }

    // find maximum in a long array
    long lmax(const std::vector<long>& a) {
        long max = std::numeric_limits<long>::min();
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    // find maximum in an integer array
    int imax(const std::vector<int>& a) {
        int max = std::numeric_limits<int>::min();
        for (int i = 0; i < a.size(); i++) {
            if (max < a[i])
                max = a[i];
        }
        return max;
    }

    // check whether an element is present in an integer array by binary search
    bool ibs(const std::vector<int>& a, int toFind) {
        std::vector<int> sortedA = a;
        std::sort(sortedA.begin(), sortedA.end());
        int min = 0;
        int max = a.size() - 1;
        bool found = false;

        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (sortedA[mid] == toFind) {
                found = true;
            } else if (toFind > sortedA[mid]) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return found;
    }

    // check whether an element is present in a long array
    bool lbs(const std::vector<long>& a, long toFind) {
        std::vector<long> sortedA = a;
        std::sort(sortedA.begin(), sortedA.end());
        int min = 0;
        int max = a.size() - 1;
        bool found = false;

        while (min <= max && !found) {
            int mid = min + (max - min) / 2;
            if (sortedA[mid] == toFind) {
                found = true;
            } else if (toFind > sortedA[mid]) {
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
            sum += stoi(s.substr(i, 1)) * std::pow(2, k++);
        }
        return sum;
    }
};

int main() {
    Main::main();
    return 0;
}
// End of Code
