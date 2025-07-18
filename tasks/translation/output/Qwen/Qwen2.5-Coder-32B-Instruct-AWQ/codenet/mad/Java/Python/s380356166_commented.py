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

    def nextInt(self):
        return int(self.in_stream.readline())

    def nextLong(self):
        return int(self.in_stream.readline())

    def nextString(self):
        return self.in_stream.readline().strip()

def main():
    in_stream = MyInput(sys.stdin)
    out = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out)

if __name__ == "__main__":
    main()
# End of Code
