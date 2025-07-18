import sys

class Solver:
    def __init__(self, in_stream, out_stream):
        self.in_stream = in_stream
        self.out_stream = out_stream

    def solve(self):
        H = int(self.in_stream.readline())
        W = int(self.in_stream.readline())
        C = [[' ' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            line = self.in_stream.readline().strip()
            for j in range(W):
                C[i + 1][j + 1] = line[j]
        if H == 1 and W == 1:
            self.out_stream.write("No\n")
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i - 1][j] != '#' and C[i + 1][j] != '#' and C[i][j - 1] != '#' and C[i][j + 1] != '#':
                    self.out_stream.write("No\n")
                    return
        self.out_stream.write("Yes\n")

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = Solver(in_stream, out_stream)
    solver.solve()

if __name__ == "__main__":
    main()
# End of Code
