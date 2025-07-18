class FastScanner:
    def __init__(self, stream):
        import sys
        if stream == sys.stdin:
            self.stream = sys.stdin
        else:
            self.stream = open(stream, 'r')
        self.tokens = []
        self.position =  kop = 0

    def next(self):
        while self.position >= len(self.tokens):
            line = self.stream.readline()
            if not line:
                return None
            self.tokens = line.split()
            self.position = 0
        res = self.tokens[self.position]
        self.position += 1
        return res

    def nextInt(self):
        return int(self.next())

class TaskB:
    def solve(self, testNumber, in_, out):
        n = in_.nextInt()
        a = []
        for _ in range(n):
            s = in_.next()
            a.append(s)
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
                    exponent = (j - k) % n
                    term = ord(a[i][j]) * powP[exponent]
                    hashRow[i][k] += term
                    exponent_col = (i - k) % n
                    term_col = ord(a[i][j]) * powP[exponent_col]
                    hashCol[j][k] += term_col
        ans = 0
        for A in range(n):
            for B in range(n):
                ok = True
                for i in range(n):
                    row_idx = (i + A) % n
                    col_idx = (i + B) % n
                    if hashRow[row_idx][B] != hashCol[col_idx][A]:
                        ok = False
                        break
                if ok:
                    ans += 1
        out.write(f"{ans}\n")
        out.flush()

def main():
    import sys
    in_stream = sys.stdin
    out = sys.stdout
    scanner = FastScanner(in_stream)
    solver = TaskB()
    solver.solve(1, scanner, out)
    out.close()

if __name__ == "__main__":
    main()  # End of Code
