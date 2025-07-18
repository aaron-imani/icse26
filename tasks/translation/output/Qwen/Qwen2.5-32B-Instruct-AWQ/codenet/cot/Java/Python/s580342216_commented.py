import sys

class Solution:
    def __init__(self):
        self.scanner = sys.stdin

        while True:
            try:
                self.run_case()
            except StopIteration:
                break

    def run_case(self):
        line = next(self.scanner).strip()
        N, K = map(int, line.split())

        length = 0
        while N > 0:
            N //= K
            length += 1

        print(length)
        return

    def str_to_int_array(self, str):
        vals = str.split()
        res = [int(val) for val in vals]
        return res

class LCS:
    def __init__(self):
        self.dp = []

    def lcs(self, A, B):
        sz_a, sz_b = len(A), len(B)
        self.dp = [[0] * (sz_b + 1) for _ in range(sz_a + 1)]

        for i in range(1, sz_a + 1):
            for j in range(1, sz_b + 1):
                if A[i - 1] == B[j - 1]:
                    self.dp[i][j] = self.dp[i - 1][j - 1] + 1
                else:
                    self.dp[i][j] = max(self.dp[i - 1][j], self.dp[i][j - 1])

        return self.dp[sz_a][sz_b]

    def get_lcs(self, X, Y):
        m, n = len(X), len(Y)
        index = self.dp[m][n]
        temp = index

        lcs = [''] * (index + 1)
        lcs[index] = '\0'

        i, j = m, n
        while i > 0 and j > 0:
            if X[i - 1] == Y[j - 1]:
                lcs[index - 1] = X[i - 1]
                i -= 1
                j -= 1
                index -= 1
            elif self.dp[i - 1][j] > self.dp[i][j - 1]:
                i -= 1
            else:
                j -= 1

        return ''.join(lcs[:temp+2])

if __name__ == "__main__":
    Solution()
# End of Code
