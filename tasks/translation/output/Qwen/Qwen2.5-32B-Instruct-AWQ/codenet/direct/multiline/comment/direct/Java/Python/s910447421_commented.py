class FastScanner:
    def __init__(self):
        self.buffer = []
        self.reader = sys.stdin

    def next(self):
        while not self.buffer:
            for token in self.reader.readline().split():
                self.buffer.append(token)
        return self.buffer.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())


class OutPut:
    def __init__(self):
        self.writer = sys.stdout

    def pln(self, x):
        print(x, file=self.writer)
        self.writer.flush()

    def p(self, x):
        print(x, end='', file=self.writer)
        self.writer.flush()


def gcd(a, b):
    if a == 0 or b == 0:
        return max(a, b)
    return gcd(min(a, b), max(a, b) % min(a, b))


def fast_exp(base, exp, mod):
    ans = 1
    while exp > 0:
        if exp % 2 == 1:
            ans *= base
        exp //= 2
        base *= base
        base %= mod
        ans %= mod
    return ans


def mod_inv(num, mod):
    return fast_exp(num, mod - 2, mod)


def pop(x):
    cnt = 0
    while x > 0:
        if x % 2 == 1:
            cnt += 1
        x //= 2
    return cnt


def min(a, b):
    return math.min(a, b)


def max(a, b):
    return math.max(a, b)


def abs(x):
    return math.abs(x)


def ceil(num, den):
    ans = num // den
    if num % den != 0:
        ans += 1
    return ans


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


if __name__ == "__main__":
    import sys
    import math

    ans = 100
    balls = []
    N = 0
    taken = []

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
