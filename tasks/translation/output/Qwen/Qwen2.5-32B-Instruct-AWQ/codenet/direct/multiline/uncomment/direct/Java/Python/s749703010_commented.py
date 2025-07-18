class Pair:
    def __init__(self, a, b):
        self.l = a
        self.r = b

    def __str__(self):
        return f"{self.l} {self.r}"

def dp(fliped, idx, msk):
    global memo, a, n
    if msk == (1 << n) - 1:
        return 0
    if memo[fliped][idx][msk] != -1:
        return memo[fliped][idx][msk]
    x = bin(msk).count('1')
    ff = 0
    ans = float('inf')
    for i in range(n):
        if not (msk & (1 << i)):
            nf = x % 2
            if idx == n or a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]:
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)))
            ff += 1
        else:
            x -= 1
    memo[fliped][idx][msk] = ans
    return ans

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    it = iter(data)
    n = int(next(it))
    a = [[], []]
    for _ in range(n):
        a[0].append(int(next(it)))
    for _ in range(n):
        a[1].append(int(next(it)))

    memo = [[[ -1 for _ in range(1 << n)] for _ in range(n + 1)] for _ in range(2)]
    ans = dp(0, n, 0)
    print(-1 if ans >= 1e8 else ans)

# End of Code
