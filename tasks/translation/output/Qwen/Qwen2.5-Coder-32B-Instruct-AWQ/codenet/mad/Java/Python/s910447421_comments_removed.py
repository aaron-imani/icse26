import sys

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next(self):
        result = self.buffer[self.index]
        self.index += 1
        return result

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

class OutPut:
    def pln(self, x):
        print(x)

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
I = FastScanner()
O = OutPut()
N = I.nextInt()
ans = N
balls = [[I.nextInt(), I.nextInt()] for _ in range(N)]
balls.sort(key=lambda a: a[0])
solve()
for i in range(N):
    balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
balls.sort(key=lambda a: a[0])
solve()
O.pln(ans)
# End of Code
