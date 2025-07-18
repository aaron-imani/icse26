#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution() {
        string line;
        while (getline(cin, line)) {
            run_case(line);
        }
    }

private:
    void run_case(const string& line) {
        istringstream iss(line);
        int N, K;
        iss >> N >> K;
        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }
        cout << len << endl;
    }
};

class LCS {
private:
    vector<vector<int>> dp;
public:
    int lcs(string A, string B) {
        int sz_a = A.size();
        int sz_b = B.size();
        dp.assign(sz_a + 1, vector<int>(sz_b + 1, 0));

        for (int i = 0; i <= sz_a; i++) dp[i][0] = 0;
        for (int j = 0; j <= sz_b; j++) dp[0][j] = 0;

        for (int i = 1; i <= sz_a; i++) {
            for (int j = 1; j <= sz_b; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[sz_a][sz_b];
    }

    string getLCS(string X, string Y) {
        int m = X.length();
        int n = Y.length();
        int index = dp[m][n];
        int temp = index;

        vector<char> lcs(index + 1);
        lcs[index] = '\0';

        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (X[i-1] == Y[j-1]) {
                lcs[index-1] = X[i-1];
                i--;
                j--;
                index--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }

        return string(lcs.begin(), lcs.end());
    }
};

int main() {
    Solution sol;
    return 0;
}
// End of Code
