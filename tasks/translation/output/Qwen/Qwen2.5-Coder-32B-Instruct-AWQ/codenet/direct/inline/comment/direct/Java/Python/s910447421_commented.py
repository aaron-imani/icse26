import sys
import math

class FastScanner:
    def __init__(self):
        self.br = sys.stdin
        self.st = []

    def next(self):
        while not self.st:
            try:
                self.st = self.br.readline().split()
            except:
                return None
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

class OutPut:
    def __init__(self):
        self.w = sys.stdout

    def pln(self, x):
        self.w.write(str(x) + '\n')
        self.w.flush()

    def p(self, x):
        self.w.write(str(x))
        self.w.flush()

def min(a, b):
    return a if a < b else b

def solve():
    global ans
    for add in range(1, N):
        taken = [False] * N
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        ans = min(ans, check(p, q))

def check(p, q):
    ret = 0
    while True:
        added = False
        start = 0
        x = -1
        y = -1
        for i in range(N):
            if not taken[i]:
                added = True
                ret += 1
                start = i
                taken[i] = True
                x = balls[i][0] + p
                y = balls[i][1] + q
                break
        if not added:
            break
        for i in range(start + 1, N):
            if balls[i][0] == x and balls[i][1] == y:
                taken[i] = True
                x += p
                y += q
    return ret

ans = 100
N = 0
balls = []
taken = []

if __name__ == "__main__":
    I = FastScanner()
    O = OutPut()
    N = I.nextInt()
    ans = N
    balls = [[I.nextInt(), I.nextInt()] for _ in range(N)]
    balls.sort(key=lambda a: a[0])
    solve()
    balls = [[y, x] for x, y in balls]
    balls.sort(key=lambda a: a[0])
    solve()
    O.pln(ans)
# End of Code
