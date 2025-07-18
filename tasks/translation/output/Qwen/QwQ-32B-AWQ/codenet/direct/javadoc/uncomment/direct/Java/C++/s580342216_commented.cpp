#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void run_case() {
        string line;
        if (!getline(cin, line)) return;
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
public:
    vector<vector<int>> dp;
    
    int lcs(const string& A, const string& B) {
        int sz_a = A.size(), sz_b = B.size();
        dp.resize(sz_a + 1, vector<int>(sz_b + 1, 0));
        
        for (int i = 1; i <= sz_a; ++i) {
            for (int j = 1; j <= sz_b; ++j) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[sz_a][sz_b];
    }
    
    string getLCS(const string& X, const string& Y) {
        int m = X.size(), n = Y.size();
        int len = dp[m][n];
        string lcs_str;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (X[i-1] == Y[j-1]) {
                lcs_str += X[i-1];
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        sol.run_case();
    }
    return 0;
}
// End of Code
