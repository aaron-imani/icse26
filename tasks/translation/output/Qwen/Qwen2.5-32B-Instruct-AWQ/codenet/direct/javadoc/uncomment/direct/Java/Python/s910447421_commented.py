import sys

class FastScanner:
    def __init__(self):
        self.br = sys.stdin
        self.st = ""
    
    def next(self):
        while not self.st:
            try:
                self.st = self.br.readline().split()
            except:
                pass
        return self.st.pop(0)
    
    def next_int(self):
        return int(self.next())
    
    def next_long(self):
        return int(self.next())
    
    def next_double(self):
        return float(self.next())

class OutPut:
    def __init__(self):
        self.w = sys.stdout
    
    def pln(self, x):
        print(x, file=self.w)
        self.w.flush()
    
    def p(self, x):
        print(x, end='', file=self.w)
        self.w.flush()

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

def min(a, b):
    return a if a < b else b

I = FastScanner()
O = OutPut()
N = I.next_int()
ans = N
balls = [[I.next_int(), I.next_int()] for _ in range(N)]
balls.sort(key=lambda x: x[0])
solve()
for i in range(N):
    balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
balls.sort(key=lambda x: x[0])
solve()
O.pln(ans)  # End of Code
