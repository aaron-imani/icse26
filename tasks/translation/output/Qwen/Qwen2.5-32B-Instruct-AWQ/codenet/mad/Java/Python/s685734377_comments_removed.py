import sys

class FastScanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.buffer = []
        self.ptr = 0

    def next(self):
        while self.ptr == len(self.buffer):
            try:
                self.buffer = self.in_stream.readline().split()
                self.ptr = 0
            except:
                pass
        result = self.buffer[self.ptr]
        self.ptr += 1
        return result

    def nextInt(self):
        return int(self.next())

class TaskB:
    def solve(self, testNumber, in_stream, out_stream):
        n = in_stream.nextInt()
        a = [list(in_stream.next()) for _ in range(n)]
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
                    if hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]:
                        ok = False
                        break
                ans += 1 if ok else 0
        out_stream.write(f'{ans}\n')

if __name__ == '__main__':
    in_stream = FastScanner(sys.stdin)
    out_stream = sys.stdout
    solver = TaskB()
    solver.solve(1, in_stream, out_stream)
# End of Code
