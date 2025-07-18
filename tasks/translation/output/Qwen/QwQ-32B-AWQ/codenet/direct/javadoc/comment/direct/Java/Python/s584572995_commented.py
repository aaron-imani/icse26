# Required for recursion depth in case of large N
import sys
sys.setrecursionlimit(1 << 20)

MOD = 10**9 + 7

def main():
    N = int(sys.stdin.readline())
    to = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        A, B = map(int, sys.stdin.readline().split())
        A -= 1
        B -= 1
        to[A].append(B)
        to[B].append(A)
        edges.append((B, A))  # Store as (B, A) similar to Java's edges[i][0], edges[i][1]

    dp = [0] * N

    # Compute subtree sizes using post-order traversal
    def rec(v, parent):
        res = 1
        for next_node in to[v]:
            if next_node == parent:
                continue
            res += rec(next_node, v)
        dp[v] = res
        return res
    rec(0, -1)

    mulsum = 0
    for e in edges:
        c1, c2 = e[0], e[1]
        if dp[c1] < dp[c2]:
            child = c1
        else:
            child = c2
        a = dp[child]
        b = N - a
        term = (pow(2, a, MOD) - 1) * (pow(2, b, MOD) - 1) % MOD
        mulsum = (mulsum + term) % MOD

    cases = pow(2, N, MOD)
    PN = (mulsum + (cases - 1)) % MOD
    BN = (N * pow(2, N-1, MOD)) % MOD
    WN = (PN - BN) % MOD
    inv_cases = pow(cases, MOD-2, MOD)
    ans = WN * inv_cases % MOD
    print(ans)

if __name__ == '__main__':
    main()
# End of Code
