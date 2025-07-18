import sys
from collections import defaultdict, deque

class MyInput:
    def __init__(self, input_stream=sys.stdin):
        self.input_stream = input_stream
        self.buffer = []
        self.pos = 0

    def next_line(self):
        while not self.buffer:
            self.buffer = self.input_stream.readline().strip().split()
        return self.buffer.pop(0)

    def next_int(self):
        return int(self.next_line())

    def next_long(self):
        return int(self.next_line())

    def next_double(self):
        return float(self.next_line())

    def next_string(self):
        return self.next_line()

class Solver:
    def __init__(self, input_stream, output_stream):
        self.inp = MyInput(input_stream)
        self.out = output_stream

    def solve(self):
        H = self.inp.next_int()
        W = self.inp.next_int()
        C = [['' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            line = self.inp.next_string()
            for j in range(W):
                C[i + 1][j + 1] = line[j]

        if H == 1 and W == 1:
            self.out.write("No\n")
            return

        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i-1][j] != '#' and C[i+1][j] != '#' and C[i][j-1] != '#' and C[i][j+1] != '#':
                    self.out.write("No\n")
                    return

        self.out.write("Yes\n")

if __name__ == "__main__":
    solver = Solver(sys.stdin, sys.stdout)
    solver.solve()

# End of Code
