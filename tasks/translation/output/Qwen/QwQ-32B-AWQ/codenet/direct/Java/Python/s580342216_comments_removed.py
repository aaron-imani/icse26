import sys

class Solution:
    def __init__(self):
        for line in sys.stdin:
            self.run_case(line.strip())
    
    def run_case(self, line):
        parts = line.split()
        N = int(parts[0])
        K = int(parts[1])
        length = 0
        while N > 0:
            N = N // K
            length +=1
        print(length)

class LCS:
    def lcs(self, A, B):
        m, n = len(A), len(B)
        self.dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if A[i-1] == B[j-1]:
                    self.dp[i][j] = self.dp[i-1][j-1] +1
                else:
                    self.dp[i][j] = max(self.dp[i-1][j], self.dp[i][j-1])
        return self.dp[m][n]
    
    def getLCS(self, X, Y):
        m, n = len(X), len(Y)
        index = self.dp[m][n]
        temp = index
        lcs = [''] * (index + 1)
        i, j = m, n
        while i > 0 and j > 0:
            if X[i-1] == Y[j-1]:
                lcs[index-1] = X[i-1]
                i -=1
                j -=1
                index -=1
            elif self.dp[i-1][j] > self.dp[i][j-1]:
                i -=1
            else:
                j -=1
        return ''.join(lcs[:temp])

if __name__ == "__main__":
    Solution()
# End of Code
