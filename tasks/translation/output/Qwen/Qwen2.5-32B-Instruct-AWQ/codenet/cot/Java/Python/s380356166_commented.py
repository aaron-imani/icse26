import sys

class Solver:
    def solve(self, testNumber, in_stream, out_stream):
        ans = 0
        K = int(next(in_stream))
        S = int(next(in_stream))
        wk = 0
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if 0 <= wk <= K:
                    ans += 1
        out_stream.write(str(ans) + '\n')

class MyInput:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def nextInt(self):
        return int(next(self.input_stream))

def main():
    in_stream = iter(sys.stdin.read().split())
    out_stream = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    main()
# End of Code
