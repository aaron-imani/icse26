import sys

class Solver:
    def solve(self, testNumber, in_stream, out):
        ans = 0
        K = int(in_stream.readline())
        S = int(in_stream.readline())
        for x in range(K + 1):
            for y in range(K + 1):
                z = S - x - y
                if 0 <= z <= K:
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

    def nextDChar(self):
        return list(self.in_stream.readline().strip())

    def nextChar(self):
        return self.in_stream.read(1)

def main():
    in_stream = sys.stdin
    out = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out)

if __name__ == "__main__":
    main()
# End of Code
