import sys

def main():
    mod = 10**9 + 7
    N = int(sys.stdin.readline())
    to = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        A, B = map(int, sys.stdin.readline().split())
        A -= 1
        B -= 1
        to[A].append(B)
        to[B].append(A)
        edges.append((B, A))
    
    dp = [0] * N

    def rec(v, parent):
        res = 1
        for u in to[v]:
            if u == parent:
                continue
            res += rec(u, v)
        dp[v] = res
        return res
    
    rec(0, -1)

    mulsum = 0
    for e in edges:
        candidate1, candidate2 = e[0], e[1]
        a_candidate = candidate1
        b_candidate = candidate2
        if dp[candidate1] > dp[candidate2]:
            a_candidate = candidate2
            b_candidate = candidate1
        a = dp[a_candidate]
        b = N - a
        term1 = (pow(2, a, mod) - 1) % mod
        term2 = (pow(2, b, mod) - 1) % mod
        mul = (term1 * term2) % mod
        mulsum = (mulsum + mul) % mod

    cases = pow(2, N, mod)
    PN = (mulsum + (cases - 1)) % mod
    BN = (N * pow(2, N-1, mod)) % mod
    WN = (PN - BN + mod) % mod
    ans = WN * pow(cases, mod-2, mod) % mod
    print(ans % mod)

if __name__ == "__main__":
    main()
# End of Code
