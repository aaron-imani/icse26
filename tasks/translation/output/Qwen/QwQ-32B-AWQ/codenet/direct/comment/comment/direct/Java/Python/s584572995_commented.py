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
        edges.append([B, A])  # Store as edges[i][0] = B, edges[i][1] = A
    
    # Calculate dp using iterative post-order traversal
    dp = [1] * N
    stack = [(0, -1, False)]
    while stack:
        v, parent, visited = stack.pop()
        if not visited:
            stack.append((v, parent, True))
            for next_node in to[v]:
                if next_node != parent:
                    stack.append((next_node, v, False))
        else:
            for next_node in to[v]:
                if next_node != parent:
                    dp[v] += dp[next_node]
    
    mulsum = 0
    for e in edges:
        c1, c2 = e[0], e[1]
        if dp[c1] < dp[c2]:
            child = c1
        else:
            child = c2
        a = dp[child]
        b = N - a
        term = (pow(2, a, mod) - 1) * (pow(2, b, mod) - 1) % mod
        mulsum = (mulsum + term) % mod
    
    cases = pow(2, N, mod)
    PN = (mulsum + (cases - 1)) % mod
    BN = N * pow(2, N-1, mod) % mod
    WN = (PN - BN) % mod
    inv_cases = pow(cases, mod-2, mod)
    ans = WN * inv_cases % mod
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
