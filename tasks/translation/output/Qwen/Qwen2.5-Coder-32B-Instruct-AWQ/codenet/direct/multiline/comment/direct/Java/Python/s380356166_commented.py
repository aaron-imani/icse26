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

def main():
    in_stream = sys.stdin
    out = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out)

if __name__ == "__main__":
    main()
# End of Code
