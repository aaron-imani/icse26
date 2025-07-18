import sys

class Solution:
    def __init__(self):
        for line in sys.stdin:
            line = line.strip()
            if not line:
                continue
            self.run_case(line)
    
    def run_case(self, line):
        parts = line.split()
        N = int(parts[0])
        K = int(parts[1])
        length = 0
        n = N
        while n > 0:
            n = n // K
            length += 1
        print(length)

class LCS:
    def lcs(self, A, B):
        m = len(A)
        n = len(B)
        self.dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if A[i-1] == B[j-1]:
                    self.dp[i][j] = self.dp[i-1][j-1] + 1
                else:
                    self.dp[i][j] = max(self.dp[i-1][j], self.dp[i][j-1])
        return self.dp[m][n]
    
    def getLcs(self, X, Y):
        m = len(X)
        n = len(Y)
        index = self.dp[m][n]
        lcs = []
        i = m
        j = n
        while i > 0 and j > 0:
            if X[i-1] == Y[j-1]:
                lcs.append(X[i-1])
                i -= 1
                j -= 1
            else:
                if self.dp[i-1][j] > self.dp[i][j-1]:
                    i -= 1
                else:
                    j -= 1
        lcs.reverse()
        return ''.join(lcs)

if __name__ == "__main__":
    Solution()
# End of Code
