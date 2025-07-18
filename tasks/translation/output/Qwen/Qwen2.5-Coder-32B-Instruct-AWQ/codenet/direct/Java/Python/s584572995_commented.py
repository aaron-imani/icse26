MOD = int(1e9) + 7

def rec(v, parent, to, dp):
    res = 1
    for next in to[v]:
        if next == parent:
            continue
        res += rec(next, v, to, dp)
    dp[v] = res
    return res

def modpow(x, y):
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y - 1) % MOD
    tmp = modpow(x, y // 2)
    return tmp * tmp % MOD

class FastScanner:
    def __init__(self, f):
        self.f = f
        self.words = []
        self.eof = False

    def next(self):
        while not self.words:
            line = self.f.readline()
            if not line:
                self.eof = True
                return None
            self.words = line.split()
        return self.words.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextFloat(self):
        return float(self.next())

    def nextLine(self):
        s = self.f.readline()
        return s if s else None

    def nextIntArray(self, n):
        return [self.nextInt() for _ in range(n)]

    def nextLongArray(self, n):
        return [self.nextLong() for _ in range(n)]

    def nextFloatArray(self, n):
        return [self.nextFloat() for _ in range(n)]

import sys
fs = FastScanner(sys.stdin)
N = fs.nextInt()
to = [[] for _ in range(N)]
edges = [[0, 0] for _ in range(N - 1)]
for i in range(N - 1):
    A = fs.nextInt() - 1
    B = fs.nextInt() - 1
    to[A].append(B)
    to[B].append(A)
    edges[i][0] = B
    edges[i][1] = A

dp = [0] * N
rec(0, -1, to, dp)
mulsum = 0
for e in edges:
    candidate1 = e[0]
    candidate2 = e[1]
    child = candidate1 if dp[candidate1] > dp[candidate2] else candidate2
    a = dp[child]
    b = N - a
    mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % MOD
    mulsum += mul
    mulsum %= MOD

cases = modpow(2, N)
PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD
BN = N * modpow(2, N - 1) % MOD
WN = (PN - BN + MOD) % MOD
ans = WN * modpow(cases, MOD - 2) % MOD

print(ans)
# End of Code
