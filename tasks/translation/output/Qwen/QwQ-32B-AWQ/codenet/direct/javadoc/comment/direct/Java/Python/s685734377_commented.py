class FastScanner:
    def __init__(self, stdin):
        self.stdin = stdin
        self.buffer = []
        self.ptr = 0

    def next(self):
        while self.ptr == len(self.buffer):
            line = self.stdin.readline()
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
    def solve(self, testNumber, in_, out):
        n = in_.nextInt()
        a = []
        for _ in range(n):
            s = in_.next()
            a.append(list(s))
        
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
                c = ord(a[i][j])
                for k in range(n):
                    exponent_row = (j - k + n) % n
                    hashRow[i][k] += c * powP[exponent_row]
                    exponent_col = (i - k + n) % n
                    hashCol[j][k] += c * powP[exponent_col]
        
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
        print(ans, file=out)

if __name__ == '__main__':
    import sys
    in_ = FastScanner(sys.stdin)
    out = sys.stdout
    solver = TaskB()
    solver.solve(1, in_, out)
    out.close()  # End of Code
