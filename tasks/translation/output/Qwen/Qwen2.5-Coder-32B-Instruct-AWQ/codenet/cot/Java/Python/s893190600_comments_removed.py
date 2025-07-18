import sys

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_ = MyInput(input_stream)
        out = output_stream

        solver = Solver(in_, out)
        solver.solve()

        out.close()

class Solver:
    def __init__(self, in_, out):
        self.in_ = in_
        self.out = out

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
        self.out.write(f"{s}\n")

    def prr(self, s):
        self.out.write(s)

    def ni(self):
        return self.in_.nextInt()

    def nl(self):
        return self.in_.nextLong()

    def nd(self):
        return self.in_.nextDouble()

    def ns(self):
        return self.in_.nextString()

class MyInput:
    def __init__(self, is_):
        self.in_ = is_
        self.buffer = []
        self.buffer_pointer = 0

    def read(self):
        if not self.buffer:
            self.buffer = self.in_.readline().split()
        return self.buffer.pop(0)

    def nextInt(self):
        return int(self.read())

    def nextLong(self):
        return int(self.read())

    def nextDouble(self):
        return float(self.read())

    def nextString(self):
        return self.read()

# End of Code
