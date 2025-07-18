import sys

class FastScanner:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.ptr = 0

    def next(self):
        while self.ptr >= len(self.buffer):
            line = self.stream.readline()
            if not line:
                return None
            self.buffer = line.split()
            self.ptr = 0
        res = self.buffer[self.ptr]
        self.ptr += 1
        return res

    def nextInt(self):
        return int(self.next())

class TaskB:
    def solve(self, testNumber, in_stream, out_stream):
        in_scanner = FastScanner(in_stream)
        n = in_scanner.nextInt()
        a = []
        for _ in range(n):
            line = in_scanner.next()
            a.append(list(line))
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
                    c = a[i][j]
                    val = ord(c)
                    exp_p_row = (j - k) % n
                    term_row = val * powP[exp_p_row]
                    hashRow[i][k] += term_row

                    exp_p_col = (i - k) % n
                    term_col = val * powP[exp_p_col]
                    hashCol[j][k] += term_col

        ans = 0
        for A in range(n):
            for B in range(n):
                ok = True
                for i in range(n):
                    ra = (i + A) % n
                    val_r = hashRow[ra][B]
                    rc = (i + B) % n
                    val_c = hashCol[rc][A]
                    if val_r != val_c:
                        ok = False
                        break
                if ok:
                    ans += 1
        out_stream.write(f"{ans}\n")

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = TaskB()
    solver.solve(1, in_stream, out_stream)
    out_stream.close()

if __name__ == "__main__":
    main()
# End of Code
