import sys
from collections import defaultdict

mod = int(1e9) + 7

def rec(v, parent):
    res = 1
    for next in to[v]:
        if next == parent:
            continue
        res += rec(next, v)
    dp[v] = res
    return res

def modpow(x, y):
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y - 1) % mod
    tmp = modpow(x, y // 2)
    return tmp * tmp % mod

class FastScanner:
    def __init__(self, f):
        self.f = f
        self.words = []

    def next(self):
        while len(self.words) == 0:
            line = self.f.readline().strip()
            if line == '':
                return ''
            self.words = line.split()
        return self.words.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextFloat(self):
        return float(self.next())

    def nextLine(self):
        line = self.f.readline().strip()
        return line

    def nextIntArray(self, n):
        return [self.nextInt() for _ in range(n)]

    def nextLongArray(self, n):
        return [self.nextLong() for _ in range(n)]

    def nextFloatArray(self, n):
        return [self.nextFloat() for _ in range(n)]

fs = FastScanner(sys.stdin)
N = fs.nextInt()
to = defaultdict(list)
dp = [0] * N
edges = []

for _ in range(N - 1):
    A = fs.nextInt() - 1
    B = fs.nextInt() - 1
    to[A].append(B)
    to[B].append(A)
    edges.append((B, A))

rec(0, -1)
mulsum = 0

for e in edges:
    candidate1, candidate2 = e
    child = candidate1 if dp[candidate1] > dp[candidate2] else candidate2
    a = dp[child]
    b = N - a
    mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
    mulsum = (mulsum + mul) % mod
cases = modpow(2, N)
PN = (mulsum + (cases - 1 + mod) % mod) % mod
BN = N * modpow(2, N - 1) % mod
WN = (PN - BN + mod) % mod
ans = WN * modpow(cases, mod - 2) % mod

print(ans)
# End of Code
