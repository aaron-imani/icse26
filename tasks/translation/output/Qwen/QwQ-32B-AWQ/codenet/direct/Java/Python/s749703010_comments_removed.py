import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    a = [[0] * n for _ in range(2)]
    idx_data = 1
    for i in range(n):
        a[0][i] = data[idx_data]
        idx_data += 1
    for i in range(n):
        a[1][i] = data[idx_data]
        idx_data += 1
    memo = [[[ -1 for _ in range(1 << n)] for _ in range(n + 1)] for _ in range(2)]
    
    def dp(flip, idx, mask):
        nonlocal n, a, memo
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
                if (idx == n) or (a[flip][idx] <= a[(nf + (ff % 2)) % 2][i]):
                    new_flip = (nf + (ff % 2)) % 2
                    new_mask = mask | (1 << i)
                    res = ff + dp(new_flip, i, new_mask)
                    if res < ans:
                        ans = res
                ff += 1
            else:
                x -= 1
        memo[flip][idx][mask] = ans
        return ans
    
    ans = dp(0, n, 0)
    print(-1 if ans == float('inf') else ans)

if __name__ == "__main__":
    main()
# End of Code
