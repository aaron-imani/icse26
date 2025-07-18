import sys
import math
from collections import deque, defaultdict, Counter, OrderedDict

class Solver:
    def __init__(self, input, output):
        self.input = input
        self.output = output

    def solve(self):
        H = self.ni()
        W = self.ni()
        C = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            line = self.ns()
            for j in range(W):
                C[i + 1][j + 1] = line[j]
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
        self.output.write(f"{s}\n")

    def prr(self, s):
        self.output.write(s)

    def ni(self):
        return int(self.ns())

    def nl(self):
        return int(self.ns())

    def nd(self):
        return float(self.ns())

    def ns(self):
        return self.input.readline().strip()

    def ndi(self, n):
        return [self.ni() for _ in range(n)]

    def ndl(self, n):
        return [self.nl() for _ in range(n)]

    def ndd(self, n):
        return [self.nd() for _ in range(n)]

    def nds(self, n):
        return [self.ns() for _ in range(n)]

    def nddi(self, n, m):
        return [[self.ni() for _ in range(m)] for _ in range(n)]

    def nddl(self, n, m):
        return [[self.nl() for _ in range(m)] for _ in range(n)]

def main():
    input = sys.stdin
    output = sys.stdout
    solver = Solver(input, output)
    solver.solve()

if __name__ == "__main__":
    main()
# End of Code
