import sys

class FastScanner:
    def __init__(self):
        self.reader = sys.stdin
        self.buffer = ""
    
    def next(self):
        while not self.buffer:
            try:
                self.buffer = self.reader.readline().strip()
            except:
                pass
        token = self.buffer
        self.buffer = ''
        return token
    
    def next_int(self):
        return int(self.next())
    
    def next_long(self):
        return int(self.next())
    
    def next_double(self):
        return float(self.next())

class Output:
    def __init__(self):
        self.writer = sys.stdout
    
    def pln(self, x):
        print(x, file=self.writer)
        self.writer.flush()
    
    def p(self, x):
        print(x, end='', file=self.writer)
        self.writer.flush()

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
O = Output()
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
