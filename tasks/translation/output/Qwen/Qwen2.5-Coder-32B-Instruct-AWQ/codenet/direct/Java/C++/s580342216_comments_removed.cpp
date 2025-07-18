#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    Solution() {
        std::string line;
        while (std::getline(std::cin, line)) {
            run_case(line);
        }
    }

private:
    void run_case(const std::string& line) {
        std::istringstream iss(line);
        int N, K;
        iss >> N >> K;

        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }

        std::cout << len << std::endl;
    }

    std::vector<int> strToIntArray(const std::string& str) {
        std::istringstream iss(str);
        std::vector<int> res;
        int val;
        while (iss >> val) {
            res.push_back(val);
        }
        return res;
    }
};

class LCS {
public:
    int lcs(const std::string& A, const std::string& B) {
        int sz_a = A.length(), sz_b = B.length();
        dp.resize(sz_a + 1, std::vector<int>(sz_b + 1, 0));

        for (int i = 1; i <= sz_a; i++) {
            for (int j = 1; j <= sz_b; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[sz_a][sz_b];
    }

    std::string getLCS(const std::string& X, const std::string& Y) {
        int m = X.length();
        int n = Y.length();

        int index = dp[m][n];
        std::vector<char> lcs(index);

        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs[index - 1] = X[i - 1];
                i--;
                j--;
                index--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return std::string(lcs.begin(), lcs.end());
    }

private:
    std::vector<std::vector<int>> dp;
};

int main() {
    new Solution();
    return 0;
}
// End of Code
