MOD = int(1e9) + 7

def rec(v, parent):
    res = 1
    for next_v in to[v]:
        if next_v == parent:
            continue
        res += rec(next_v, v)
    dp[v] = res
    return res

def modpow(x, y):
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y - 1) % MOD
    tmp = modpow(x, y // 2)
    return tmp * tmp % MOD

import sys
from collections import defaultdict

input = sys.stdin.read
data = input().split()

N = int(data[0])
index = 1
to = defaultdict(list)
edges = []

for _ in range(N - 1):
    A = int(data[index]) - 1
    B = int(data[index + 1]) - 1
    to[A].append(B)
    to[B].append(A)
    edges.append((B, A))
    index += 2

dp = [0] * N
rec(0, -1)

mulsum = 0
for e in edges:
    candidate1, candidate2 = e
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
