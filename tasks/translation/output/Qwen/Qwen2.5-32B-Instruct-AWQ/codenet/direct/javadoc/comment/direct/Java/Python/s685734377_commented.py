class TaskB:
    def solve(self, test_number, in_stream, out_stream):
        n = int(in_stream.readline())
        a = [list(in_stream.readline().strip()) for _ in range(n)]
        P, Q = 37, 47
        powP = [1] * (n + 1)
        powQ = [1] * (n + 1)
        for i in range(1, n + 1):
            powP[i] = powP[i - 1] * P
            powQ[i] = powQ[i - 1] * Q

        hash_row = [[0 for _ in range(n)] for _ in range(n)]
        hash_col = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    hash_row[i][k] += ord(a[i][j]) * powP[(j - k + n) % n]
                    hash_col[j][k] += ord(a[i][j]) * powP[(i - k + n) % n]

        ans = 0
        for A in range(n):
            for B in range(n):
                ok = True
                for i in range(n):
                    if hash_row[(i + A) % n][B] != hash_col[(i + B) % n][A]:
                        ok = False
                        break
                if ok:
                    ans += 1
        out_stream.write(f"{ans}\n")

class FastScanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.st = []

    def next_int(self):
        return int(self.next())

    def next(self):
        while not self.st:
            line = self.in_stream.readline()
            self.st = line.strip().split()
        return self.st.pop(0)

if __name__ == "__main__":
    import sys
    in_stream = sys.stdin
    out_stream = sys.stdout
    scanner = FastScanner(in_stream)
    solver = TaskB()
    solver.solve(1, scanner, out_stream)
# End of Code
