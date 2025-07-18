import sys

from collections import defaultdict, deque

class Solver:
    def __init__(self, input, output):
        self.input = input
        self.output = output

    def solve(self):
        H = self.nextInt()
        W = self.nextInt()
        C = [['' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            c = self.nextString()
            for j in range(W):
                C[i + 1][j + 1] = c[j]
        if H == 1 and W == 1:
            self.output.write("No\n")
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i - 1][j] != '#' and C[i + 1][j] != '#' and C[i][j - 1] != '#' and C[i][j + 1] != '#':
                    self.output.write("No\n")
                    return
        self.output.write("Yes\n")

    def nextInt(self):
        return int(self.input.readline())

    def nextString(self):
        return self.input.readline().strip()

def main():
    input = sys.stdin
    output = sys.stdout
    solver = Solver(input, output)
    solver.solve()
    output.close()

if __name__ == "__main__":
    main()
# End of Code
