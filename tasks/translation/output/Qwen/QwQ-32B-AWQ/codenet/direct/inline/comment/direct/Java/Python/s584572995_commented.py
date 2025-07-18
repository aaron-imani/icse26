MOD = 10**9 + 7

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    N = int(sys.stdin.readline())
    to = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        A, B = map(int, sys.stdin.readline().split())
        A -= 1
        B -= 1
        to[A].append(B)
        to[B].append(A)
        edges.append((B, A))  # edges[i][0] = B, edges[i][1] = A
    
    dp = [0] * N
    
    # Compute dp using iterative post-order traversal
    stack = [(0, -1, False)]
    while stack:
        v, parent, visited = stack.pop()
        if not visited:
            stack.append((v, parent, True))
            for neighbor in to[v]:
                if neighbor != parent:
                    stack.append((neighbor, v, False))
        else:
            total = 1
            for neighbor in to[v]:
                if neighbor != parent:
                    total += dp[neighbor]
            dp[v] = total
    
    mulsum = 0
    for e in edges:
        c1, c2 = e[0], e[1]
        if dp[c1] > dp[c2]:
            child = c2
        else:
            child = c1
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

if __name__ == "__main__":
    main()
# End of Code
