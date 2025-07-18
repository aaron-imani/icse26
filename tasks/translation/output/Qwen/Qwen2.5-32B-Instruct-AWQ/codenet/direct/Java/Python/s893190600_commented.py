import sys
from collections import defaultdict, deque

class Solver:
    def __init__(self, in_stream, out_stream):
        self.in_stream = in_stream
        self.out_stream = out_stream

    def solve(self):
        H = self.ni()
        W = self.ni()
        C = [['' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            c = self.ns()
            for j in range(W):
                C[i + 1][j + 1] = c[j]
        if H == 1 and W == 1:
            self.prn("No")
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i - 1][j] != '#' and C[i + 1][j] != '#' and C[i][j - 1] != '#' and C[i][j + 1] != '#':
                    self.prn("No")
                    return
        self.prn("Yes")

    def prn(self, s):
        self.out_stream.write(str(s) + "\n")

    def prr(self, s):
        self.out_stream.write(str(s))

    def ni(self):
        return int(self.in_stream.readline())

    def nl(self):
        return int(self.in_stream.readline())

    def nd(self):
        return float(self.in_stream.readline())

    def ns(self):
        return self.in_stream.readline().strip()

    def ndi(self, n):
        return [self.ni() for _ in range(n)]

    def ndl(self, n):
        return [self.nl() for _ in range(n)]

    def ndd(self, n):
        return [self.nd() for _ in range(n)]

    def nds(self, n):
        return [self.ns() for _ in range(n)]

    def nddi(self, n, m):
        return [self.ndi(m) for _ in range(n)]

    def nddl(self, n, m):
        return [self.ndl(m) for _ in range(n)]

class MyInput:
    def __init__(self, in_stream):
        self.in_stream = in_stream

    def readline(self):
        return self.in_stream.readline()

    def nextChar(self):
        return self.in_stream.read(1)

    def nextString(self):
        return self.in_stream.readline().strip()

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = Solver(in_stream, out_stream)
    solver.solve()

if __name__ == "__main__":
    main()

# End of Code
