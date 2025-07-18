#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution();
private:
    void run_case(const string& line);
    vector<int> strToIntArray(const string& str);
};

Solution::Solution() {
    string line;
    while (getline(cin, line)) {
        run_case(line);
    }
}

void Solution::run_case(const string& line) {
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

vector<int> Solution::strToIntArray(const string& str) {
    vector<int> res;
    istringstream iss(str);
    int val;
    while (iss >> val) {
        res.push_back(val);
    }
    return res;
}

class LCS {
private:
    vector<vector<int>> dp;
public:
    int lcs(const string& A, const string& B);
    string getLCS(const string& X, const string& Y);
};

int LCS::lcs(const string& A, const string& B) {
    int sz_a = A.length();
    int sz_b = B.length();
    dp = vector<vector<int>>(sz_a + 1, vector<int>(sz_b + 1, 0));

    for (int i = 0; i <= sz_a; ++i) dp[i][0] = 0;
    for (int j = 0; j <= sz_b; ++j) dp[0][j] = 0;

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

string LCS::getLCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    int index = dp[m][n];
    int temp = index;

    char lcs_str[index + 1];
    lcs_str[index] = '\0';
    index--;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs_str[index--] = X[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return string(lcs_str);
}

int main() {
    Solution solution;
    return 0;
}
// End of Code
