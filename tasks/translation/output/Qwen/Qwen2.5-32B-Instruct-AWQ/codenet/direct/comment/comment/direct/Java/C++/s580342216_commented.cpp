#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
        stringstream ss(line);
        int N, K;
        ss >> N >> K;

        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }

        cout << len << endl;
    }

    vector<int> strToIntArray(const string& str) {
        stringstream ss(str);
        vector<int> res;
        int val;
        while (ss >> val) {
            res.push_back(val);
        }
        return res;
    }
};

class LCS {
public:
    int lcs(const string& A, const string& B) {
        int sz_a = A.size(), sz_b = B.size();
        vector<vector<int>> dp(sz_a + 1, vector<int>(sz_b + 1));

        for (int i = 0; i <= sz_a; i++) dp[i][0] = 0;
        for (int j = 0; j <= sz_b; j++) dp[0][j] = 0;

        for (int i = 1; i <= sz_a; i++) {
            for (int j = 1; j <= sz_b; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[sz_a][sz_b];
    }

    string getLCS(const string& X, const string& Y) {
        int m = X.size();
        int n = Y.size();
        int index = dp[m][n];
        int temp = index;

        char lcs[index + 1];
        lcs[index] = '\0';

        int i = m;
        int j = n;
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

        return string(lcs, temp + 1);
    }

private:
    vector<vector<int>> dp;
};

int main() {
    Solution solution;
    // End of Code
