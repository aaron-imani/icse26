class Pair:
    def __init__(self, l, r):
        self.l = l
        self.r = r

    def __str__(self):
        return f"{self.l} {self.r}"

def dp(flip, idx, mask):
    global memo, a, n
    if mask == (1 << n) - 1:
        return 0
    if memo[flip][idx][mask] != -1:
        return memo[flip][idx][mask]
    x = bin(mask).count('1')
    ff = 0
    ans = float('inf')
    for i in range(n):
        if not (mask & (1 << i)):
            nf = x % 2
            if idx == n or a[flip][idx] <= a[(nf + (ff % 2)) % 2][i]:
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, mask | (1 << i)))
            ff += 1
        else:
            x -= 1
    memo[flip][idx][mask] = ans
    return ans

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    n = int(data[idx])
    idx += 1
    a = [[], []]
    for i in range(n):
        a[0].append(int(data[idx]))
        idx += 1
    for i in range(n):
        a[1].append(int(data[idx]))
        idx += 1
    
    memo = [[[ -1 for _ in range(1 << n)] for _ in range(n + 1)] for _ in range(2)]
    
    ans = dp(0, n, 0)
    print(-1 if ans >= float('inf') else ans)

# End of Code
