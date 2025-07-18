from collections import defaultdict

MOD = 10**9 + 7

def modpow(x, y):
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y - 1) % MOD
    tmp = modpow(x, y // 2)
    return tmp * tmp % MOD

def dfs(v, parent):
    res = 1
    for next_v in graph[v]:
        if next_v == parent:
            continue
        res += dfs(next_v, v)
    dp[v] = res
    return res

N = int(input())
graph = defaultdict(list)
edges = []

for _ in range(N - 1):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    graph[A].append(B)
    graph[B].append(A)
    edges.append((A, B))

dp = [0] * N
dfs(0, -1)

mulsum = 0
for u, v in edges:
    if dp[u] > dp[v]:
        u, v = v, u
    a = dp[u]
    b = N - a
    mul = ((modpow(2, a) - 1) * (modpow(2, b) - 1)) % MOD
    mulsum += mul
    mulsum %= MOD

cases = modpow(2, N)
PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD
BN = (N * modpow(2, N - 1)) % MOD
WN = (PN - BN + MOD) % MOD
ans = (WN * modpow(cases, MOD - 2)) % MOD

print(ans)  # End of Code
