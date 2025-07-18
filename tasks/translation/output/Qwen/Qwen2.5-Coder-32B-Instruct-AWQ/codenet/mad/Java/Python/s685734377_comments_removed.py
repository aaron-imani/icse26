import sys

class FastScanner:
    def __init__(self, file):
        self.file = file
        self.line = None
        self.tokens = []

    def next(self):
        if not self.tokens:
            self.line = self.file.readline()
            if not self.line:
                return None
            self.tokens = self.line.split()
        return self.tokens.pop(0)

    def nextInt(self):
        return int(self.next())

def main():
    in_ = FastScanner(sys.stdin)
    out = sys.stdout
    solver = TaskB()
    solver.solve(1, in_, out)

class TaskB:
    def solve(self, testNumber, in_, out):
        n = in_.nextInt()
        a = [list(in_.next()) for _ in range(n)]
        P = 37
        Q = 47
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
        out.write(f"{ans}\n")

if __name__ == "__main__":
    main()
# End of Code
