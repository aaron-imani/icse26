class Solver:
    def solve(self, testNumber, in_stream, out_stream):
        ans = 0
        K = in_stream.nextInt()
        S = in_stream.nextInt()
        wk = 0
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if wk >= 0 and wk <= K:
                    ans += 1
        out_stream.write(f"{ans}\n")

class MyInput:
    def __init__(self, is_):
        self.in_ = is_
        self.buffer = []
        self.pos = 0

    def read(self):
        if self.pos >= len(self.buffer):
            self.buffer = self.in_.readline().strip().split(' ')
            self.pos = 0
        result = self.buffer[self.pos]
        self.pos += 1
        return result

    def nextInt(self):
        return int(self.read())

    def nextLong(self):
        return int(self.read())

    def nextString(self):
        return self.read()

    def nextDChar(self):
        return list(self.read())

def main():
    in_stream = MyInput(sys.stdin)
    out_stream = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    import sys
    main()  # End of Code
