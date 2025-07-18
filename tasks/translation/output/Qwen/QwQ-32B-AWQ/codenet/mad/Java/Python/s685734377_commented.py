import sys

class FastScanner:
    def __init__(self, stdin):
        self.stdin = stdin
        self.buffer = []
        self.ptr = 0

    def next(self):
        if self.ptr >= len(self.buffer):
            self.buffer = self.stdin.readline().split()
            self.ptr = 0
        res = self.buffer[self.ptr]
        self.ptr += 1
        return res

    def nextInt(self):
        return int(self.next())

def main():
    in_ = FastScanner(sys.stdin)
    n = in_.nextInt()
    a = []
    for _ in range(n):
        line = in_.next()
        a.append(list(line))
    
    P = 37
    powP = [1] * (n + 1)
    for i in range(1, n + 1):
        powP[i] = powP[i - 1] * P
    
    hashRow = [[0] * n for _ in range(n)]
    hashCol = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            c = a[i][j]
            val = ord(c)
            for k in range(n):
                exponent = (j - k + n) % n
                term = val * powP[exponent]
                hashRow[i][k] += term
                exponent_col = (i - k + n) % n
                term_col = val * powP[exponent_col]
                hashCol[j][k] += term_col
    
    ans = 0
    for A in range(n):
        for B in range(n):
            ok = True
            for i in range(n):
                row = (i + A) % n
                col = (i + B) % n
                val_row = hashRow[row][B]
                val_col = hashCol[col][A]
                if val_row != val_col:
                    ok = False
                    break
            if ok:
                ans += 1
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
