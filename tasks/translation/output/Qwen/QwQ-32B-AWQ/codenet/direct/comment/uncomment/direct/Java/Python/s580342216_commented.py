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
        while N > 0:
            N = N // K
            length += 1
        print(length)

class LCS:
    def __init__(self):
        self.dp = []

    def lcs(self, A, B):
        sz_a = len(A)
        sz_b = len(B)
        self.dp = [[0]*(sz_b+1) for _ in range(sz_a+1)]

        for i in range(1, sz_a+1):
            for j in range(1, sz_b+1):
                if A[i-1] == B[j-1]:
                    self.dp[i][j] = self.dp[i-1][j-1] + 1
                else:
                    self.dp[i][j] = max(self.dp[i-1][j], self.dp[i][j-1])
        return self.dp[sz_a][sz_b]

    def getLCS(self, X, Y):
        m = len(X)
        n = len(Y)
        index = self.dp[m][n]
        lcs = [''] * index
        i = m
        j = n
        current = index -1
        while i > 0 and j > 0:
            if X[i-1] == Y[j-1]:
                lcs[current] = X[i-1]
                current -= 1
                i -= 1
                j -= 1
            else:
                if self.dp[i-1][j] > self.dp[i][j-1]:
                    i -= 1
                else:
                    j -= 1
        return ''.join(lcs)

if __name__ == "__main__":
    Solution()
# End of Code
