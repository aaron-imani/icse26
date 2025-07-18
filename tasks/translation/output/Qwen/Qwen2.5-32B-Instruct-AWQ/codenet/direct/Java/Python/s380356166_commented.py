import sys

class Solver:
    def solve(self, testNumber, in_stream, out_stream):
        ans = 0
        K = in_stream.nextInt()
        S = in_stream.nextInt()
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if 0 <= wk <= K:
                    ans += 1
        out_stream.write(f"{ans}\n")

class MyInput:
    def __init__(self, input_stream):
        self.in_stream = input_stream
        self.buffer = []
        self.pos = 0

    def nextInt(self):
        return int(self.nextString())

    def nextLong(self):
        return int(self.nextString())

    def nextString(self):
        while not self.buffer:
            self.buffer = self.in_stream.readline().split()
        return self.buffer.pop(0)

class MyOutput:
    def __init__(self, output_stream):
        self.out_stream = output_stream

    def write(self, s):
        self.out_stream.write(s)

if __name__ == "__main__":
    in_stream = MyInput(sys.stdin)
    out_stream = MyOutput(sys.stdout)
    solver = Solver()
    solver.solve(1, in_stream, out_stream)
    out_stream.out_stream.close()  # End of Code
