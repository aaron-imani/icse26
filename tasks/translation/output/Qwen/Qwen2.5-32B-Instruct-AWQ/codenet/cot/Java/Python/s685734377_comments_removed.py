import sys

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    in_reader = FastScanner(in_stream)
    out_writer = out_stream
    solver = TaskB()
    solver.solve(1, in_reader, out_writer)
    out_writer.close()

def TaskB():
    class TaskB:
        def solve(self, testNumber, in_reader, out_writer):
            n = in_reader.nextInt()
            a = [list(in_reader.next()) for _ in range(n)]
            P, Q = 37, 47
            powP = [1] * (n + 1)
            powQ = [1] * (n + 1)
            for i in range(1, n + 1):
                powP[i] = powP[i - 1] * P
                powQ[i] = powQ[i - 1] * Q
            hashRow = [[0] * n for _ in range(n)]
            hashCol = [[0] * n for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    for k in range(n):
                        hashRow[i][k] += ord(a[i][j]) * powP[(j - k + n) % n]
                        hashCol[j][k] += ord(a[i][j]) * powP[(i - k + n) % n]
            ans = 0
            for A in range(n):
                for B in range(n):
                    ok = True
                    for i in range(n):
                        ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A]
                    ans += 1 if ok else 0
            out_writer.write(str(ans) + '\n')
    return TaskB()

def FastScanner(in_stream):
    class FastScanner:
        def __init__(self, in_stream):
            self.in_stream = in_stream
            self.st = None
            self.buffer = []
        def next(self):
            while not self.st or not self.st:
                line = self.in_stream.readline().strip()
                if not line:
                    continue
                self.st = iter(line.split())
            return next(self.st)
        def nextInt(self):
            return int(self.next())
    return FastScanner(in_stream)

if __name__ == "__main__":
    main()
# End of Code
