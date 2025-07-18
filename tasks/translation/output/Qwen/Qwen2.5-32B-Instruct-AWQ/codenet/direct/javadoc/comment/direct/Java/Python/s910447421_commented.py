class FastScanner:
    def __init__(self):
        self.buffer = []
        self.ptr = 0

    def next(self):
        if self.ptr >= len(self.buffer):
            self.buffer = input().split()
            self.ptr = 0
        res = self.buffer[self.ptr]
        self.ptr += 1
        return res

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())


class OutPut:
    def __init__(self):
        self.w = None

    def pln(self, x):
        print(x)

    def p(self, x):
        print(x, end='')


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


ans = 100
balls = []
N = 0
taken = []

I = FastScanner()
O = OutPut()

N = I.next_int()
ans = N
balls = [[0] * 2 for _ in range(N)]
for i in range(N):
    balls[i][0] = I.next_int()
    balls[i][1] = I.next_int()

balls.sort(key=lambda x: x[0])
solve()

for i in range(N):
    x = balls[i][0]
    y = balls[i][1]
    balls[i][0] = y
    balls[i][1] = x

balls.sort(key=lambda x: x[0])
solve()

O.pln(ans)  # End of Code
