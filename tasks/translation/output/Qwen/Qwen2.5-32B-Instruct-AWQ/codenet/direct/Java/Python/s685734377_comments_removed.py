import sys

class TaskB:
    def solve(self, testNumber, in_stream, out_stream):
        n = int(in_stream.readline())
        a = [list(in_stream.readline().strip()) for _ in range(n)]
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
                if ok:
                    ans += 1
        
        out_stream.write(f"{ans}\n")

class FastScanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.st = None

    def next(self):
        while self.st is None or not self.st:
            line = self.in_stream.readline().strip()
            self.st = line.split()
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

if __name__ == "__main__":
    in_stream = sys.stdin
    out_stream = sys.stdout
    scanner = FastScanner(in_stream)
    solver = TaskB()
    solver.solve(1, scanner, out_stream)
# End of Code
