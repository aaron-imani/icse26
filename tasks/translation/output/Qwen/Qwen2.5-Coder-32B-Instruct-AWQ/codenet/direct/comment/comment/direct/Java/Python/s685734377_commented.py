import sys

class TaskB:
    def solve(self, testNumber, in_reader, out):
        n = int(in_reader.readline())
        a = [in_reader.readline().strip() for _ in range(n)]
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
        out.write(f"{ans}\n")

class FastScanner:
    def __init__(self, file):
        self.file = file
        self.buffer = []
        self.token = None

    def readline(self):
        if len(self.buffer) == 0:
            self.buffer = self.file.readline().split()
        return self.buffer.pop(0)

def main():
    in_reader = FastScanner(sys.stdin)
    out = sys.stdout
    solver = TaskB()
    solver.solve(1, in_reader, out)

if __name__ == "__main__":
    main()
# End of Code
