#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution() {
        while (cin.peek() != EOF) {
            run_case();
        }
    }

private:
    void run_case() {
        string line;
        getline(cin, line);
        int N = stoi(line.substr(0, line.find(' ')));
        int K = stoi(line.substr(line.find(' ') + 1));

        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }

        cout << len << endl;
    }

    vector<int> strToIntArray(const string& str) {
        vector<int> res;
        string temp;
        for (char c : str) {
            if (c == ' ') {
                res.push_back(stoi(temp));
                temp.clear();
            } else {
                temp += c;
            }
        }
        res.push_back(stoi(temp));
        return res;
    }
};

class LCS {
public:
    int lcs(const string& A, const string& B) {
        int sz_a = A.length(), sz_b = B.length();
        vector<vector<int>> dp(sz_a + 1, vector<int>(sz_b + 1, 0));

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
        int m = X.length();
        int n = Y.length();
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
    return 0;
}
// End of Code
