mod = 10**9 + 7

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    N = int(sys.stdin.readline())
    to = [[] for _ in range(N)]
    edges = [])
    for _ in range(N-1):
        A, B = map(int, sys.stdin.readline().split())
        A -= 1
        B -= 1
        to[A].append(B)
        to[B].append(A)
        edges.append([B, A])
    
    dp = [0] * N
    stack = [(0, -1, False)]
    while stack:
        v, parent, visited = stack.pop()
        if not visited:
            stack.append((v, parent, True))
            for neighbor in to[v]:
                if neighbor != parent:
                    stack.append((neighbor, v, False))
        else:
            dp[v] = 1
            for neighbor in to[v]:
                if neighbor != parent:
                    dp[v] += dp[neighbor]
    
    mulsum = 0
    for e in edges:
        c1, c2 = e[0], e[1]
        if dp[c1] > dp[c2]:
            child = c2
        else:
            child = c1
        a = dp[child]
        b = N - a
        term1 = (pow(2, a, mod) - 1) % mod
        term2 = (pow(2, b, mod) - 1) % mod
        mul = (term1 * term2) % mod
        mulsum = (mulsum + mul) % mod
    
    cases = pow(2, N, mod)
    PN = (mulsum + cases - 1) % mod
    BN = (N * pow(2, N-1, mod)) % mod
    WN = (PN - BN) % mod
    ans = WN * pow(cases, mod-2, mod) % mod
    print(ans)

if __name__ == "__main__":
    main()
#End of Code
