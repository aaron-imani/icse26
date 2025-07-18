import sys

class FastScanner:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.ptr = 0

    def next(self):
        if self.ptr >= len(self.buffer):
            self.buffer = self.stream.readline().split()
            self.ptr = 0
        if self.buffer:
            self.ptr += 1
            return self.buffer[self.ptr - 1]
        return None

    def nextInt(self):
        return int(self.next())

def main():
    mod = 10**9 + 7
    scanner = FastScanner(sys.stdin)
    N = scanner.nextInt()
    to = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        A = scanner.nextInt() - 1
        B = scanner.nextInt() - 1
        to[A].append(B)
        to[B].append(A)
        edges.append([B, A])
    dp = [0] * N

    stack = []
    stack.append((0, -1, False))
    while stack:
        v, parent, visited = stack.pop()
        if not visited:
            stack.append((v, parent, True))
            for next_node in to[v]:
                if next_node != parent:
                    stack.append((next_node, v, False))
        else:
            dp[v] = 1
            for next_node in to[v]:
                if next_node != parent:
                    dp[v] += dp[next_node]

    mulsum = 0
    for e in edges:
        c1, c2 = e[0], e[1]
        child = c1 if dp[c1] < dp[c2] else c2
        a = dp[child]
        b = N - a
        term = (pow(2, a, mod) - 1) * (pow(2, b, mod) - 1) % mod
        mulsum = (mulsum + term) % mod

    cases = pow(2, N, mod)
    PN = (mulsum + (cases - 1 + mod) % mod) % mod
    BN = N * pow(2, N-1, mod) % mod
    WN = (PN - BN) % mod
    inv_cases = pow(cases, mod-2, mod)
    ans = WN * inv_cases % mod
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
