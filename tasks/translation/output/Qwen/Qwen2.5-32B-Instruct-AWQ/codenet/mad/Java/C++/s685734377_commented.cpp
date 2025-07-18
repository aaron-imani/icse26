#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

// FastScanner class for efficient input handling
class FastScanner {
public:
    FastScanner(std::istream& in) : in_(in) {}

    int nextInt() {
        return std::stoi(next());
    }

    std::string next() {
        while (!st_ || st_->eof()) {
            std::string line;
            std::getline(in_, line);
            st_ = std::make_unique<std::istringstream>(line);
        }
        std::string token;
        *st_ >> token;
        return token;
    }

private:
    std::istream& in_;
    std::unique_ptr<std::istringstream> st_;
};

// TaskB class for solving the problem
class TaskB {
public:
    void solve(int testNumber, FastScanner& in, std::ostream& out) {
        int n = in.nextInt();
        std::vector<std::vector<char>> a(n, std::vector<char>(n));
        long P = 37, Q = 47;
        std::vector<long> powP(n + 1), powQ(n + 1);
        powP[0] = powQ[0] = 1;
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }
        for (int i = 0; i < n; i++) {
            std::string line = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = line[j];
            }
        }

        std::vector<std::vector<long>> hashRow(n, std::vector<long>(n));
        std::vector<std::vector<long>> hashCol(n, std::vector<long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                    hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; A++) {
            for (int B = 0; B < n; B++) {
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
                }
                ans += ok ? 1 : 0;
            }
        }
        out << ans << std::endl;
    }
};

int main() {
    std::istream& inputStream = std::cin;
    std::ostream& outputStream = std::cout;
    FastScanner in(inputStream);
    TaskB solver;
    solver.solve(1, in, outputStream);
    return 0;
}

// End of Code
