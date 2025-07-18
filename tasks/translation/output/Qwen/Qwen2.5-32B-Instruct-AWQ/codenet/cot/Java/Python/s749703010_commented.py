class Pair:
    def __init__(self, l, r):
        self.l = l
        self.r = r

    def __str__(self):
        return f"{self.l} {self.r}"

class Scanner:
    def __init__(self, stream):
        self.stream = stream

    def next(self):
        return next(self.stream).strip()

    def nextInt(self):
        return int(self.next())

    def nextLine(self):
        return next(self.stream).strip()

def dp(flip, idx, msk):
    if msk == (1 << n) - 1:
        return 0
    if memo[flip][idx][msk] != -1:
        return memo[flip][idx][msk]
    x = bin(msk).count('1')
    ff = 0
    ans = float('inf')
    for i in range(n):
        if (msk & (1 << i)) == 0:
            nf = x % 2
            if idx == n or a[flip][idx] <= a[(nf + (ff % 2)) % 2][i]:
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)))
            ff += 1
        else:
            x -= 1
    memo[flip][idx][msk] = ans
    return ans

if __name__ == "__main__":
    sc = Scanner(iter(sys.stdin.readline, ''))
    n = sc.nextInt()
    a = [[0] * n for _ in range(2)]
    for i in range(n):
        a[0][i] = sc.nextInt()
    for i in range(n):
        a[1][i] = sc.nextInt()
    memo = [[[0] * (1 << n) for _ in range(n + 1)] for _ in range(2)]
    for z in memo:
        for x in z:
            x[:] = [-1] * len(x)
    ans = dp(0, n, 0)
    print(-1 if ans >= 1e8 else ans)
# End of Code
