import sys
from collections import deque, defaultdict

class Solver:
    def __init__(self, input, output):
        self.input = input
        self.output = output

    def solve(self):
        H = self.ni()
        W = self.ni()
        C = [['.'] * (W + 2) for _ in range(H + 2)]
        for i in range(H):
            line = self.ns()
            for j in range(W):
                C[i + 1][j + 1] = line[j]
        if H == 1 and W == 1:
            self.prn("No")
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i - 1][j] != '#' and C[i + 1][j] != '#' \
                        and C[i][j - 1] != '#' and C[i][j + 1] != '#':
                    self.prn("No")
                    return
        self.prn("Yes")

    def prn(self, s):
        self.output.write(f"{s}\n")

    def ni(self):
        return int(self.ns())

    def ns(self):
        return self.input.readline().strip()

    def nd(self):
        return float(self.ns())

    def ndl(self):
        return list(map(int, self.ns().split()))

    def ndd(self):
        return list(map(float, self.ns().split()))

    def nds(self):
        return self.ns().split()

    def nddi(self, n):
        return [self.ndl() for _ in range(n)]

    def nddl(self, n):
        return [self.nddl() for _ in range(n)]


def main():
    input = sys.stdin
    output = sys.stdout
    solver = Solver(input, output)
    solver.solve()


if __name__ == "__main__":
    main()
# End of Code
