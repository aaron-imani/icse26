import sys
class Solver:
    def solve(self, testNumber, in_stream, out):
        ans = 0
        K = in_stream.nextInt()
        S = in_stream.nextInt()
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if 0 <= wk <= K:
                    ans += 1
        out.write(f"{ans}\n")
class MyInput:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.buffer = []
        self.buffer_pointer = 0
    def read(self):
        if self.buffer_pointer >= len(self.buffer):
            self.buffer = sys.stdin.readline().split()
            self.buffer_pointer = 0
        return self.buffer[self.buffer_pointer]
    def nextInt(self):
        return int(self.read())
    def nextLong(self):
        return int(self.read())
    def nextString(self):
        return self.read()
    def nextDChar(self):
        return list(self.read())
    def nextChar(self):
        return self.read()[0]
def main():
    in_stream = MyInput(sys.stdin)
    out = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out)
if __name__ == "__main__":
    main()
# End of Code
