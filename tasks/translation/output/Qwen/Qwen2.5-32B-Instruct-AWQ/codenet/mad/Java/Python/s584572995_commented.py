mod = 10**9 + 7

def modpow(x, y):
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y-1) % mod
    tmp = modpow(x, y // 2)
    return tmp * tmp % mod

def rec(v, parent):
    res = 1
    for next in to[v]:
        if next == parent:
            continue
        res += rec(next, v)
    dp[v] = res
    return res

class FastScanner:
    def __init__(self, in_stream):
        self.reader = in_stream
        self.tokenizer = None

    def next(self):
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = self.reader.readline().split()
        return self.tokenizer.pop(0)

    def nextLine(self):
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            return self.reader.readline().strip()
        return self.tokenizer.nextToken("\n")

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

import sys
fs = FastScanner(sys.stdin)
N = fs.nextInt()
to = [[] for _ in range(N)]
edges = [[0, 0] for _ in range(N-1)]
for i in range(N-1):
    A = fs.nextInt() - 1
    B = fs.nextInt() - 1
    to[A].append(B)
    to[B].append(A)
    edges[i][0] = B
    edges[i][1] = A

dp = [0] * N
rec(0, -1)
mulsum = 0
for e in edges:
    candidate1 = e[0]
    candidate2 = e[1]
    child = candidate1 if dp[candidate1] <= dp[candidate2] else candidate2
    a = dp[child]
    b = N - a
    mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
    mulsum += mul
    mulsum %= mod

cases = modpow(2, N)
PN = (mulsum + (cases - 1 + mod) % mod) % mod
BN = N * modpow(2, N-1) % mod
WN = (PN - BN + mod) % mod
ans = WN * modpow(cases, mod-2) % mod

print(ans)
# End of Code
