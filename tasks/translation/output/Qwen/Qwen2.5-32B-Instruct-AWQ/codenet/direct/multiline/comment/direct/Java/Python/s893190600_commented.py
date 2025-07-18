import sys
from collections import defaultdict, deque

class Solver:
    def __init__(self, input_stream, output_stream):
        self.input = input_stream
        self.output = output_stream

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
        self.output.write(str(s) + "\n")

    def prr(self, s):
        self.output.write(str(s))

    def ni(self):
        return int(self.input.readline())

    def nl(self):
        return int(self.input.readline())

    def nd(self):
        return float(self.input.readline())

    def ns(self):
        return self.input.readline().strip()

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = Solver(input_stream, output_stream)
    solver.solve()

if __name__ == "__main__":
    main()

# End of Code
