import sys

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_ = FastScanner(input_stream)
        out = output_stream
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
                    ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A]
                ans += 1 if ok else 0
        out.write(f"{ans}\n")

class FastScanner:
    def __init__(self, in_):
        import sys
        self.br = sys.stdin
        self.st = None

    def nextInt(self):
        return int(self.next())

    def next(self):
        while self.st is None or not self.st.hasMoreTokens():
            try:
                self.st = StringTokenizer(self.br.readline())
            except Exception:
                self.st = StringTokenizer('')
        return self.st.nextToken()

if __name__ == "__main__":
    Main.main()
# End of Code
