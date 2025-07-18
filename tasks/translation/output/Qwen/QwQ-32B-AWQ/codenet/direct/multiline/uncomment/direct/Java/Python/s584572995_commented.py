import sys
MOD = 10**9 + 7

def main():
    sys.setrecursionlimit(1 << 20)
    N = int(sys.stdin.readline())
    to = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        A, B = map(int, sys.stdin.readline().split())
        A -= 1
        B -= 1
        to[A].append(B)
        to[B].append(A)
        edges.append([B, A])
    
    dp = [0] * N

    def dfs(v, parent):
        size = 1
        for u in to[v]:
            if u != parent:
                size += dfs(u, v)
        dp[v] = size
        return size
    
    dfs(0, -1)
    
    mulsum = 0
    for e in edges:
        c1, c2 = e[0], e[1]
        if dp[c1] < dp[c2]:
            child = c1
        else:
            child = c2
        a = dp[child]
        b = N - a
        term1 = (pow(2, a, MOD) - 1) % MOD
        term2 = (pow(2, b, MOD) - 1) % MOD
        mul = (term1 * term2) % MOD
        mulsum = (mulsum + mul) % MOD
    
    cases = pow(2, N, MOD)
    PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD
    BN = N * pow(2, N-1, MOD) % MOD
    WN = (PN - BN) % MOD
    inv_cases = pow(cases, MOD-2, MOD)
    ans = WN * inv_cases % MOD
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
