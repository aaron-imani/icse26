mod = 10**9 + 7

def modpow(x, y):
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y - 1) % mod
    tmp = modpow(x, y // 2)
    return tmp * tmp % mod

def rec(v, parent, to, dp):
    res = 1
    for next in to[v]:
        if next == parent:
            continue
        res += rec(next, v, to, dp)
    dp[v] = res
    return res

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    i = 0
    N = int(data[i])
    i += 1
    to = [[] for _ in range(N)]
    edges = []
    for _ in range(N - 1):
        A = int(data[i]) - 1
        i += 1
        B = int(data[i]) - 1
        i += 1
        to[A].append(B)
        to[B].append(A)
        edges.append((B, A))
    dp = [0] * N
    rec(0, -1, to, dp)
    mulsum = 0
    for e in edges:
        candidate1, candidate2 = e
        child = candidate1 if dp[candidate1] > dp[candidate2] else candidate2
        a = dp[child]
        b = N - a
        mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
        mulsum += mul
        mulsum %= mod
    cases = modpow(2, N)
    PN = (mulsum + (cases - 1 + mod) % mod) % mod
    BN = N * modpow(2, N - 1) % mod
    WN = (PN - BN + mod) % mod
    ans = WN * modpow(cases, mod - 2) % mod
    print(ans)

main()  # End of Code
