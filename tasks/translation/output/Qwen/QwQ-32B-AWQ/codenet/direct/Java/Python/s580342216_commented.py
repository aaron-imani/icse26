class LCS:
    def __init__(self):
        self.dp = None

    def lcs(self, A, B):
        sz_a = len(A)
        sz_b = len(B)
        self.dp = [[0]*(sz_b+1) for _ in range(sz_a+1)]

        for i in range(sz_a + 1):
            self.dp[i][0] = 0
        for j in range(sz_b + 1):
            self.dp[0][j] = 0

        for i in range(1, sz_a + 1):
            for j in range(1, sz_b + 1):
                if A[i-1] == B[j-1]:
                    self.dp[i][j] = self.dp[i-1][j-1] + 1
                else:
                    self.dp[i][j] = max(self.dp[i-1][j], self.dp[i][j-1])
        return self.dp[sz_a][sz_b]

    def getLCS(self, X, Y):
        m = len(X)
        n = len(Y)
        index = self.dp[m][n]
        temp = index
        lcs = [''] * (index + 1)
        i = m
        j = n
        while i > 0 and j > 0:
            if X[i-1] == Y[j-1]:
                lcs[index-1] = X[i-1]
                i -= 1
                j -= 1
                index -= 1
            else:
                if self.dp[i-1][j] > self.dp[i][j-1]:
                    i -= 1
                else:
                    j -= 1
        return ''.join(lcs[:temp])

import sys

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        N = int(parts[0])
        K = int(parts[1])
        length = 0
        n = N
        while n > 0:
            n = n // K
            length += 1
        print(length)

if __name__ == "__main__":
    main()
# End of Code
